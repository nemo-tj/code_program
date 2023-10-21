#pragma once

#include <glog/logging.h>


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
      inline bool operator< (const Node<T> &node) const {
        return this->val < node.val;
      }
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
    struct BTNode : public Node<T> {
      BTNode<T> *left;
      BTNode<T> *right;

      BTNode(const T &v): Node<T>(v) {}

      BTNode(const BTNode<T> *btn) {
        this->val = btn->val;
      }

    };

} // end namespace nemo
