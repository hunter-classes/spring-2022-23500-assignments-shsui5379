#include <iostream>
#include "Node.h"

#include "BSTree.h"

BSTree::BSTree()
{
   root = nullptr;
}

std::string BSTree::get_debug_string()
{
   return get_debug_string_helper(root);
}

std::string BSTree::get_debug_string_helper(Node *subtreeRoot)
{
   if (subtreeRoot == nullptr)
   {
      return "";
   }

   if (subtreeRoot->getLeft() == nullptr && subtreeRoot->getRight() == nullptr)
   {
      return std::to_string(subtreeRoot->getData());
   }

   return std::to_string(subtreeRoot->getData()) + "\n" + get_debug_string_helper(subtreeRoot->getLeft()) + "\n" + get_debug_string_helper(subtreeRoot->getRight());
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