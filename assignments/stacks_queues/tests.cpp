#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../commons/doctest.h"

#include "Stack.h"

TEST_CASE("Stack")
{
   Stack *stack = new Stack(3);

   CHECK(stack->is_empty() == true);

   stack->push("1");

   CHECK(stack->is_empty() == false);
   CHECK(stack->top() == "1");

   stack->push("2");
   CHECK(stack->top() == "2");

   stack->push("3");
   CHECK(stack->top() == "3");

   CHECK_THROWS(stack->push("4"), STACK_ERR_FULL);

   CHECK(stack->pop() == "3");
   CHECK(stack->top() == "2");

   CHECK(stack->pop() == "2");
   CHECK(stack->top() == "1");

   CHECK(stack->pop() == "1");
   CHECK_THROWS(stack->top(), STACK_ERR_EMPTY);

   CHECK(stack->is_empty() == true);
}