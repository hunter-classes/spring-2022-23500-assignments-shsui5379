#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../commons/doctest.h"

#include "Node.h"
#include "BSTree.h"

TEST_CASE("rsearch")
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

   CHECK_THROWS(tree->rsearch(0), NODE_NOT_FOUND);
}

TEST_CASE("rinsert")
{
   BSTree *tree = new BSTree();
   tree->setup();

   tree->rinsert(8);
   CHECK(tree->get_debug_string() == "10, 5, 3, 8, 20, 15, 30");

   tree->rinsert(17);
   CHECK(tree->rsearch(17) == 17);
   CHECK(tree->get_debug_string() == "10, 5, 3, 8, 20, 15, , 17, 30");
}

TEST_CASE("remove")
{
   BSTree *tree = new BSTree();
   tree->setup();

   // invalid
   CHECK_THROWS(tree->remove(120), NODE_NOT_FOUND);

   // remove root w/ 2 children
   CHECK(tree->rsearch(10) == 10);
   tree->remove(10);
   CHECK_THROWS(tree->rsearch(10), NODE_NOT_FOUND);
   CHECK(tree->get_debug_string() == "15, 5, 3, 8, 20, , 30");

   // remove node w/ one child
   CHECK(tree->rsearch(20) == 20);
   tree->remove(20);
   CHECK_THROWS(tree->rsearch(20), NODE_NOT_FOUND);
   CHECK(tree->get_debug_string() == "15, 5, 3, 8, 30");

   // remove leaf
   CHECK(tree->rsearch(30) == 30);
   tree->remove(30);
   CHECK_THROWS(tree->rsearch(30), NODE_NOT_FOUND);
   CHECK(tree->get_debug_string() == "15, 5, 3, 8, ");

   // remove node w/ two children
   CHECK(tree->rsearch(5) == 5);
   tree->remove(5);
   CHECK_THROWS(tree->rsearch(5), NODE_NOT_FOUND);
   CHECK(tree->get_debug_string() == "15, 8, 3, , ");

   // remove root w/ one child
   CHECK(tree->rsearch(15) == 15);
   tree->remove(15);
   CHECK_THROWS(tree->rsearch(15), NODE_NOT_FOUND);
   CHECK(tree->get_debug_string() == "8, 3, ");

   CHECK(tree->rsearch(8) == 8);
   tree->remove(8);
   CHECK_THROWS(tree->rsearch(8), NODE_NOT_FOUND);
   CHECK(tree->get_debug_string() == "3");

   // remove root that's leaf
   CHECK(tree->rsearch(3) == 3);
   tree->remove(3);
   CHECK_THROWS(tree->rsearch(3), NODE_NOT_FOUND);
   CHECK(tree->get_debug_string() == "");
}

TEST_CASE("countLeaves")
{
   BSTree *tree = new BSTree();
   CHECK(tree->countLeaves() == 0);

   tree->setup();
   CHECK(tree->countLeaves() == 4);

   tree->rinsert(12);
   CHECK(tree->countLeaves() == 4);

   tree->remove(12);
   tree->remove(3);
   CHECK(tree->countLeaves() == 3);
}

TEST_CASE("height")
{
   BSTree *tree = new BSTree();
   CHECK(tree->getHeight() == 0);

   tree->setup();
   CHECK(tree->getHeight() == 3);

   tree->rinsert(12);
   CHECK(tree->getHeight() == 4);

   tree->remove(3);
   CHECK(tree->getHeight() == 4);
}