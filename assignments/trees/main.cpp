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
   std::cout << tree->get_debug_string() << std::endl;

   std::cout << "----------" << std::endl;

   BSTree *tree2 = new BSTree();
   tree2->setup();
   std::cout << tree2->get_debug_string() << std::endl;
   std::cout << "Tree has " << tree2->countLeaves() << " leaves" << std::endl;
   std::cout << "Tree's height is " << tree2->getHeight() << " nodes" << std::endl;

   tree2->remove(10);
   try
   {
      tree2->rsearch(10);
   }
   catch (int e)
   {
      std::cout << "10 got removed" << std::endl;
   }
   std::cout << tree2->get_debug_string() << std::endl;
   std::cout << "Tree has " << tree2->countLeaves() << " leaves" << std::endl;
   std::cout << "Tree's height is " << tree2->getHeight() << " nodes" << std::endl;

   tree2->remove(20);
   try
   {
      tree2->rsearch(20);
   }
   catch (int e)
   {
      std::cout << "20 got removed" << std::endl;
   }
   std::cout << tree2->get_debug_string() << std::endl;
   std::cout << "Tree has " << tree2->countLeaves() << " leaves" << std::endl;
   std::cout << "Tree's height is " << tree2->getHeight() << " nodes" << std::endl;

   tree2->remove(30);
   try
   {
      tree2->rsearch(30);
   }
   catch (int e)
   {
      std::cout << "30 got removed" << std::endl;
   }
   std::cout << tree2->get_debug_string() << std::endl;
   std::cout << "Tree has " << tree2->countLeaves() << " leaves" << std::endl;
   std::cout << "Tree's height is " << tree2->getHeight() << " nodes" << std::endl;

   tree2->remove(5);
   try
   {
      tree2->rsearch(5);
   }
   catch (int e)
   {
      std::cout << "5 got removed" << std::endl;
   }
   std::cout << tree2->get_debug_string() << std::endl;
   std::cout << "Tree has " << tree2->countLeaves() << " leaves" << std::endl;
   std::cout << "Tree's height is " << tree2->getHeight() << " nodes" << std::endl;

   tree2->remove(15);
   try
   {
      tree2->rsearch(15);
   }
   catch (int e)
   {
      std::cout << "15 got removed" << std::endl;
   }
   std::cout << tree2->get_debug_string() << std::endl;
   std::cout << "Tree has " << tree2->countLeaves() << " leaves" << std::endl;
   std::cout << "Tree's height is " << tree2->getHeight() << " nodes" << std::endl;

   tree2->remove(8);
   try
   {
      tree2->rsearch(8);
   }
   catch (int e)
   {
      std::cout << "8 got removed" << std::endl;
   }
   std::cout << tree2->get_debug_string() << std::endl;
   std::cout << "Tree has " << tree2->countLeaves() << " leaves" << std::endl;
   std::cout << "Tree's height is " << tree2->getHeight() << " nodes" << std::endl;

   tree2->remove(3);
   try
   {
      tree2->rsearch(3);
   }
   catch (int e)
   {
      std::cout << "3 got removed" << std::endl;
   }
   std::cout << tree2->get_debug_string() << std::endl;
   std::cout << "Tree has " << tree2->countLeaves() << " leaves" << std::endl;
   std::cout << "Tree's height is " << tree2->getHeight() << " nodes" << std::endl;

   std::cout << "----------" << std::endl;

   BSTree *tree3 = new BSTree();
   tree3->setup();

   std::cout << "are 10 and 15 cousins: " << tree3->areCousins(10, 15) << std::endl;

   std::cout << "are 10 and 0 cousins: ";
   try
   {
      tree3->areCousins(10, 0);
   }
   catch (int e)
   {
      std::cout << "0 is not on the tree" << std::endl;
   }

   std::cout << "are 5 and 20 cousins: " << tree3->areCousins(5, 20) << std::endl;
   std::cout << "are 5 and 10 cousins: " << tree3->areCousins(5, 10) << std::endl;

   std::cout << "are 8 and 30 cousins: " << tree3->areCousins(8, 30) << std::endl;
   std::cout << "are 3 and 20 cousins: " << tree3->areCousins(3, 20) << std::endl;

   return 0;
}
