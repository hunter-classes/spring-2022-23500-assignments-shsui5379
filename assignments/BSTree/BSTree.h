#pragma once

class BSTree
{
private:
   Node *root;

public:
   BSTree();
   std::string get_debug_string();
   std::string get_debug_string_helper(Node *subtreeRoot);
   void insert(int data);
   void setup();
};