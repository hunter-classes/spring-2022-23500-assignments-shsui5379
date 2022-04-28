#pragma once

#include "List.h"

#define STACK_ERR_INVALID_SIZE 1
#define STACK_ERR_FULL 2
#define STACK_ERR_EMPTY 4

class Stack
{
private:
   List *list;
   int topIndex;
   int size;

public:
   Stack(int s);
   ~Stack();
   void push(std::string s);
   std::string pop();
   std::string top();
   bool is_empty();
};