#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <compiler/lib/lexer.hpp>
#include <compiler/lib/token.hpp>

using namespace std;

int main(int argc, char const *argv[]) {
  char *teststring = "name = 100\nresult = func(name)\n";
  printf("creating object\n");
  Lexer lex = Lexer(teststring);
  printf("tokenizing\n");
  TokenList tokens = lex.tokenize();
  printf("printing list\n");
  tokens.printTokenList();
  return 0;
}
