#include "Stack.h"
/**
 * Initializes a Stack that can fit s strings
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
   topIndex = -1;
   size = s;
}

/**
 * Destructs this Stack
 * */
Stack::~Stack()
{
   delete list;
}

/**
 * Pushes string onto this Stack
 *
 * @param s  The int to push
 * */
void Stack::push(std::string s)
{
   if (topIndex + 1 == size)
   {
      throw STACK_ERR_FULL;
   }

   topIndex++;
   list->insert(s);
}

/**
 * Remove and return the top item
 *
 * @returns  The top item
 * */
std::string Stack::pop()
{
   if (is_empty())
   {
      throw STACK_ERR_EMPTY;
   }

   std::string data = list->get(0);
   list->remove(0);
   topIndex--;

   return data;
}

/**
 * Get the top item of this Stack
 *
 * @returns  The top item
 * */
std::string Stack::top()
{
   if (is_empty())
   {
      throw STACK_ERR_EMPTY;
   }

   return list->get(0);
}

/**
 * Returns whether this Stack is empty
 *
 * @returns  True if empty
 * */
bool Stack::is_empty()
{
   return topIndex == -1;
}