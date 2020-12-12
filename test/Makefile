CPPFLAGS = -Wall
CXX = g++
LIBDIR = -L..
LIBS = -lcompiler
INCLUDES = -I../src/
OBJECTS = basiclexertest

.cpp:
	$(MAKE) -C ..
	$(CXX) $(CPPFLAGS) $(INCLUDES) $^ -o $@ $(LIBDIR) $(LIBS)

clean:
	rm -f $(OBJECTS)
