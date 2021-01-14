#include <cstdio>
#include <cstdlib>
#include <string>
#include <string_view>

#include "absl/strings/string_view.h"
#include "absl/container/flat_hash_map.h"

extern "C" void demo_function(std::size_t n, const char* args[]) {
  std::puts("I am a function. Here come my arguments.");

  absl::flat_hash_map<std::string, std::vector<std::string>> m;

  for (std::size_t i = 0; i != n; ++i) {
    absl::string_view arg = args[i];
    m[arg].emplace_back().assign(arg);
  }

  for (const auto& [k, v] : m) {
    std::printf("Argument '%*s' appears %zu times.\n",
                static_cast<int>(k.size()), k.data(), v.size());
  }
}
