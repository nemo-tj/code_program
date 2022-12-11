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
      
    private:
      LinkNode<T> *pHead;
  };

} // end nemo namespace
