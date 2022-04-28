#include "Queue.h"

/**
 * Constructs a Queue
 *
 * @param s  The capacity
 * */
Queue::Queue(int s)
{
   if (s < 1)
   {
      throw QUEUE_ERR_INVALID_SIZE;
   }

   head = 0;
   tail = 0;
   arr = new int[s];
   empty = true;
   size = s;
}

/**
 * Destructs this Queue
 * */
Queue::~Queue()
{
   delete[] arr;
}