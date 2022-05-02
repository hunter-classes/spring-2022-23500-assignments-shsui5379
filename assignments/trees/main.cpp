#include <iostream>
#include "Node.h"
#include "BSTree.h"

int main()
{
   BSTree *tree = new BSTree();

   tree->setup();

   std::cout << tree->rsearch(3) << std::endl;
   std::cout << tree->rsearch(5) << std::endl;
   std::cout << tree->rsearch(8) << std::endl;
   std::cout << tree->rsearch(15) << std::endl;
   std::cout << tree->rsearch(20) << std::endl;
   std::cout << tree->rsearch(30) << std::endl;

   try
   {
      std::cout << tree->rsearch(0) << std::endl;
   }
   catch (int e)
   {
      std::cout << 0 << " not found" << std::endl;
   }

   tree->rinsert(17);
   std::cout << tree->rsearch(17) << std::endl;

   return 0;
}