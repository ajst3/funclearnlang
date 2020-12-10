.DEFAULT_GOAL := all

all: lexer
	ar rcs libcompiler.a src/compiler/*o

lexer:
	$(Make) -C src/compiler

clean:
	rm -f libcryptolib.a
	$(MAKE) -C src/compiler clean
