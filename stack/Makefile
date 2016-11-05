Flags = -Wextra -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11 -Wall -g
CPP = g++

main :  main.o stack.o 
	$(CPP) $(Flags)  main.o stack.o -o main

main.o :  main.cpp   stack.h 
	$(CPP) -c $(Flags) main.cpp -o main.o

stack.o :  stack.cpp   stack.h 
	$(CPP) -c $(Flags) stack.cpp -o stack.o