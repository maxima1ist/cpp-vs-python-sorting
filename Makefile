all: cppsort.so

out/Sort.o: Makefile sort/Sort.hpp sort/Sort.cpp
	g++ -I./include -I/usr/include/python3.8 -c -fPIC sort/Sort.cpp -o out/Sort.o

cppsort.so: Makefile out/Sort.o
	g++ out/Sort.o -shared -Wl,-rpath,./lib ./lib/libboost_python38.so.1.77.0 -Wl,-soname,-cppsort -o cppsort.so
