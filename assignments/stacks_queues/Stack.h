#pragma once

#include "List.h"

#define STACK_ERR_INVALID_SIZE 1

class Stack
{
private:
   List *list;
   int topIndex;
   int size;

public:
   Stack(int s);
   ~Stack();
   void push(int n);
   int pop();
   int top();
   bool is_empty();
};