#ifndef STACK
#define STACK

#include "token.hpp"

class Stack : private TokenList {
private:
  int currentonstack;

public:
  Stack();
  void push(struct token *toadd);
  struct token *pop();
}

#endif
