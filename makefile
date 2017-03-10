#CCC=g++
#FLG= -g -Wall

stack_class.o: stack_class.cpp string_stack.h 
	g++ -Wall -g -c stack_class.cpp -o stack_class.o
pr: main.cpp stack_class.o
	g++ -Wall -g main.cpp stack_class.o -o pr
test: test.cpp stack_class.o
	g++ -Wall -g test.cpp stack_class.o -o test
