#include <dlfcn.h>

#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "lib/runfiles_for_test.h"

namespace {

TEST(DSOTest, LoadDSO) {
  auto runfiles_or = tarpit::CreateRunfilesForTest();
  ASSERT_TRUE(runfiles_or.ok()) << runfiles_or.status();

  auto& runfiles = **runfiles_or;
  void* h = dlopen(runfiles.Rlocation("tarpit/sandbox/dso_demo.so").c_str(), RTLD_NOW);
  ASSERT_FALSE(h == nullptr) << dlerror();

  void* s = dlsym(h, "demo_function");
  ASSERT_FALSE(s == nullptr) << dlerror();

  EXPECT_EQ(0, dlclose(h)) << dlerror();
}

}  // namespace
