#include <iostream>
#include "Stack.h"

int main()
{
   Stack *stack = new Stack(3);

   try
   {
      Stack *s = new Stack(0);
   }
   catch (int e)
   {
      std::cout << "Invalid size" << std::endl;
   }

   std::cout << stack->is_empty() << std::endl;

   stack->push("1");

   std::cout << stack->is_empty() << std::endl;
   std::cout << stack->top() << std::endl;

   stack->push("2");
   std::cout << stack->top() << std::endl;

   stack->push("3");
   std::cout << stack->top() << std::endl;

   try
   {
      stack->push("4");
   }
   catch (int e)
   {
      std::cout << "Stack is full" << std::endl;
   }

   std::cout << stack->pop() << std::endl;
   std::cout << stack->top() << std::endl;

   std::cout << stack->pop() << std::endl;
   std::cout << stack->top() << std::endl;

   std::cout << stack->pop() << std::endl;
   try
   {
      std::cout << stack->top() << std::endl;
   }
   catch (int e)
   {
      std::cout << "Stack is empty" << std::endl;
   }

   std::cout << "----------" << std::endl;

   return 0;
}