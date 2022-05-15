#pragma once

#define NODE_NOT_FOUND 1

class BSTree
{
private:
   Node *root;
   int rsearch(int value, Node *root);
   void rinsert(int value, Node *root);
   void remove(int value, Node *trailer);
   int countLeaves(Node *root);
   int getHeight(Node *root);
   int levelFound(int value, Node *root, int currentLevel);

public:
   BSTree();
   std::string get_debug_string();
   std::string traverse(Node *subtreeRoot);
   void insert(int data);
   void setup();
   int search(int value);
   int rsearch(int value);
   void rinsert(int value);
   void remove(int value);
   int countLeaves();
   int getHeight();
   bool areCousins(int a, int b);
};