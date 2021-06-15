CXX=clang++
CXX_FLAGS=-std=c++20 -stdlib=libc++ -g -O0 -Wall -Wextra -Werror -Iincludes/

.PHONY: test clean

main: main.o obj/student.o
	mkdir -p bin
	${CXX} ${CXX_FLAGS} -lc++abi obj/main.o obj/student.o -o bin/main

main.o: src/main.cc student.o includes/student.hpp
	mkdir -p obj
	${CXX} ${CXX_FLAGS} -c src/main.cc -o obj/main.o

test: test.o student.o
	mkdir -p bin
	${CXX} ${CXX_FLAGS} -lc++abi obj/test.o obj/student.o -o bin/test

test.o: tests/catch.hpp tests/test.cc includes/student.hpp
	mkdir -p obj
	${CXX} ${CXX_FLAGS} -c tests/test.cc -o obj/test.o

student.o: includes/student.hpp src/student.cc
	mkdir -p obj
	${CXX} ${CXX_FLAGS} -c src/student.cc -o obj/student.o

clean:
	rm -f bin/* obj/*
