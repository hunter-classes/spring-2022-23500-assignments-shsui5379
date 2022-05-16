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
   void remove(int loc);
   int getLength();
   std::string get(int index);
   ~List();
};