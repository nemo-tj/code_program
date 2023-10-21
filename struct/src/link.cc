#include <iostream>

#include "typedef.h"
#include "link.h"

namespace nemo {
  
  template <class T>
    Link<T>::Link() {
      LOG(INFO) << "Creating Link default ";
      pHead = nullptr;
    }

  template <class T>
    Link<T>::~Link() {
			std::string LOG_STR = "Destroy Link: ";
      while (nullptr != pHead) {
        LinkNode<T> *cur = pHead;
        pHead = pHead->next;
				LOG_STR += to_string(*cur) + " ";
        delete cur;
      }
			LOG(INFO) << LOG_STR;
    }

  template <class T>
    Link<T>::Link(const std::vector<T> &vec) {
      if (vec.empty()) return;
			std::string log_str = "Creating Link default ";
			log_str += to_string(vec.at(0)) + " ";
      pHead = new LinkNode<T>(vec.at(0));
      LinkNode<T> *cur = pHead;
      for (uint32 ix = 1; ix < vec.size(); ++ix) {
				log_str += to_string(vec[ix]) + " ";
        cur->next = new LinkNode<T>(vec[ix]);
        cur = cur->next;
      }
			cur->next = nullptr;
			LOG(INFO) << log_str;
    }

  template <class T>
    LinkNode<T>* Link<T>::reverseR(LinkNode<T> *head) {
			LOG(INFO) << "reverseR";
      if (nullptr == head || nullptr == head->next) return head;
      LinkNode<T> *pre = head->next;
      LinkNode<T> *r = this->reverseR(head->next);
      pre->next = head;
      head->next = nullptr;
			// 
      pHead = r;
      return r;
    }
  
  template <class T>
    LinkNode<T>* Link<T>::reverse(LinkNode<T> *head) {
			LOG(INFO) << "reverse";
      if (nullptr == head || nullptr == head->next) return head;
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
			std::string LOG_STR = "link: ";
      if (nullptr == head) return;
      while (nullptr != head) {
        LOG_STR += to_string(*head) + " ";
        head = head->next;
      }
			LOG(INFO) << LOG_STR;
    }

  template <class T>
    LinkNode<T>* Link<T>::lastKth(LinkNode<T> *head, int k) {
			LOG(INFO) << "last k th";
      LinkNode<T> *fast = head;
      LinkNode<T> *slow = head;
      while (k > 0 && fast != nullptr) {
        fast = fast->next;
        --k;
      }
      while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
      }
      if (k > 0) return nullptr; // link length is shorter than `k`
      return slow;
    }

  template <class T>
    LinkNode<T>* Link<T>::pairRev(LinkNode<T> *head) {
			LOG(INFO) << "pairRev";
      if (nullptr == head) return head;
      if (nullptr == head->next) return head;
      LinkNode<T> *p1 = head, *p2 = head->next;
      LinkNode<T> *p = p2->next;
      p2->next = p1;
      p1->next = pairRev(p);
      pHead = p2;
      return p2;
    }

  template <class T>
    LinkNode<T>* Link<T>::pairReve(LinkNode<T> *head) {
			LOG(INFO) << "pairReve";
      if (nullptr == head) return head;
      if (nullptr == head->next) return head;
      LinkNode<T>* p1 = head; 
      LinkNode<T>* p2 = p1->next;
      LinkNode<T>* p3 = p2->next;
      LinkNode<T>* phead = p2;
      p1->next = p3;
      p2->next = p1;
      while (nullptr != p3 && nullptr != p3->next) {
        LinkNode<T> *pre = p1;
        p1 = p3;
        p2 = p1->next;
        p3 = p2->next;
        p1->next = p3;
        p2->next = p1;
        pre->next = p2;
      }
      pHead = phead;
      return phead;
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
