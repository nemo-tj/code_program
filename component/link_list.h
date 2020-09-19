#pragma once

#include "component/common.h"

namespace nemo {

  template <class T>
  struct Node {
   T val;
   Node * next;
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
  Node<T>* q = head->next;
  Node<T>* r = Reverser(q);
  q->next = head;
  return r;
}


template <class T>
Node<T> *LinkList<T>::TailK(Node<T> *head, int k) {
  Node<T> *front = head;
  Node<T> *back = head;
  int step = 0;
  while ( step < k && front != nullptr) {
    front = front->next;
    ++step;
  }
  if (step < k && front == nullptr) return nullptr;
  while (front != nullptr) {
    front = front->next;
    back = back->next;
  }
  return back;
}

} // namespace nemo
