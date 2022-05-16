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
   empty = true;
   full = false;
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

   empty = false;

   arr[tail % size] = n;
   tail++;

   if (head % size == tail % size)
   {
      full = true;
   }
}

/**
 * Dequeue the first item from this Queue
 *
 * @returns  The first item
 * */
int Queue::dequeue()
{
   if (is_empty())
   {
      throw QUEUE_ERR_EMPTY;
   }

   full = false;

   int data = front();

   head++;

   if (head % size == tail % size)
   {
      empty = true;
   }

   return data;
}

/**
 * Gets the item from the front
 *
 * @returns  The first item
 * */
int Queue::front()
{
   if (is_empty())
   {
      throw QUEUE_ERR_EMPTY;
   }

   return arr[head % size];
}

/**
 * Determine if this Queue is full
 *
 * @returns  True if full
 * */
bool Queue::is_full()
{
   return full;
}

/**
 * Determiens if this Queue is empty
 *
 * @returns  True if empty
 * */
bool Queue::is_empty()
{
   return empty;
}