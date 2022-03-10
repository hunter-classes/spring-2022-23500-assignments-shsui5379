#pragma once

#include "List.h"
#include <string>

/**
 * A linked list of strings, but ordered in increasing order
 * */
class OList : public List
{
public:
   OList();
   ~OList();
   void insert(std::string value);
   std::string toString();
   bool contains(std::string value);
   std::string get(int loc);
   void remove(int loc);
   void reverse();
};