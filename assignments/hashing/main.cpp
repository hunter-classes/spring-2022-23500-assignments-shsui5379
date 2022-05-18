#include <iostream>
#include "Dictionary.h"

int main()
{
   try
   {
      Dictionary *d = new Dictionary(0);
   }
   catch (int e)
   {
      std::cout << "Dictionary must have a size of at least 1" << std ::endl;
   }

   Dictionary *d = new Dictionary(3);

   d->insert("Shalom", "Tomczak");
   d->insert("Kibwe", "Sampson");
   d->insert("Aitor", "Espensen");
   d->insert("Karma", "Yamagishi");
   d->insert("Lena", "Jans");
   d->insert("Aroa", "MacKenna");

   std::cout << d->getAll() << std::endl;

   std::cout << d->get("Lena", "Jans")->get_name() << " exists" << std::endl;
   std::cout << "Aroa Jans" << ((d->get("Aroa", "Jans") == nullptr) ? " doesn't" : "does") << std::endl;

   return 0;
}