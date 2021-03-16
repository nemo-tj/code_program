#pragma once
#include "comp/common.h"

namespace nemo {
  template <class T>
  struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(const T &v) {
      val = v;
      left = nullptr;
      right = nullptr;
    }
    bool operator <(const TreeNode<T> &node) const {
      return this->val < node.val;
    }
  };

  template <class T>
  class BiTree {
    public:
      BiTree() {noot = nullptr;}
      BiTree(const std::vector<T> &vec);
      ~BiTree();
    public:
      void Init(const std::vector<T> &vec);
      void Display(TreeNode<T> *root);
      void DisplayK(TreeNode<T> *root, int k);
      int Level(TreeNode<T> *root);
      T SumTree(TreeNode<T> *root);
      TreeNode<T>* Mirror(TreeNode<T> *root);
      TreeNode<T> *GetRoot();
    public:
      void RPreVisit(TreeNode<T> *root);
      void PreVisit(TreeNode<T> *root);
      void RMidVisit(TreeNode<T> *root);
      void MidVisit(TreeNode<T> *root);
      void RPostVisit(TreeNode<T> *root);
      void PostVisit(TreeNode<T> *root);
      void PostVisitV2(TreeNode<T> *root);
    private:
      TreeNode<T> *noot;
  }; // class BiTree

} // end nemo
