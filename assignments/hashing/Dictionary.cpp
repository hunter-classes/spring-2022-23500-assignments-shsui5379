#include "Dictionary.h"

/**
 * @brief Construct a new Dictionary:: Dictionary object
 *
 * @param s  The size of the Dictionary
 */
Dictionary::Dictionary(int s)
{
   if (s < 1)
   {
      throw INVALID_SIZE;
   }

   size = s;
   arr = new List *[size];

   for (int i = 0; i < size; i++)
   {
      arr[i] = new List();
   }
}

/**
 * @brief Destroy the Dictionary:: Dictionary object
 *
 */
Dictionary::~Dictionary()
{
   for (int i = 0; i < size; i++)
   {
      delete arr[i];
      arr[i] = nullptr;
   }

   delete[] arr;
   arr = nullptr;
}