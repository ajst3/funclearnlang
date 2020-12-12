#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "lib/token.hpp"
#include "lib/lexer.hpp"

using namespace std;

Lexer::Lexer(char *code_to_tokenize) {
  code = code_to_tokenize;
}

TokenList Lexer::tokenize() {
  spot = 0;
  int currline = 0;
  TokenList tokens = TokenList();
  while(code[spot] != '\0') {

    if(code[spot] == ' ') {
      spot += 1;
      continue;
    }

    if(code[spot] == '\n') {
      struct token *newToken = (struct token *) malloc(sizeof(struct token));
      newToken->type = ENDLINE;
      newToken->literal = "\n";
      tokens.addToken(newToken);
    }
    else if(code[spot] == '(') {
      // beginning of a function call
      struct token *newToken =
        (struct token *) malloc(sizeof(struct token));
      newToken->literal = "(";
      newToken->type = LEFT_PAREN;
      tokens.addToken(newToken);
    }
    else if(code[spot] == ')') {
      struct token *newToken =
        (struct token *) malloc(sizeof(struct token));
      newToken->literal = ")";
      newToken->type = RIGHT_PAREN;
      tokens.addToken(newToken);
    }
    else if(code[spot] == '=') {
      struct token *newToken =
        (struct token *) malloc(sizeof(struct token));
      newToken->literal = "=";
      newToken->type = SYMBOL;
      tokens.addToken(newToken);
    }
    else if(code[spot] == '-') {
      if(code[spot + 1] != '>') {
        printf("Incorrect symbol\n");
        exit(-1);
      }
      struct token *newToken =
        (struct token *) malloc(sizeof(struct token));
      newToken->type = SYMBOL;
      newToken->literal = "->";
      tokens.addToken(newToken);
      spot += 1;
    }
    else {
      tokens.addToken(buildLiteralToken(spot));
    }
    spot += 1;

  }

  struct token *newToken = (struct token *) malloc(sizeof(struct token));
  newToken->type = ENDPROGRAM;
  newToken->literal = "\0";
  tokens.addToken(newToken);

  return tokens;
}

struct token* Lexer::buildLiteralToken(int begin) {
  // Must determine if the literal is a variable or a number
  // TODO: distict between floating point and integer (for now just int)

  if(isalpha(code[begin])) {
    // First character is alphabetical so we assume this is a literal
    return buildIDToken(begin);
  }
  else {
    // First character is a number
    return buildNumericToken(begin);
  }
}

struct token* Lexer::buildIDToken(int begin) {
  struct token *newToken = (struct token *) malloc(sizeof(struct token));
  newToken->type = ID;
  int i = begin;
  while(isalpha(code[i])) {
    i += 1;
  }
  int end = i;
  spot = end-1;
  char *literal = getLiteral(begin, end);
  newToken->literal = literal;
  return newToken;
}

struct token* Lexer::buildNumericToken(int begin) {
  struct token *newToken = (struct token *) malloc(sizeof(struct token));

  int i = begin;
  while(isdigit(code[i])) {
    i += 1;
  }
  int end = i;
  spot = end-1;

  char *literal = getLiteral(begin, end);
  newToken->literal = literal;
  newToken->type = NUMERIC;
  return newToken;
}

char* Lexer::getLiteral(int begin, int end) {
  char *literal = (char *) malloc(sizeof(char) * (end - begin));
  int i;
  int li = 0;
  for(i = begin; i < end; ++i) {
    literal[li] = code[i];
    li += 1;
  }
  return literal;
}

Lexer::~Lexer() {

}
