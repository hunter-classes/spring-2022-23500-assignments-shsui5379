#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../commons/doctest.h"

#include "Node.h"
#include "BSTree.h"

TEST_CASE("rsearch and rinsert")
{
   BSTree *tree = new BSTree();
   tree->setup();

   CHECK(tree->rsearch(3) == 3);
   CHECK(tree->rsearch(5) == 5);
   CHECK(tree->rsearch(8) == 8);
   CHECK(tree->rsearch(10) == 10);
   CHECK(tree->rsearch(15) == 15);
   CHECK(tree->rsearch(20) == 20);
   CHECK(tree->rsearch(30) == 30);

   CHECK_THROWS(tree->rsearch(0), 1);

   tree->rinsert(17);
   CHECK(tree->rsearch(17) == 17);
}