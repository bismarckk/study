SHELL = /bin/sh
EXEC = factorial.o hello.o
CXXFLAGS = -O0 -Wall -pedantic -I. -g
LDFLAGS = -g -L.

main: main.cpp libtest.a
	$(CXX) $^ $(LDFLAGS) -o $@

libtest.a: $(EXEC)
	$(AR) cr $@ $(EXEC) # static library

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *~ *.bak *.o *.so *.a main
