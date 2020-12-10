#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib/token.hpp"

using namespace std;

TokenList:TokenList() {
  tokens = (struct token *) malloc(sizeof(struct token) * 300);
  current = 0;
  capacity = 300;
}

void TokenList:resize() {
  capacity *= 2;
  struct token *newlist =
    (struct token *) malloc(sizeof(struct token) * capacity);
  int i;
  for(i = 0l i <= current; ++i) {
    newlist[i] = tokens[i];
  }
  free(tokens);
  tokens = newlist;
}

void TokenList:addToken(struct token *toadd) {
  if(current + 1 < capacity) {
    tokens[current + 1] = toadd;
  }
  else {
    resize();
    tokens[current + 1] = toadd;
  }
  capacity -= 1;
  current += 1;
}

struct token* TokenList:getToken(int index) {
  return tokens[index];
}
