#ifndef __JOVO__PARSER_H_
#define __JOVO__PARSER_H_

#include "ast/ast.hpp"
#include "base.hpp"
#include "lexer/token.hpp"

namespace jovolang {

class Parser {
private:
  vector<Token> tokens;
  size_t pos = 0;

  Token peek() const {
    if (pos < tokens.size())
      return tokens[pos];

    return {TokenType::END_OF_FILE, "EOF"};
  }

  Token advance() { return tokens[pos++]; }

  std::unique_ptr<ASTNode> parsePrimary() {
    Token current = advance();
    if (current.type == TokenType::NUMBER) {
      return std::make_unique<NumberNode>(current.value);
    }

    throw std::runtime_error("Unexpected token: " + current.value);
  }

  std::unique_ptr<ASTNode> parseExpression() {
    auto left = parsePrimary();

    while (peek().type == TokenType::OPERATOR) {
      Token op = advance();
      auto right = parsePrimary();
      left = std::make_unique<BinaryOpNode>(std::move(left), op.value, std::move(right));
    }

    return left;
  }

public:
  explicit Parser(std::vector<Token> t) : tokens(std::move(t)) {}

  std::unique_ptr<ASTNode> parse() { return parseExpression(); };
};

} // namespace jovolang

#endif