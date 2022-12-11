#pragma once

namespace nemo {
  template <typename T>
    struct Node {
      T val;
      Node() {};
      Node(const Node<T> &node) {
        this->val = node.val;
      }
      Node(const T &val) {
        this->val = val;
      }
      inline operator T() { return val; }
    };

  template <typename T>
    struct LinkNode : public Node<T> {
      LinkNode<T> *next;

      LinkNode() {}

      // LinkNode(const LinkNode<T> *ln) {
      //   this->val = ln->val;
      // }

      LinkNode(const T &v): Node<T>(v) {}

    };

  template <typename T>
    struct BTreeNode : public Node<T> {
      BTreeNode<T> *left;
      BTreeNode<T> *right;

      BTreeNode(const T &v): Node<T>(v) {}

      BTreeNode(const BTreeNode<T> *btn) {
        this->val = btn->val;
      }

    };

} // end namespace nemo
