#include <iostream>

#include "List.h"

List::List()
{
   head = nullptr;
   length = 0;
}

void List::insert(Person *person)
{
   Node *new_node = new Node(person);

   new_node->setNext(head);
   head = new_node;

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
      s += walker->getData()->get_name() + " --> ";
      walker = walker->getNext();
   }

   s += "nullptr";
   return s;
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

Person *List::get(std::string firstName, std::string lastName)
{
   Node *walker = head;

   if (walker == nullptr)
   {
      throw NODE_NOT_FOUND;
   }

   for (int i = 0; i < length; i++)
   {
      if (walker->getData()->get_name() == firstName + " " + lastName)
      {
         return walker->getData();
      }

      walker = walker->getNext();
   }

   throw NODE_NOT_FOUND;
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