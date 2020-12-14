#ifndef LEXERTYPES
#define LEXERTYPES

enum lexertype {
  KEYWORD,
  ID,
  NUMERIC,
  SYMBOL,
  LEFT_PAREN,
  RIGHT_PAREN,
  ENDLINE,
  ENDPROGRAM,

  // Combination types (used by parser)
  STATEMNT,
  ASSIGNMENT,
  FUNCTIONCALL
};

#endif
