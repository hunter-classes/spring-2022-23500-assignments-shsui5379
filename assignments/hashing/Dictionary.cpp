#include <string>
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

   lastAssignedId = 0;
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

/**
 * @brief Hashes the name using a simple mod function
 *
 * @param name Full name of the Person
 * @return int Hash for which spot in the Dictionary the Person should be located
 */
int Dictionary::hash(std::string name)
{
   int asciiSum = 0;

   for (char c : name)
   {
      asciiSum += c;
   }

   return asciiSum % size;
}

/**
 * @brief Inserts a new Person in this Dictionary
 *
 * @param firstName The Person's first name
 * @param lastName The Person's last name
 */
void Dictionary::insert(std::string firstName, std::string lastName)
{
   arr[hash(firstName + " " + lastName)]->insert(new Person(firstName, lastName, ++lastAssignedId));
}