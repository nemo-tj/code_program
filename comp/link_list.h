#pragma once

#include "comp/common.h"

namespace nemo {

  template <class T>
  struct Node {
   T val;
   Node * next;
   Node() { next = nullptr;}
   bool operator <(const Node<T> &node) const {
     return val < node.val;
   }
  };

  template <class T>
  class LinkList {
    public:
      LinkList();
      LinkList(const std::vector<T> &vec);
      ~LinkList();
      Node<T>* GetHead() {return head;}
      void Display(const Node<T>* head);
      void Display();
    public:
      Node<T>* Reverse(Node<T> *head);
      Node<T>* Reverser(Node<T> *head);
      Node<T>* TailK(Node<T> *head, int k);
    public:
      Node<T>* Sort(Node<T> *header);
      Node<T>* BubSort(Node<T> *header);
      Node<T> *QSort(Node<T> *header);
      Node<T> *QSortDivide(Node<T> *begin, Node<T> *ender, Node<T> **cap);
    
    private:
      Node<T> *Init(const std::vector<T> &vec);
    private:
      Node<T> *head;
  };
// END OF DEFINITION

template <class T>
LinkList<T>::LinkList() {
  head = nullptr;
}

template <class T>
LinkList<T>::~LinkList() {
  std::cout << "Destroying ..." << std::endl;
  while (head != nullptr) {
    Node<T> *p = head->next;
    delete head;
    head = nullptr;
    head = p;
  }
}

template <class T>
LinkList<T>::LinkList(const std::vector<T> &vec) {
  Init(vec);
  return;
  if (vec.empty()) { head = nullptr; return;}
  head = new Node<T>;
  head->val = vec.at(0);
  Node<T> *p = head;
  auto it = vec.begin() + 1;
  while ( it != vec.end() ) {
    Node<T> *q = new Node<T>;
    q->val = *it;
    ++it;
    p->next= q;
    p = q;
  }
  p->next = nullptr;
}

template <class T>
Node<T>* LinkList<T>::Init(const std::vector<T> &vec) {
  head = nullptr;
  Node<T> * pre = nullptr;
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (head == nullptr) {
      head = new Node<T>;
      head->val = *it;
      pre = head;
    } else {
      Node<T> * cur = new Node<T>;
      cur->val = *it;
      pre->next = cur;
      pre = cur;
    }
  }
  pre->next = nullptr;
  return head;
}

template <class T>
void LinkList<T>::Display(const Node<T> *head) {
  if (head == nullptr) { 
    std::cout << std::endl; 
    return;
  }
  std::cout << head->val << " ";
  Display(head->next);
}

template <class T>
void LinkList<T>::Display() {
  Node<T>* head = GetHead();
  Display(head);
}

template <class T>
Node<T>* LinkList<T>::Reverse(Node<T> *head) {
  Node<T> * phead = nullptr;;
  while (head != nullptr) {
    Node<T> *p = head;
    head = p->next;
    p->next = phead;
    phead = p;
  }
  return phead;
}

template <class T>
Node<T>* LinkList<T>::Reverser(Node<T> *head) {
  if (head == nullptr) return head;
  if (head->next == nullptr) return head;
  Node<T> *hnext = head->next;
  // head -> hnext ; phead -> ... ->hnext
  Node<T> *phead = Reverser(hnext);
  // phead -> ... ->hnext -> head -> hnext
  hnext->next = head;
  // phead -> ... ->hnext -> head -> nullptr
  head->next = nullptr; 
  return phead;
}

// Bub sort
template <class T>
Node<T> *LinkList<T>::BubSort(Node<T> *header) {
  if (header == nullptr) return nullptr;
  Node<T> *top = nullptr;
  while (header->next != top) {
    Node<T> *in = header;
    while (in->next != top) {
      if (*in < *(in->next)) {
        swap_val(in->val, in->next->val);
      }
      in = in->next;
    }
    top = in;
  }
  return header;
}

// Insert sort
template <class T>
Node<T> *LinkList<T>::Sort(Node<T> *header) {
  if (header == nullptr) return nullptr;
  if (header->next == nullptr) return  header;
  Node<T> *pre = header;
  Node<T> *cur = header->next;
  while (cur != nullptr) {
    bool is_head = true;
    Node<T> *tmp = header;
    while(tmp != cur) {
      if (is_head) {
        if (*cur < *tmp) {
          pre->next = cur->next;
          cur->next = header;
          header = cur;
          cur = pre->next;
          break;
        }
        is_head = false;
      } else {
        if (*cur < *(tmp->next)) {
          pre->next = cur->next;
          cur->next = tmp->next;
          tmp->next = cur;
          cur = pre->next;
          break;
        } else {
          tmp = tmp->next;
        }
      }
    }
    // Display(header);
    if (tmp == cur) {
      pre = pre->next;
      cur = pre->next;
    }
  }
  return header;
}

template <class T>
Node<T>* LinkList<T>::QSort(Node<T> *header) {
  Node<T> *pcur = QSortDivide(header, nullptr, &header);
  QSortDivide(header, pcur, &header);
  QSortDivide(pcur, nullptr, nullptr);
  return header;
}

template <class T>
Node<T>* LinkList<T>::QSortDivide(Node<T> *header, Node<T> *tail, Node<T> ** cap) {
  if (header == tail) return header;
  Node<T> *key = header;
  Node<T> *left = header; 
  Node<T> *pre = header;
  Node<T> *right = header->next;
  while (right != tail) {
    if (*right < *key) {
      pre->next = right->next;
      right->next = left;
      left = right;
      right = pre->next;
    } else {
      right = right->next;
      pre = pre->next;
    }
  }
  if (cap != nullptr) *cap = left;
  return key;
}

template <class T>
Node<T> *LinkList<T>::TailK(Node<T> *head, int k) {
  Node<T> *front = head;
  Node<T> *back = front;
  for (int i = 0; i < k; ++i) {
    if (front == nullptr) return nullptr;
    front = front->next;
  }
  while (front != nullptr) {
   front = front->next;
   back = back->next;
  }
  return back;
}

} // namespace nemo
