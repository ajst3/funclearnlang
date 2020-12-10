CPPFLAGS = -Wall
CXX = g++
LIBDIR = -L..
LIBS = -lcompilerlib
INCLUDES = -I../compiler/lib
OBJECTS = lexertest

.cpp:
	$(MAKE) -C ..
	$(CXX) $(CPPFLAGS) $(INCLUDES) $^ -o $@ $(LIBDIR) $(LIBS)

clean:
	rm -f $(OBJECTS)
