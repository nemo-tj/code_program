#pragma once

#include "node.h"

#include <vector>

namespace nemo {

  template <class T>
  class Link {
    public:
      Link();
      ~Link();
      Link(const std::vector<T> &vec);
    public:
      void display(LinkNode<T> *head);
      inline LinkNode<T> *getHead() { return pHead; }
      LinkNode<T>* reverse(LinkNode<T> *head);
      LinkNode<T>* reverseR(LinkNode<T> *head);
      LinkNode<T>* pairRev(LinkNode<T> *head);
      LinkNode<T>* pairReve(LinkNode<T> *head);
      LinkNode<T>* lastKth(LinkNode<T> *head, int k);
      
    private:
      LinkNode<T> *pHead;
  };

} // end nemo namespace
