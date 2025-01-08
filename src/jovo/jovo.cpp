#include "jovo/jovo.hpp"
#include "config.hpp"
#include "jovo/cli.hpp"
#include <string>

using std::string;

int main(int argc, char **argv) {
  if (argc <= 1) {
    print_help();
    return 0;
  }

  string command = argv[1];

  if (command == "version") {
    print_version();
  }

  else {
    print_help();
  }

  return 0;
}