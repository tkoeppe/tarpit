#include <cstdio>

int main(int argc, char* argv[]) {
  std::fprintf(stdout, "We have %d arguments:\n", argc);
  for (int i = 0; i < argc; ++i) {
    std::fprintf(stdout, "  Argument #%d: '%s'\n", i, argv[i]);
  }
  std::fputs("Goodbye!\n", stdout);
}
