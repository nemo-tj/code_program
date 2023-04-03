#pragma once

#include "link.h"
#include "btree.h"
#include "sorter.h"

#include "perm.h"

#include "util.h"
#include "node.h"

using namespace nemo;

void test_struct()
{
  std::vector<int> vec = {4, 5, 2, 1, 3, 4, 7, 9};
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
  BTreeNode<int> *rt = btree.getRoot();
  btree.displayK(rt, 1);
  std::cout << std::endl;
  btree.displayK(rt, 2);
  std::cout << std::endl;
  btree.displayK(rt, 3);
  std::cout << std::endl;
  std::cout << "depth:" << btree.depth(rt) << std::endl;
  INFO("TREE");
  btree.display(btree.getRoot());
  INFO("destroy");
}


