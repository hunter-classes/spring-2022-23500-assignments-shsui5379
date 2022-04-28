#include "Stack.h"
/**
 * Initializes a Stack that can fit s ints
 *
 * @param s  Size of the Stack to construct
 * */
Stack::Stack(int s)
{
   if (s < 1)
   {
      throw STACK_ERR_INVALID_SIZE;
   }

   list = new List();
   topIndex = 0;
   size = s;
}

/**
 * Destructs this Stack
 * */
Stack::~Stack()
{
   delete list;
}