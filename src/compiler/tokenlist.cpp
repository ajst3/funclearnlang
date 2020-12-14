#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib/token.hpp"

using namespace std;

TokenList::TokenList() {
  tokens = (struct token **) malloc(sizeof(struct token *) * 300);
  current = 0;
  capacity = 300;
}

void TokenList::resize() {
  capacity *= 2;
  struct token **newlist =
    (struct token **) malloc(sizeof(struct token *) * capacity);
  int i;
  for(i = 0; i <= current; ++i) {
    newlist[i] = tokens[i];
  }
  free(tokens);
  tokens = newlist;
}

void TokenList::addToken(struct token *toadd) {
  if(current < capacity) {
    tokens[current] = toadd;
  }
  else {
    resize();
    tokens[current] = toadd;
  }
  capacity -= 1;
  current += 1;
}

struct token* TokenList::getToken(int index) {
  return tokens[index];
}

void TokenList::printTokenList() {
  int i;
  printf("Amount in list %d\n", current);
  for(i = 0; i < current; ++i) {
    printf("Token %d: type: %d, literal %s\n",
      i, tokens[i]->type, tokens[i]->literal);
  }
}

int TokenList::size() {
  return current;
}

struct token* TokenList::remove() {
  struct token *last = tokens[current];
  current -= 1;
  return last;
}

TokenList::~TokenList() {
  free(tokens);
}
