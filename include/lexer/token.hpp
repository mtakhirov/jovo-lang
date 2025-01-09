#ifndef __JOVO__LEXER_TOKEN_H_
#define __JOVO__LEXER_TOKEN_H_

#include "base.hpp"

namespace jovolang {

enum class TokenType { IDENTIFIER, NUMBER, OPERATOR, PUNCTUATION, KEYWORD, END_OF_FILE };

struct Token {
  TokenType type;
  str value;
};

} // namespace jovolang

#endif // __JOVO__LEXER_TOKEN_H_