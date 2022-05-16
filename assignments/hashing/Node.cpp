#include <iostream>
#include "Node.h"

Node::Node() : next(nullptr) {}

Node::Node(Person *person)
{
   this->data = data;
   this->next = nullptr;
}

Node::Node(Person *person, Node *next)
{
   this->data = data;
   this->next = next;
}

void Node::setNext(Node *next)
{
   this->next = next;
}

Person *Node::getData()
{
   return this->data;
}

Node *Node::getNext()
{
   return this->next;
}