#pragma once

#include <iostream>
#include "Node.h"

class List
{
protected:
   Node *head;
   int length;

public:
   List();
   void insert(std::string data);
   void insert(int index, std::string data);
   std::string toString();
   int locate(std::string data);
   void remove(std::string data);
   int getLength();
   std::string get(int index);
   ~List();
};