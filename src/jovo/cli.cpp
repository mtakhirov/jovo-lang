#include "jovo/cli.hpp"
#include "config.hpp"
#include <iostream>

using std::cout;
using std::endl;

void print_help() {
  cout << "jovo - A simple parser and lexer CLI" << endl;
  cout << "Commands:" << endl;
  cout << "  help       - Show this help message" << endl;
  cout << "  version    - Show version information" << endl;
}

void print_version() { cout << "jovo version v" << JOVO_VERSION << endl; }