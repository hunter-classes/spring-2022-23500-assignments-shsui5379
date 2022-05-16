#pragma once

#include <iostream>
#include "Node.h"
#include "Person.h"

#define NODE_NOT_FOUND 1

class List
{
protected:
   Node *head;
   int length;

public:
   List();
   void insert(Person *person);
   std::string toString();
   void remove(int loc);
   int getLength();
   Person *get(std::string firstName, std::string lastName);
   ~List();
};