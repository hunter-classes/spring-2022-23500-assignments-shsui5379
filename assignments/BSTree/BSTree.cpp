#include <iostream>
#include "Node.h"

#include "BSTree.h"

BSTree::BSTree()
{
   root = nullptr;
}

std::string BSTree::get_debug_string()
{
   if (root == nullptr)
   {
      return "";
   }
   else
   {
      return std::to_string(root->getData()) + "\n" + std::to_string(root->getLeft()->getData()) + "\n" + std::to_string(root->getRight()->getData()) + "\n" + std::to_string(root->getLeft()->getLeft()->getData());
   }
}

void BSTree::setup()
{
   Node *n = new Node(10);
   root = n;
   n = new Node(20);
   root->setLeft(n);
   n = new Node(30);
   root->setRight(n);
   n = new Node(40);
   root->getLeft()->setLeft(n);
}