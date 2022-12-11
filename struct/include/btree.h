#pragma once

#include "node.h"
#include "typedef.h"

namespace nemo {

  template <class T>
    class BTree {
      public:
        BTree(); 
        BTree(const std::vector<T> &vec);
        ~BTree();

      public:
        void display(BTreeNode<T> *rt);
        void preVisit(BTreeNode<T> *rt);
        void preV(BTreeNode<T> *rt);
        void midVisit(BTreeNode<T> *rt);
        void midV(BTreeNode<T> *rt);
        void postVisit(BTreeNode<T> *rt);
        void postV(BTreeNode<T> *rt);
        void postV1(BTreeNode<T> *rt);

      public:
        int depth(BTreeNode<T> *rt);
        void displayK(BTreeNode<T> *rt, int k);

      public:
        inline BTreeNode<T> *getRoot() { return root; }
      private:
        BTreeNode<T> *root;
    };

} // end nemo namespace
