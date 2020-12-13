# Grammar

## Notes  
  - | means concat  
  - Program structure is a series of statements  
  - All statements are ended with a newline character  

## Production Rules  
  - Program -> Statments
  - Statements -> Statement | Statements
  - Statements -> emptystring
  - Statement -> Assignment  
  - Statement -> Conditional  
  - Assignment -> Identifier | = | FunctionCall  
  - Assignment -> Identifier | = | Identifier  
  - Assignment -> Identifier | = | Numeric
  - Assignment -> Identifier | = | CodeBlock  
  - FunctionCall -> Identifier | ( | Parameters | )  
  - Parameters -> Identifier | , | Parameters
  - Parameters -> emptystring  
  - CodeBlock -> \n | \t | Statements
  - Identifier -> Literal
