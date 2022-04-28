#pragma once

#define QUEUE_ERR_INVALID_SIZE 1

class Queue
{
private:
   int head;
   int tail;
   int *arr;
   bool empty;
   int size;

public:
   Queue(int s);
   ~Queue();
   void enqueue(int n);
   int dequeue();
   int front();
   bool is_empty();
   bool is_full();
};