#include <iostream>
#include "Node.h"

int main()
{
   Node *n1 = new Node(10);
   Node *n2 = new Node(20);
   Node *n3 = new Node(30);
   Node *n4 = new Node(40);
   Node *n5 = new Node(50);
   Node *n6 = new Node(60);
   Node *n7 = new Node(70);

   n1->setLeft(n2);
   n2->setLeft(n3);
   n3->setLeft(n4);

   n1->setRight(n5);
   n5->setLeft(n6);
   n5->setRight(n7);

   std::cout << n1->getLeft()->getData() << std::endl;
   std::cout << n2->getLeft()->getData() << std::endl;
   std::cout << n3->getLeft()->getData() << std::endl;
   std::cout << n1->getRight()->getData() << std::endl;
   std::cout << n5->getLeft()->getData() << std::endl;
   std::cout << n5->getRight()->getData() << std::endl;

   return 0;
}