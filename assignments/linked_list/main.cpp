#include <iostream>
#include "Node.h"
#include "List.h"

int main()
{
   List *list = new List();

   list->insert("a");
   list->insert("b");
   list->insert("c");
   list->insert("d");
   list->insert("e");

   std::cout << list->toString() << std::endl;

   std::cout << "Length of list: " << list->getLength() << std::endl;

   std::cout << "Position of c: " << list->locate("c") << std::endl;

   std::cout << "Removing c..." << std::endl;

   list->remove("c");

   std::cout << list->toString() << std::endl;

   std::cout << "Length of list: " << list->getLength() << std::endl;

   std::cout << "Element at index 1: " << list->get(1) << std::endl;

   std::cout << "Inserting a \"z\" at index 3:" << std::endl;

   list->insert(3, "z");

   std::cout << list->toString() << std::endl;

   std::cout << "Length of list: " << list->getLength() << std::endl;

   std::cout << "Inserting a \"x\" at index 0:" << std::endl;

   list->insert(0, "x");

   std::cout << list->toString() << std::endl;

   std::cout << "Length of list: " << list->getLength() << std::endl;

   std::cout << "Inserting a \"*\" at index 6:" << std::endl;

   list->insert(6, "*");

   std::cout << list->toString() << std::endl;

   std::cout << "Length of list: " << list->getLength() << std::endl;

   std::cout << "Removing x..." << std::endl;

   list->remove("x");

   std::cout << list->toString() << std::endl;

   std::cout << "Length of list: " << list->getLength() << std::endl;

   std::cout << "Removing *..." << std::endl;

   list->remove("*");

   std::cout << list->toString() << std::endl;

   std::cout << "Length of list: " << list->getLength() << std::endl;

   delete list;

   return 0;
}