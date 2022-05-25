#include <dlfcn.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "lib/runfiles.h"
#include "tools/cpp/runfiles/runfiles.h"

using ::bazel::tools::cpp::runfiles::Runfiles;

// Runfiles start with the workspace name.
const char kDemoDso[] = "tarpit/sandbox/dso_demo.so";

int main(int argc, char* argv[]) {
  auto runfiles_or = tarpit::CreateRunfiles(argv[0]);

  if (!runfiles_or.ok()) {
    std::cerr << "Failed to locate runfiles: '" << runfiles_or.status() << "'\n";
    std::abort();
  }

  auto& runfiles = **runfiles_or;

  std::cout << "Some runfiles:\n";
  for (const char* s : {"been/made-up", kDemoDso, ".", "tarpit/foo"}) {
    std::cout << "  Rlocation of '" << s << "': '" << runfiles.Rlocation(s) << "'.\n";
  }

  {
    const std::string dso_path = runfiles.Rlocation(kDemoDso);
    if (void* h = dlopen(dso_path.c_str(), RTLD_NOW); h != nullptr) {
      std::cout << "Successfully opened DSO from runfiles at '" << dso_path << "'.\n";
      dlclose(h);
      return EXIT_SUCCESS;
    } else {
      std::cerr << "Failed to open DSO at runfiles path '" << dso_path << "'!\n";
      return EXIT_FAILURE;
    }
  }
}
