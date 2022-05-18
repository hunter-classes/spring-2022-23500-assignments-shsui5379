#pragma once

#include <string>
#include "List.h"

#define INVALID_SIZE 1

class Dictionary
{
private:
   List **arr;
   int size;
   int lastAssignedId;

public:
   Dictionary(int s);
   ~Dictionary();
   int hash(std::string name);
   void insert(std::string firstName, std::string lastName);
   Person *get(std::string firstName, std::string lastName);
};