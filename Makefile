all: cppsort.so

out/Sort.o: Makefile sort/Sort.hpp sort/Sort.cpp
	g++ -I/usr/include/python3.8 -c -fPIC sort/Sort.cpp -o out/Sort.o

cppsort.so: Makefile out/Sort.o
	g++ out/Sort.o -shared -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_python38.so.1.71.0 -Wl,-soname,-cppsort -o cppsort.so
