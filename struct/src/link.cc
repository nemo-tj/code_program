#include <iostream>

#include "typedef.h"
#include "link.h"

namespace nemo {
  
  template <class T>
    Link<T>::Link() {
      std::cout << "Creating Link default " << std::endl;
      pHead = nullptr;
    }

  template <class T>
    Link<T>::~Link() {
      std::cout << "Destroy Link: ";
      while (nullptr != pHead) {
        LinkNode<T> *cur = pHead;
        pHead = pHead->next;
        std::cout << *cur << " " ;
        delete cur;
      }
      std::cout << std::endl;
    }

  template <class T>
    Link<T>::Link(const std::vector<T> &vec) {
      if (vec.empty()) return;
      pHead = new LinkNode<T>(vec.at(0));
      LinkNode<T> *cur = pHead;
      for (uint32 ix = 1; ix < vec.size(); ++ix) {
        cur->next = new LinkNode<T>(vec[ix]);
        cur = cur->next;
      }
    }

  template <class T>
    LinkNode<T>* Link<T>::reverseR(LinkNode<T> *head) {
      if (nullptr == head) return nullptr;
      if (nullptr == head->next) return head;
      LinkNode<T> *pre = head->next;
      LinkNode<T> *r = this->reverseR(head->next);
      pre->next = head;
      head->next = nullptr;
      pHead = r;
      return r;
    }
  
  template <class T>
    LinkNode<T>* Link<T>::reverse(LinkNode<T> *head) {
      LinkNode<T> *cur = nullptr;
      while (nullptr != head) {
        LinkNode<T> *t = head;
        head = head->next;
        t->next = cur;
        cur = t;
      }
      pHead = cur;
      return cur;
    }

  template <class T>
    void Link<T>::display(LinkNode<T> *head) {
      std::cout << "link: ";
      if (nullptr == head) return;
      while (nullptr != head) {
        std::cout << *head << " ";
        head = head->next;
      }
      std::cout << std::endl;
    }


  // ===============
  // instantialize: explicitly declare
  #define _EXPLICIT_DEFINE(CT) template class Link<CT>
  _EXPLICIT_DEFINE(char);
  _EXPLICIT_DEFINE(int);
  _EXPLICIT_DEFINE(float);
  _EXPLICIT_DEFINE(double);
  #undef _EXPLICIT_DEFINE


} // end nemo namespace
