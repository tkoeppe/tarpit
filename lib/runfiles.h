#ifndef H_LIB_RUNFILES
#define H_LIB_RUNFILES

#include <memory>

#include "absl/status/statusor.h"
#include "tools/cpp/runfiles/runfiles.h"

namespace tarpit {

absl::StatusOr<std::unique_ptr<::bazel::tools::cpp::runfiles::Runfiles>> CreateRunfiles(const char* argv0);

}  // namespace tarpit

#endif  // H_LIB_RUNFILES
