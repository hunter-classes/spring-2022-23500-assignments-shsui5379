#pragma once

class Node
{
private:
   int data;
   Node *left;
   Node *right;

public:
   Node();
   Node(int data);
   Node(int data, Node *left, Node *right);
   int getData();
   void setData(int d);
   Node *getLeft();
   Node *getRight();
   void setLeft(Node *l);
   void setRight(Node *r);
};