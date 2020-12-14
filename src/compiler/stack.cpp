#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "lib/stack.hpp"

using namespace std;

Stack::Stack() : TokenList() {
  currentonstack = 0;
}

void Stack::push(struct token *toadd) {
  addToken(toadd);
}

struct token* Stack::pop() {
  return remove();
}

Stack::~Stack() {

}
