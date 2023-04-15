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
        void display(BTNode<T> *rt);
        void preVisit(BTNode<T> *rt);
        void preV(BTNode<T> *rt);
        void midVisit(BTNode<T> *rt);
        void midV(BTNode<T> *rt);
        void postVisit(BTNode<T> *rt);
        void postV(BTNode<T> *rt);
        void postV1(BTNode<T> *rt);

      public:
        void mirror(BTNode<T> *rt);
        int depth(BTNode<T> *rt);
        void displayK(BTNode<T> *rt, int k);
        int sumNode(BTNode<T> *rt);

      public:
        inline BTNode<T> *getRoot() { return root; }
      private:
        BTNode<T> *root;
    };

} // end nemo namespace
