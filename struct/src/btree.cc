#include "btree.h"
#include <deque>
#include <stack>

namespace nemo {

  template <class T>
    BTree<T>::BTree() {
    }

  template <class T>
    BTree<T>::BTree(const std::vector<T> &vec) {
      if (vec.empty()) return;
      std::deque<BTNode<T>*> Q;
      uint32 x = 0;
      root = new BTNode<T>(vec[x]);
      Q.push_back(root);
      x += 1;
      while (true) {
        BTNode<T> *cur = Q.front();
        if (x < vec.size()) {
          cur->left = new BTNode<T>(vec[x++]);
          Q.push_back(cur->left);
        }
        if (x < vec.size()) {
          cur->right = new BTNode<T>(vec[x++]);
          Q.push_back(cur->right);
        }
        Q.pop_front();
        if (x >= vec.size()) {
          break;
        }
      }
    }
  
  template <class T>
    BTree<T>::~BTree() {
      if (nullptr == root) return;
      std::deque<BTNode<T> *> Q;
      Q.push_back(root);
      while (!Q.empty()) {
        BTNode<T> *cur = Q.front();
        if (nullptr != cur->left) Q.push_back(cur->left);
        if (nullptr != cur->right)Q.push_back(cur->right);
        Q.pop_front();
        delete cur;
      }
    }
  
  template <class T>
    void BTree<T>::postVisit(BTNode<T> *rt) {
      if (nullptr == rt) return;
      postVisit(rt->left);
      postVisit(rt->right);
      std::cout << *rt << " ";
    }

  template <class T>
    void BTree<T>::midVisit(BTNode<T> *rt) {
      if (nullptr == rt) return;
      midVisit(rt->left);
      std::cout << *rt << " ";
      midVisit(rt->right);
    }

  template <class T>
    void BTree<T>::preVisit(BTNode<T> *rt) {
      if (nullptr == rt) return;
      std::cout << *rt << " ";
      preVisit(rt->left);
      preVisit(rt->right);
    }

  template <class T>
    void BTree<T>::postV1(BTNode<T> *rt) {
      if (nullptr == rt) return;
      std::stack<BTNode<T> *> ST;
      std::stack<BTNode<T> *> R;
      BTNode<T> *cur = rt;
      while (true) {
        while (nullptr != cur) {
          ST.push(cur);
          R.push(cur);
          cur = cur->right;
        }
        if (!ST.empty()) {
          cur = ST.top()->left;
          ST.pop();
        }
        if (ST.empty() && nullptr == cur) break;
      }
      while (!R.empty()) {
        std::cout << *R.top() << " ";
        R.pop();
      }
      std::cout << std::endl;
    }

  template <class T>
    void BTree<T>::postV(BTNode<T> *rt) {
      if (nullptr == rt) return;
      std::deque<BTNode<T> *> Q;
      BTNode<T> *last = nullptr;
      BTNode<T> *cur = rt;
      while (true) {
        while (nullptr != cur) {
          Q.push_back(cur);
          cur = cur->left;
        }
        if (!Q.empty()) {
          cur = Q.back();
          if (nullptr == cur->right || cur->right == last) {
            std::cout << *cur << " ";
            last = cur;
            Q.pop_back();
            cur = nullptr;
          } else {
            cur = cur->right;
          }
        }
        if (Q.empty() && nullptr == cur) break;
      }
      std::cout << std::endl;
    }

  template <class T>
    void BTree<T>::midV(BTNode<T> *rt) {
      if (nullptr == rt) return;
      BTNode<T> *cur = rt;
      std::deque<BTNode<T> *> Q;
      while (true) {
        while (nullptr != cur) {
          Q.push_back(cur);
          cur = cur->left;
        }
        if (!Q.empty()) {
          BTNode<T> *t = Q.back();
          std::cout << *t << " ";
          Q.pop_back();
          cur = t->right;
        }
        if (Q.empty() && cur == nullptr) {
          break;
        }
      }
      std::cout << std::endl;
    }

  template <class T>
    void BTree<T>::preV(BTNode<T> *rt) {
      if (nullptr == rt) return;
      BTNode<T> *cur = rt;
      std::deque<BTNode<T> *> ST;
      while (true) {
        while (nullptr != cur) {
          std::cout << *cur << " ";
          ST.push_back(cur);
          cur = cur->left;
        }
        if (!ST.empty()) {
          BTNode<T> *t = ST.back();
          cur = t->right;
          ST.pop_back();
        }
        if (ST.empty() && nullptr == cur) {
          break;
        }
      }
      std::cout << std::endl;
    }


  template <class T>
    void BTree<T>::display(BTNode<T> *rt) {
      if (nullptr == rt) return;
      std::deque<BTNode<T> *> V;
      V.push_back(rt);
      while (true) {
        int sz = V.size();
        for (int i = 0; i < sz; ++i) {
          BTNode<T> *cur = V.front();
          std::cout << *cur << " ";
          if (nullptr != cur->left)  V.push_back(cur->left);
          if (nullptr != cur->right) V.push_back(cur->right);
          V.pop_front();
        }
        std::cout << std::endl;
        if (V.empty()) break;
      }
      std::cout << std::endl;
    }

  template <class T>
    int BTree<T>::depth(BTNode<T> *rt) {
      if (nullptr == rt) return 0;
      return 1 + std::max(depth(rt->left), depth(rt->right));
    }

  template <class T>
    void BTree<T>::displayK(BTNode<T> *rt, int k) {
      if (nullptr == rt) return;
      if (0 == k) std::cout << *rt << " ";
      displayK(rt->left, k-1);
      displayK(rt->right, k-1);
    }

  template <class T>
    int BTree<T>::sumNode(BTNode<T> *rt) {
      if (nullptr == rt) return 0;
      return rt->val + sumNode(rt->left) + sumNode(rt->right);
    }

  template <class T>
    void BTree<T>::mirror(BTNode<T> *rt) {
      if (nullptr == rt) return;
      BTNode<T> *cur = rt->left;
      rt->left = rt->right;
      rt->right = cur;
      mirror(rt->left);
      mirror(rt->right);
    }



  // ===============
  // instantialize: explicitly declare
  #define _EXPLICIT_DEFINE(CT) template class BTree<CT>
  _EXPLICIT_DEFINE(char);
  _EXPLICIT_DEFINE(int);
  _EXPLICIT_DEFINE(float);
  _EXPLICIT_DEFINE(double);
  #undef _EXPLICIT_DEFINE

}
