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

   std::cout << "Position of c: " << list->locate("c") << std::endl;

   std::cout << "Removing c..." << std::endl;

   list->remove("c");

   std::cout << list->toString() << std::endl;

   return 0;
}