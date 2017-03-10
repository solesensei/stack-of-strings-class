#include <iostream>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

#define p_SIZE 10

class Stack
{
public:
  Stack (int x = 10, int y = 255);
  ~Stack ();
  void print_stack() const;
  bool push (const char*);
  char* pop();
  char* peek() const;
  int length() const;
  int maxsize() const;
  bool operator+ (const char*);
  bool operator- (char* &);
private:
  char**  sp; //stack pointer
  int     top;
  int     size; //stack size
  int     str_size;

};

enum stack_cmd {push, pop, peek, print, length, size, undef, spush, spop, help };
stack_cmd _selector(const char*);
const char* str_find (const char*);
