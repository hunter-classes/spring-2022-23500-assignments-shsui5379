#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../commons/doctest.h"
#include "OList.h"

TEST_CASE("get and insert")
{
   OList *olist = new OList();

   olist->insert("A");
   olist->insert("D");
   olist->insert("C");
   olist->insert("E");
   olist->insert("E");
   olist->insert("B");

   CHECK(olist->get(0) == "A");
   CHECK(olist->get(1) == "B");
   CHECK(olist->get(2) == "C");
   CHECK(olist->get(3) == "D");
   CHECK(olist->get(4) == "E");
   CHECK(olist->get(5) == "E");

   CHECK_THROWS_AS(olist->get(-1), std::out_of_range);
   CHECK_THROWS_AS(olist->get(6), std::out_of_range);
}

TEST_CASE("toString")
{
   OList *olist = new OList();

   CHECK(olist->toString() == "head --> nullptr");

   olist->insert("A");
   olist->insert("D");
   olist->insert("C");

   CHECK(olist->toString() == "head --> A --> C --> D --> nullptr");
}

TEST_CASE("contains")
{
   OList *olist = new OList();

   olist->insert("A");
   olist->insert("D");
   olist->insert("C");

   CHECK(olist->contains("B") == false);
   CHECK(olist->contains("A") == true);
   CHECK(olist->contains("C") == true);
   CHECK(olist->contains("D") == true);
}

TEST_CASE("remove")
{
   OList *olist = new OList();

   olist->insert("A");
   olist->insert("D");
   olist->insert("C");

   CHECK_THROWS_AS(olist->remove(-1), std::out_of_range);
   CHECK_THROWS_AS(olist->remove(4), std::out_of_range);

   olist->remove(1);
   CHECK(olist->toString() == "head --> A --> D --> nullptr");

   olist->remove(1);
   CHECK(olist->toString() == "head --> A --> nullptr");

   olist->remove(0);
   CHECK(olist->toString() == "head --> nullptr");
}

TEST_CASE("reverse")
{
   OList *olist = new OList();

   olist->reverse();
   CHECK(olist->toString() == "head --> nullptr");

   olist->insert("A");
   olist->reverse();
   CHECK(olist->toString() == "head --> A --> nullptr");

   olist->insert("D");
   olist->insert("C");
   olist->insert("E");
   olist->insert("B");
   olist->reverse();
   CHECK(olist->toString() == "head --> E --> D --> C --> B --> A --> nullptr");
}