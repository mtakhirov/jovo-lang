#include "base.hpp"
#include "config.hpp"
#include "jovo/cli.hpp"
#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include <string>
#include <iostream>

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

  else if (command == "test") {
    str code = "42 + 13";

    jovolang::Lexer lexer(code);
    auto tokens = lexer.tokenize();

    jovolang::Parser parser(tokens);
    auto ast = parser.parse();

    // for (const auto &token : tokens) {
    //   std::cout << "Token: " << token.value << "\n";
    // }

    std::cout << "Parsing complete." << "\n";
  }

  else {
    print_help();
  }

  return 0;
}