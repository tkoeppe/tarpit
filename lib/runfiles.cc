#include "lib/runfiles.h"

#include <string>

#include "absl/memory/memory.h"
#include "absl/status/statusor.h"
#include "tools/cpp/runfiles/runfiles.h"

namespace tarpit {

absl::StatusOr<std::unique_ptr<bazel::tools::cpp::runfiles::Runfiles>> CreateRunfiles(const char* argv0) {
  if (std::string error; auto* runfiles = bazel::tools::cpp::runfiles::Runfiles::Create(argv0, &error)) {
    return absl::WrapUnique(runfiles);
  } else {
    return absl::InternalError(error);
  }
}

}  // namespace tarpit
