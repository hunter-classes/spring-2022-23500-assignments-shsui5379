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
   size = s;
}

/**
 * Destructs this Queue
 * */
Queue::~Queue()
{
   delete[] arr;
}

/**
 * Adds an item to this Queue
 *
 * @param n  The item to add
 * */
void Queue::enqueue(int n)
{
   if (is_full())
   {
      throw QUEUE_ERR_FULL;
   }

   tail++;
   arr[tail % size] = n;
}

/**
 * Determine if this Queue is full
 *
 * @returns  True if full
 * */
bool Queue::is_full()
{
   return (tail + 1) % size == head % size;
}

/**
 * Determiens if this Queue is empty
 *
 * @returns  True if empty
 * */
bool Queue::is_empty()
{
   return head % size == tail % size;
}