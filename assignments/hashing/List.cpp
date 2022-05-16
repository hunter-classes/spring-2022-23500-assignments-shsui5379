#include <iostream>

#include "List.h"

List::List()
{
   head = nullptr;
   length = 0;
}

void List::insert(std::string data)
{
   Node *new_node = new Node(data);

   new_node->setNext(head);
   head = new_node;

   length++;
}

void List::insert(int index, std::string data)
{
   if (index == 0)
   {
      return insert(data);
   }

   if (index < 0 || index > length)
   {
      throw std::out_of_range("Out of range");
   }

   Node *new_node = new Node(data);
   Node *walker = head;

   for (int i = 0; i < index - 1; i++)
   {
      walker = walker->getNext();
   }

   new_node->setNext(walker->getNext());
   walker->setNext(new_node);

   length++;
}

std::string List::toString()
{
   if (head == nullptr)
      return "nullptr";

   Node *walker = head;
   std::string s = "";

   while (walker != nullptr)
   {
      s += walker->getData() + " --> ";
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

void List::remove(int loc)
{
   if (loc > -1 && loc < getLength())
   {
      Node *walker = head;

      for (int i = 0; i < loc - 1; i++)
      {
         walker = walker->getNext();
      }

      Node *target;
      if (loc > 0)
      {
         target = walker->getNext();
      }
      else
      {
         target = head;
         head = target->getNext();
      }

      walker->setNext(target->getNext());

      delete target;

      length--;
   }
   else
   {
      throw std::out_of_range("Out of range");
   }
}

int List::getLength()
{
   return length;
}

std::string List::get(int index)
{
   if (index < 0 || index > length - 1)
   {
      throw std::out_of_range("Out of range");
   }

   Node *walker = head;

   for (int i = 0; i < index; i++)
   {
      walker = walker->getNext();
   }

   return walker->getData();
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