#pragma once

#include "link.h"
#include "btree.h"
#include "sorter.h"

#include "perm.h"

#include "util.h"
#include "node.h"

using namespace nemo;

template <class T>
void display_btree(BTree<T>& tree) {
  BTNode<T>* rt = tree.getRoot();
  int depth = tree.depth(rt);
  for (int i = 0; i < depth; ++i) {
    tree.displayK(rt, i);
    std::cout << std::endl;
  }
}

void test_struct()
{
  std::vector<int> vec = {4, 5, 2, 1, 3, 4, 7, 9, 2, 3, 4, 56, 7, 1, 6, 2 ,3};
  Link<int> linker(vec);
  INFO("btree-pre");
  BTree<int> btree(vec);
  btree.preV(btree.getRoot());
  btree.preVisit(btree.getRoot());
  INFO("btree-mid");
  btree.midV(btree.getRoot());
  btree.midVisit(btree.getRoot());
  INFO("btree-post");
  btree.postV1(btree.getRoot());
  btree.postV(btree.getRoot());
  btree.postVisit(btree.getRoot());
  LINE;
  BTNode<int> *rt = btree.getRoot();
  btree.displayK(rt, 1);
  std::cout << std::endl;
  btree.displayK(rt, 2);
  std::cout << std::endl;
  btree.displayK(rt, 3);
  std::cout << std::endl;
  LINE;
  std::cout << "depth:" << btree.depth(rt) << std::endl;
  INFO("Tree sum node value");
  std::cout << btree.sumNode(rt) << std::endl;
  LINE;
  display_btree<int>(btree);
  INFO("TREE");
  btree.mirror(rt);
  btree.display(btree.getRoot());
  INFO("destroy");
}


