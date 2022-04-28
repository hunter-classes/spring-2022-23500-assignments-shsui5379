#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../commons/doctest.h"

#include "Stack.h"
#include "Queue.h"

TEST_CASE("Stack")
{
   Stack *stack = new Stack(3);
   CHECK_THROWS(new Stack(0), STACK_ERR_INVALID_SIZE);

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
   CHECK_THROWS(stack->pop(), STACK_ERR_EMPTY);

   CHECK(stack->is_empty() == true);
}

TEST_CASE("Queue")
{
   Queue *queue = new Queue(3);
   CHECK_THROWS(new Queue(0), QUEUE_ERR_INVALID_SIZE);

   CHECK(queue->is_empty() == true);
   CHECK(queue->is_full() == false);

   queue->enqueue(1);

   CHECK(queue->is_empty() == false);
   CHECK(queue->is_full() == false);
   CHECK(queue->front() == 1);

   queue->enqueue(2);
   queue->enqueue(3);

   CHECK_THROWS(queue->enqueue(4), QUEUE_ERR_FULL);
   CHECK(queue->is_empty() == false);
   CHECK(queue->is_full() == true);

   CHECK(queue->dequeue() == 1);
   CHECK(queue->front() == 2);

   CHECK(queue->dequeue() == 2);
   CHECK(queue->front() == 3);

   CHECK(queue->dequeue() == 3);
   CHECK_THROWS(queue->front(), QUEUE_ERR_EMPTY);
   CHECK_THROWS(queue->dequeue(), QUEUE_ERR_EMPTY);

   CHECK(queue->is_empty() == true);
   CHECK(queue->is_full() == false);

   CHECK(queue->is_empty() == true);
}
