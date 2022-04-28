#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
   std::cout << "STACK" << std::endl;

   Stack *stack = new Stack(3);

   try
   {
      Stack *s = new Stack(0);
   }
   catch (int e)
   {
      std::cout << "0 is an invalid size" << std::endl;
   }

   std::cout << "is empty?: " << stack->is_empty() << std::endl;

   stack->push("1");
   std::cout << "pushed " << stack->top() << std::endl;

   std::cout << "is empty? " << stack->is_empty() << std::endl;

   stack->push("2");
   std::cout << "pushed " << stack->top() << std::endl;

   stack->push("3");
   std::cout << "pushed " << stack->top() << std::endl;

   try
   {
      stack->push("4");
   }
   catch (int e)
   {
      std::cout << "Stack is full" << std::endl;
   }

   std::cout << "popped " << stack->pop() << std::endl;
   std::cout << stack->top() << " remains" << std::endl;

   std::cout << "popped " << stack->pop() << std::endl;
   std::cout << stack->top() << " remains" << std::endl;

   std::cout << "popped " << stack->pop() << std::endl;
   try
   {
      std::cout << stack->top() << std::endl;
   }
   catch (int e)
   {
      std::cout << "Stack is empty" << std::endl;
   }

   std::cout << "----------\nQUEUE" << std::endl;

   Queue *queue = new Queue(3);
   try
   {
      Queue *q = new Queue(0);
   }
   catch (int e)
   {
      std::cout << "0 is an invalid size" << std::endl;
   }

   std::cout << "is empty?: " << queue->is_empty() << std::endl;
   std::cout << "is full?: " << queue->is_full() << std::endl;

   queue->enqueue(1);
   queue->enqueue(2);
   queue->enqueue(3);

   std::cout << "Queued 1, 2, 3" << std::endl;

   std::cout << "Next up: " << queue->front() << std::endl;

   std::cout << "is empty?: " << queue->is_empty() << std::endl;
   std::cout << "is full?: " << queue->is_full() << std::endl;

   try
   {
      queue->enqueue(4);
   }
   catch (int e)
   {
      std::cout << "Queue is full" << std::endl;
   }

   std::cout << "dequeue " << queue->dequeue() << std::endl;
   std::cout << "Next up: " << queue->front() << std::endl;

   std::cout << "enqueue 4" << std::endl;
   queue->enqueue(4);
   std::cout << "Next up: " << queue->front() << std::endl;

   std::cout << "dequeue " << queue->dequeue() << std::endl;
   std::cout << "Next up: " << queue->front() << std::endl;

   std::cout << "dequeue " << queue->dequeue() << std::endl;
   std::cout << "Next up: " << queue->front() << std::endl;

   std::cout << "dequeue " << queue->dequeue() << std::endl;
   try
   {
      queue->front();
   }
   catch (int e)
   {
      std::cout << "Queue is empty" << std::endl;
   }

   std::cout << "is empty?: " << queue->is_empty() << std::endl;
   std::cout << "is full?: " << queue->is_full() << std::endl;

   return 0;
}