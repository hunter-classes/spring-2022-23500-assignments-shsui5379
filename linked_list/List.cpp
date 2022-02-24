#include <iostream>

#include "List.h"

List::List()
{
   head = nullptr;
}

void List::insert(std::string data)
{
   Node *new_node = new Node(data);

   new_node->setNext(head);
   head = new_node;
}

std::string List::toString()
{
   if (head == nullptr)
      return "";

   Node *walker = head;
   std::string s = "";

   while (walker != nullptr)
   {
      s += walker->getData() + "-->";
      walker = walker->getNext();
   }

   s += "nullptr";
   return s;
}

/**
 * Finds the index of a piece of data on this list
 *
 * @param data  The data to search for
 * @returns  The index of data
 * */
int List::locate(std::string data)
{
   if (head == nullptr)
      return -1;

   int index = 0;
   Node *walker = head;

   while (walker != nullptr)
   {
      if (walker->getData() == data)
         return index;

      index++;
      walker = walker->getNext();
   }

   return -1;
}

/**
 * Remove the first instance of data
 *
 * @param data  The data to remove
 * */
void List::remove(std::string data)
{
   int position = locate(data);

   if (position > -1)
   {
      Node *walker = head;

      for (int i = 0; i < position - 1; i++)
      {
         walker = walker->getNext();
      }

      walker->setNext(walker->getNext()->getNext());
   }
}

List::~List()
{
   Node *walker = head;

   while (walker != nullptr)
   {
      Node *current = walker;
      walker = walker->getNext();
      delete current;
   }
}