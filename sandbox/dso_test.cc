#include <dlfcn.h>

#include "absl/strings/str_cat.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(DSOTest, LoadDSO) {
  const char* srcdir = std::getenv("TEST_SRCDIR");
  ASSERT_FALSE(srcdir == nullptr);

  void* h = dlopen(absl::StrCat(srcdir, "/tarpit/sandbox/dso_demo.so").c_str(), RTLD_NOW);
  ASSERT_FALSE(h == nullptr) << dlerror();

  void* s = dlsym(h, "demo_function");
  ASSERT_FALSE(s == nullptr) << dlerror();

  EXPECT_EQ(0, dlclose(h)) << dlerror();
}
