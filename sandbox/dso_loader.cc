#include <dlfcn.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

extern "C" {
using FunPtr = void(std::size_t, const char*[]);
}  // extern "C"

int main(int argc, char* argv[]) {
  for (int i = 1; i != argc; ++i) {
    void* h = dlopen(argv[i], RTLD_NOW);

    if (h == nullptr) {
      std::fprintf(stderr, "Failed to open file '%s' with error '%s'.\n", argv[i], dlerror());
      continue;
    }

    std::fprintf(stdout, "Loaded DSO from file '%s', handle is %p.\n", argv[i], h);

    if (void* s = dlsym(h, "demo_function"); s == nullptr) {
      std::fprintf(stderr, "Failed to load symbol with error '%s'.\n", dlerror());
    } else {
      FunPtr* f;
      *reinterpret_cast<void**>(&f) = s;
      f(argc, const_cast<const char**>(argv));
    }

    if (dlclose(h) != 0) {
      std::fprintf(stderr, "Failed to close DSO '%s' with error '%s'.\n", argv[i], dlerror());
    }
  }
}
