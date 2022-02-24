#include <iostream>

#include "List.h"

List::List()
{
   head = nullptr;
}

void List::insert(std::string data)
{
   Node *new_node = new Node(data);

   if (head == nullptr)
   {
      head = new_node;
   }
   else
   {
      head->setNext(new_node);
   }
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

   s += "nulltpr";
   return s;
}