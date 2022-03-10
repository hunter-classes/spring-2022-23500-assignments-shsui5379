#include "List.h"
#include "OList.h"
#include <string>

OList::OList() : List::List() {}

OList::~OList()
{
   List::~List();
}