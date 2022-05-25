#include "lib/runfiles_for_test.h"

#include <string>

#include "absl/memory/memory.h"
#include "absl/status/statusor.h"
#include "tools/cpp/runfiles/runfiles.h"

namespace tarpit {

absl::StatusOr<std::unique_ptr<bazel::tools::cpp::runfiles::Runfiles>> CreateRunfilesForTest() {
  if (std::string error; auto* runfiles = bazel::tools::cpp::runfiles::Runfiles::CreateForTest(&error)) {
    return absl::WrapUnique(runfiles);
  } else {
    return absl::InternalError(error);
  }
}

}  // namespace tarpit
