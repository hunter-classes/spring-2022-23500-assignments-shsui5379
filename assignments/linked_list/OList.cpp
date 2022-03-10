#include "List.h"
#include "OList.h"
#include <string>

OList::OList() : List::List() {}

OList::~OList() {}

/**
 * Inserts a new Node to this list so that it's still in increasing order
 *
 * @param value  Value for the new Node to insert
 * */
void OList::insert(std::string value)
{
   int index = 0;

   while (index < getLength() && get(index) < value)
   {
      index++;
   }

   List::insert(index, value);
}

/**
 * Get a value from a location
 *
 * @param loc  The locatoin
 * @returns  The value at `loc`
 * */
std::string OList::get(int loc)
{
   return List::get(loc);
}

/**
 * Get the string representation of this linked list
 *
 * @returns  String representation of this linked list
 * */
std::string OList::toString()
{
   return "head --> " + List::toString();
}