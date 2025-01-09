#ifndef __JOVO__LEXER_H_
#define __JOVO__LEXER_H_

#include "base.hpp"
#include "lexer/token.hpp"
#include <cctype>

namespace jovolang {

class Lexer {
private:
  str source;
  size_t pos = 0;

  umap<str, TokenType> keywords = {
      {"if",     TokenType::KEYWORD},
      {"else",   TokenType::KEYWORD},
      {"while",  TokenType::KEYWORD},
      {"return", TokenType::KEYWORD}
  };

  char peek() const {
    if (pos < source.size())
      return source[pos];

    return '\0';
  }

  char advance() { return source[pos++]; }

  void skipWhitespace() {
    while (isspace(peek()))
      advance();
  }

  Token identifier() {
    std::string result;
    while (isalnum(peek()) || peek() == '_') {
      result += advance();
    }
    if (keywords.find(result) != keywords.end()) {
      return {keywords[result], result};
    }
    return {TokenType::IDENTIFIER, result};
  }

  Token number() {
    std::string result;
    while (isdigit(peek())) {
      result += advance();
    }
    return {TokenType::NUMBER, result};
  }

  Token op() {
    std::string result;
    result += advance();
    return {TokenType::OPERATOR, result};
  }

public:
  Lexer(const str &src) : source(src) {};

  vector<Token> tokenize() {
    vector<Token> tokens;

    while (pos < source.size()) {
      skipWhitespace();
      char current = peek();

      if (isalpha(current) || current == '_') {
        tokens.push_back(identifier());
      } else if (isdigit(current)) {
        tokens.push_back(number());
      } else if (ispunct(current)) {
        tokens.push_back(op());
      } else {
        advance();
      }
    }

    tokens.push_back({TokenType::END_OF_FILE, "EOF"});
    return tokens;
  }
};

} // namespace jovolang

#endif // __JOVO__LEXER_H_