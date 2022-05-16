#pragma once

#include "Person.h"

class Node
{
private:
   Person *data;
   Node *next;

public:
   Node();
   Node(Person *person);
   Node(Person *person, Node *next);

   void setNext(Node *next);

   Person *getData();
   Node *getNext();
};