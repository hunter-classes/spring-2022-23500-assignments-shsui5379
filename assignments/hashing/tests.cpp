#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../commons/doctest.h"

#include "Dictionary.h"

TEST_CASE("valid size")
{
   CHECK_NOTHROW(new Dictionary(1));
   CHECK_THROWS(new Dictionary(0), INVALID_SIZE);
}

TEST_CASE("hash")
{
   Dictionary *d = new Dictionary(3);
   CHECK(d->hash("hash") == ('h' + 'a' + 's' + 'h') % 3);
   CHECK(d->hash("") == 0);
}

TEST_CASE("insert and get")
{
   Dictionary *d = new Dictionary(3);

   d->insert("Shalom", "Tomczak");
   d->insert("Kibwe", "Sampson");
   d->insert("Aitor", "Espensen");
   d->insert("Karma", "Yamagishi");
   d->insert("Lena", "Jans");
   d->insert("Aroa", "MacKenna");

   Person *p = d->get("Shalom", "Tomczak");
   CHECK(p->get_name() == "Tomczak,Shalom");

   p = d->get("Kibwe", "Sampson");
   CHECK(p->get_name() == "Sampson,Kibwe");

   p = d->get("Aitor", "Espensen");
   CHECK(p->get_name() == "Espensen,Aitor");

   p = d->get("Karma", "Yamagishi");
   CHECK(p->get_name() == "Yamagishi,Karma");

   p = d->get("Lena", "Jans");
   CHECK(p->get_name() == "Jans,Lena");

   p = d->get("Aroa", "MacKenna");
   CHECK(p->get_name() == "MacKenna,Aroa");

   CHECK(d->get("Lena", "MacKenna") == nullptr);
}

TEST_CASE("insert and getAll")
{
   Dictionary *d = new Dictionary(3);

   CHECK(d->getAll() == "nullptr\nnullptr\nnullptr\n");

   d->insert("Shalom", "Tomczak");
   d->insert("Kibwe", "Sampson");
   d->insert("Aitor", "Espensen");
   d->insert("Karma", "Yamagishi");
   d->insert("Lena", "Jans");
   d->insert("Aroa", "MacKenna");

   CHECK(d->getAll() == "MacKenna,Aroa --> nullptr\nSampson,Kibwe --> nullptr\nJans,Lena --> Yamagishi,Karma --> Espensen,Aitor --> Tomczak,Shalom --> nullptr\n");
}