#pragma once

#include "List.h"

#define INVALID_SIZE 1

class Dictionary
{
private:
   List **arr;
   int size;

public:
   Dictionary(int s);
   ~Dictionary();
};