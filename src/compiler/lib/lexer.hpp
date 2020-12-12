#ifndef LEXER
#define LEXER

#include "token.hpp"

class Lexer {
private:
  char *code;
  int spot;

  struct token *buildLiteralToken(int begin);
  struct token *buildNumericToken(int begin);
  struct token *buildIDToken(int begin);

  char *getLiteral(int begin, int end);

public:
  Lexer(char *code_to_tokenize);
  TokenList tokenize();
  ~Lexer();

};
#endif
