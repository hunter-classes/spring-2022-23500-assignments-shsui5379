#pragma once

class BSTree
{
private:
   Node *root;

public:
   BSTree();
   std::string get_debug_string();
   std::string traverse(Node *subtreeRoot);
   void insert(int data);
   void setup();
   int search(int value);
   int rsearch(int value);
   int rsearch(int value, Node *root);
};