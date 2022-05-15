#include <iostream>
#include "Node.h"

#include "BSTree.h"

BSTree::BSTree()
{
   root = nullptr;
}

std::string BSTree::get_debug_string()
{
   return traverse(root);
}

std::string BSTree::traverse(Node *subtreeRoot)
{
   if (subtreeRoot == nullptr)
   {
      return "";
   }

   if (subtreeRoot->getLeft() == nullptr && subtreeRoot->getRight() == nullptr)
   {
      return std::to_string(subtreeRoot->getData());
   }

   return std::to_string(subtreeRoot->getData()) + ", " + traverse(subtreeRoot->getLeft()) + ", " + traverse(subtreeRoot->getRight());
}

void BSTree::setup()
{
   Node *n = new Node(10);
   root = n;
   n = new Node(20);
   root->setRight(n);
   Node *n2 = new Node(30);
   n->setRight(n2);
   n2 = new Node(15);
   n->setLeft(n2);
   n2 = new Node(5);
   root->setLeft(n2);
   n = new Node(3);
   n2->setLeft(n);
   n = new Node(8);
   n2->setRight(n);
}

int BSTree::search(int value)
{
   Node *t = root;

   while (t != nullptr)
   {
      int tval = t->getData();
      if (tval == value)
      {
         // here we'd really return a full object
         // with all the stuff associated with value
         // not just an int
         return value;
      }

      if (tval < value)
      {
         t = t->getRight();
      }
      else
      {
         t = t->getLeft();
      }
   }

   // if we get here then the value isn't
   // in the tree

   // normally, if we had a tree of objects
   // we could return null but since we only have
   // an int, we can't return an int to represent
   // not found so we'll throw an exception

   throw NODE_NOT_FOUND; // we should define our exceptions.
}

// we will always insert new nodes as leaves
void BSTree::insert(int value)
{

   // make a new node
   Node *newnode = new Node(value);

   // search for where the node would go as a leaf
   // that is, search until we get to null
   // we can use the piggyback strategy of having
   // a second pointer trail the lead pointer
   Node *p = root;
   Node *trailer;

   while (p != nullptr)
   {
      // note that trailer is one level behind
      trailer = p;
      if (p->getData() == value)
      {
         // do the stuff when the node is already in the tree
         return;
      }
      else if (p->getData() < value)
      {
         p = p->getRight();
      }
      else
      {
         p = p->getLeft();
      }
   }

   // handle the special case of the tree
   // being empty (null)
   if (root == nullptr)
   {
      root = newnode;
   }
   else
   {
      // trailer points to the node ABOVE where the new node
      // will go.
      // we have to figure out if newnode goes on the
      // left of trailer or on the right of trailer
      if (trailer->getData() < value)
      {
         trailer->setRight(newnode);
      }
      else
      {
         trailer->setLeft(newnode);
      }
   }
}

int BSTree::rsearch(int value)
{
   return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *root)
{
   if (root == nullptr)
   {
      throw NODE_NOT_FOUND;
   }

   if (root->getData() == value)
   {
      return value;
   }

   if (root->getLeft() == nullptr && root->getRight() == nullptr)
   {
      throw NODE_NOT_FOUND;
   }

   if (value > root->getData())
   {
      return rsearch(value, root->getRight());
   }

   return rsearch(value, root->getLeft());
}

void BSTree::rinsert(int value)
{
   rinsert(value, root);
}

void BSTree::rinsert(int value, Node *root)
{
   if (root == nullptr)
   {
      root = new Node(value);
   }
   else if (value > root->getData())
   {
      if (root->getRight() == nullptr)
      {
         return root->setRight(new Node(value));
      }
      else
      {
         return rinsert(value, root->getRight());
      }
   }
   else if (value < root->getData())
   {
      if (root->getLeft() == nullptr)
      {
         return root->setLeft(new Node(value));
      }
      else
      {
         return rinsert(value, root->getLeft());
      }
   }
}

/**
 * Removes a given value from this Tree
 *
 * @param value  The value to remove
 * */
void BSTree::remove(int value)
{
   remove(value, nullptr);
}

void BSTree::remove(int value, Node *trailer)
{
   // root
   if (trailer == nullptr)
   {
      // root is value to delete
      if (root->getData() == value)
      {
         // no child
         if (root->getLeft() == nullptr && root->getRight() == nullptr)
         {
            delete root;
            root = nullptr;
         }
         // has only a left child
         else if (root->getLeft() != nullptr && root->getRight() == nullptr)
         {
            Node *newRoot = root->getLeft();
            delete root;
            root = newRoot;
         }
         // has only a right child
         else if (root->getRight() != nullptr && root->getLeft() == nullptr)
         {
            Node *newRoot = root->getRight();
            delete root;
            root = newRoot;
         }
         // has 2 children
         else if (root->getLeft() != nullptr && root->getRight() != nullptr)
         {
            // get smallest
            Node *walker = root->getRight();

            while (walker->getLeft() != nullptr)
            {
               walker = walker->getLeft();
            }

            // copy
            root->setData(walker->getData());

            // delete dupe
            remove(walker->getData(), root);
         }
      }
      else
      {
         remove(value, root);
      }
   }

   // child is value to delete
   else if (trailer->getLeft() != nullptr && trailer->getLeft()->getData() == value)
   {
      Node *toDelete = trailer->getLeft();

      // no child or one left child
      if ((toDelete->getLeft() != nullptr && toDelete->getRight() == nullptr) || (toDelete->getLeft() == nullptr && toDelete->getRight() == nullptr))
      {
         trailer->setLeft(toDelete->getLeft());
         delete toDelete;
      }
      // one right child
      else if (toDelete->getRight() != nullptr && toDelete->getLeft() == nullptr)
      {
         trailer->setLeft(toDelete->getRight());
         delete toDelete;
      }
      // two children
      else if (toDelete->getLeft() != nullptr && toDelete->getRight() != nullptr)
      {
         // get smallest
         Node *walker = toDelete->getRight();

         while (walker->getLeft() != nullptr)
         {
            walker = walker->getLeft();
         }

         // copy
         toDelete->setData(walker->getData());

         // delete dupe
         remove(walker->getData(), toDelete);
      }
   }
   else if (trailer->getRight() != nullptr && trailer->getRight()->getData() == value)
   {
      Node *toDelete = trailer->getRight();

      // no child or one left child
      if ((toDelete->getLeft() != nullptr && toDelete->getRight() == nullptr) || (toDelete->getLeft() == nullptr && toDelete->getRight() == nullptr))
      {
         trailer->setRight(toDelete->getLeft());
         delete toDelete;
      }
      // one right child
      else if (toDelete->getRight() != nullptr && toDelete->getLeft() == nullptr)
      {
         trailer->setRight(toDelete->getRight());
         delete toDelete;
      }
      // two children
      else if (toDelete->getLeft() != nullptr && toDelete->getRight() != nullptr)
      {
         // get smallest
         Node *walker = toDelete->getRight();

         while (walker->getLeft() != nullptr)
         {
            walker = walker->getLeft();
         }

         // copy
         toDelete->setData(walker->getData());

         // delete dupe
         remove(walker->getData(), toDelete);
      }
   }
   else if (value >= trailer->getData() && trailer->getRight() != nullptr)
   {
      remove(value, trailer->getRight());
   }
   else if (value < trailer->getData() && trailer->getLeft() != nullptr)
   {
      remove(value, trailer->getLeft());
   }
   else if (trailer->getData() != value && trailer->getLeft() == nullptr && trailer->getRight() == nullptr)
   {
      throw NODE_NOT_FOUND;
   }
}

/**
 * @brief Counts the number of leaves on this Tree
 *
 * @return int Number of leaves
 */
int BSTree::countLeaves()
{
   return countLeaves(root);
}

int BSTree::countLeaves(Node *root)
{
   if (root == nullptr)
   {
      return 0;
   }

   if (root->getLeft() == nullptr && root->getRight() == nullptr)
   {
      return 1;
   }

   return countLeaves(root->getLeft()) + countLeaves(root->getRight());
}

/**
 * @brief Gets the height of this BSTree
 *
 * @return int Height of tree
 */
int BSTree::getHeight()
{
   return getHeight(root);
}

int BSTree::getHeight(Node *root)
{
   if (root == nullptr)
   {
      return 0;
   }

   int leftHeight = getHeight(root->getLeft());
   int rightHeight = getHeight(root->getRight());

   return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

/**
 * @brief Determines if 2 values are cousins
 *
 * @param a The first value
 * @param b The second value
 * @return true If the 2 values are cousins
 * @return false If the 2 values are not cousins
 */
bool BSTree::areCousins(int a, int b)
{
   int aLevel = levelFound(a, root, 1);
   int bLevel = levelFound(b, root, 1);

   if (aLevel == -1 || bLevel == -1)
   {
      throw NODE_NOT_FOUND;
   }

   return aLevel == bLevel;
}

int BSTree::levelFound(int value, Node *root, int currentLevel)
{
   if (root == nullptr)
   {
      return -1;
   }

   if (root->getData() == value)
   {
      return currentLevel;
   }

   int leftLevel = levelFound(value, root->getLeft(), currentLevel + 1);
   int rightLevel = levelFound(value, root->getRight(), currentLevel + 1);

   return (leftLevel != -1) ? leftLevel : rightLevel;
}