#ifndef TOKENSTRUCT
#define TOKENSTRUCT

#include "lexertypes.hpp"

struct token {
  int type;
  char *literal;
};

class TokenList {
private:
  int capacity;
  int current;
  struct Token *tokens;
  void resize();

public:
  TokenList();
  void addToken(struct token *toadd);
  struct token *getToken(int index);
  ~Token();

};

#endif
