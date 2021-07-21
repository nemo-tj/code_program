#include "comp/tree.h"
#include <deque>

namespace nemo {

  template <class T>
  void BiTree<T>::Init(const std::vector<T> &vec) {
    if (vec.empty()) { noot = nullptr; return;}
    std::deque<TreeNode<T>*> Q;
    auto it = vec.begin();
    noot = new TreeNode<T>(*it);
    Q.push_back(noot);
    while (true) {
      TreeNode<T> *cur = Q.front();
      if (++it != vec.end()) {
        cur->left = new TreeNode<T>(*it);
        Q.push_back(cur->left);
      }
      if (it == vec.end()) {
        break;
      }
      if (++it != vec.end()) {
        cur->right = new TreeNode<T>(*it);
        Q.push_back(cur->right);
      }
      if (it == vec.end()) {
        break;
      }
      //std::cout << "val=" << *it << " Q.size=" << Q.size() << std::endl;
      if (!Q.empty()) {
        Q.pop_front();
      }
    }
    Q.clear();
  }
  template <class T>
  BiTree<T>::BiTree(const std::vector<T> &vec) {
    if (vec.empty()) {noot = nullptr; return;}
    auto it = vec.begin();
    noot = new TreeNode<T>(*it);
    std::deque<TreeNode<T>*> Q;
    Q.push_back(noot);
    while (true) {
      TreeNode<T> *cur = Q.front();
      if (++it != vec.end()) {
        cur->left = new TreeNode<T>(*it);
        Q.push_back(cur->left);
      } else {
        break;
      }
      if (++it != vec.end()) {
        cur->right = new TreeNode<T>(*it);
        Q.push_back(cur->right);
      } else {
        break;
      }
      if (!Q.empty()) { Q.pop_front(); }
    }
    while (!Q.empty()) Q.pop_front();
  }

  template <class T>
  BiTree<T>::~BiTree() {
    std::cout << "Destroy  BiTree ..." << std::endl;
    std::deque<TreeNode<T>*> Q;
    if (noot != nullptr) {
      Q.push_back(noot);
    }
    while(!Q.empty()) {
      TreeNode<T>* p = Q.front();
      // std::cout << "val=" << p->val << " Q.size=" << Q.size() << std::endl;
      if (p->left != nullptr) Q.push_back(p->left);
      if (p->right != nullptr) Q.push_back(p->right);
      Q.pop_front();
      delete p;
    }
  }
  template <class T>
  T BiTree<T>::SumTree(TreeNode<T> *root) {
    if (root == nullptr) return 0;
    return root->val + SumTree(root->left) + SumTree(root->right);
  }

  template <class T>
  void BiTree<T>::Display(TreeNode<T> *root) {
    int sum_level = Level(root);
    std::cout << "display tree ..." << std::endl;
    for (int i = 1; i <= sum_level; ++i) {
      DisplayK(root, i);
      std::cout << std::endl;
      // std::cout << "\n----" << i << "----" << std::endl;
    }
    std::cout << "end display tree!!" << std::endl;
  }

  template <class T>
  TreeNode<T>* BiTree<T>::Mirror(TreeNode<T> *root) {
    if (root == nullptr) { return root;}
    TreeNode<T>* left = Mirror(root->left);
    TreeNode<T>* right= Mirror(root->right);
    root->left = right;
    root->right = left;
    return root;
  }

  template <class T>
  int BiTree<T>::Level(TreeNode<T>* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(Level(root->left), Level(root->right));
  }

  template <class T>
  void BiTree<T>::RPreVisit(TreeNode<T> *root) {
    if (root == nullptr) return;
    std::cout << root->val << " ";
    RPreVisit(root->left);
    RPreVisit(root->right);
  }

  template <class T>
  void BiTree<T>::PreVisit(TreeNode<T> *root) {
    if (nullptr == root) return;
    std::deque<T> R;
    std::deque<TreeNode<T>*> Q;
    TreeNode<T> *cur = root;
    while (true) {
      while (cur != nullptr) {
        R.push_back(cur->val);
        Q.push_back(cur);
        cur = cur->left;
      }
      cur = Q.back()->right;
      Q.pop_back();
      if (Q.empty() && cur == nullptr) {
        break;
      }
    }
    while (!R.empty()) {
      std::cout << R.front() << " ";
      R.pop_front();
    }
  }

  template <class T>
  void BiTree<T>::RMidVisit(TreeNode<T> *root) {
    if (root == nullptr) return;
    RMidVisit(root->left);
    std::cout << root->val << " ";
    RMidVisit(root->right);
  }

  template <class T>
  void BiTree<T>::MidVisit(TreeNode<T> *root) {
    if (root == nullptr) return;
    std::deque<T> R;
    std::deque<TreeNode<T>*> Q;
    TreeNode<T> *cur = root;
    while (true) {
      while (cur != nullptr) {
        Q.push_back(cur);
        cur = cur->left;
      } 
      cur = Q.back();
      R.push_back(cur->val);
      cur = cur->right;
      Q.pop_back();
      if (Q.empty() && cur == nullptr) {
        break;
      }
    }
    while (!R.empty()) {
      std::cout << R.front() << " ";
      R.pop_front();
    }
  }

  template <class T>
  void BiTree<T>::RPostVisit(TreeNode<T> *root) {
    if (root == nullptr) return;
    RPostVisit(root->left);
    RPostVisit(root->right);
    std::cout << root->val << " ";
  }

  template <class T>
  void BiTree<T>::PostVisit(TreeNode<T> *root) {
    if (nullptr == root) return;
    std::deque<T> R;
    std::deque<TreeNode<T>*> Q;
    TreeNode<T> *pre = nullptr;
    TreeNode<T> *cur = root;
    while (true) {
      while (nullptr != cur) {
        Q.push_back(cur);
        cur = cur->left;
      }
      cur = Q.back();
      if (nullptr == cur->right || cur->right == pre) {
        R.push_back(cur->val);
        Q.pop_back();
        pre = cur;
        cur = nullptr;
      } else {
        cur = cur->right;
      }
      if (Q.empty() && nullptr == cur) {
        break;
      }
    }
    while (!R.empty()) {
      std::cout << R.front() << " ";
      R.pop_front();
    }
  }

  // refer to PreVisit: root -> left ->right
  // previsit': root -> right ->left 
  // postvisit: left -> right ->root;
  template <class T>
  void BiTree<T>::PostVisitV2(TreeNode<T> *root) {
    if (nullptr == root) return;
    std::deque<T> R;
    std::deque<TreeNode<T>*> Q;
    TreeNode<T> *cur = root;
    while (true) {
      while (nullptr != cur) {
        R.push_back(cur->val);
        Q.push_back(cur);
        cur = cur->right;
      }
      cur = Q.back();
      Q.pop_back();
      cur = cur->left;
      if (Q.empty() && nullptr == cur) break;
    }
    while (!R.empty()) {
      std::cout << R.back() << " ";
      R.pop_back();
    }
  }

  template <class T>
  TreeNode<T>* BiTree<T>::GetRoot() {
    return noot;
  }

  template <class T>
  void BiTree<T>::DisplayK(TreeNode<T> *root, int k) {
    if (root == nullptr) return;
    if (k == 1) { std::cout << root->val << " "; return; }
    if (root->left != nullptr) DisplayK(root->left, k-1);
    if (root->right!= nullptr) DisplayK(root->right, k-1);
  }

  #define _EXPLICIT_DEFINE(CT) template class BiTree<CT>
  _EXPLICIT_DEFINE(char);
  _EXPLICIT_DEFINE(int);
  _EXPLICIT_DEFINE(float);
  _EXPLICIT_DEFINE(double);
  #undef _EXPLICIT_DEFINE
}

