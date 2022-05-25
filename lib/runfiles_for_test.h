#ifndef H_LIB_RUNFILES_FOR_TEST
#define H_LIB_RUNFILES_FOR_TEST

#include <memory>

#include "absl/status/statusor.h"
#include "tools/cpp/runfiles/runfiles.h"

namespace tarpit {

absl::StatusOr<std::unique_ptr<::bazel::tools::cpp::runfiles::Runfiles>> CreateRunfilesForTest();

}  // namespace tarpit

#endif  // H_LIB_RUNFILES_FOR_TEST
