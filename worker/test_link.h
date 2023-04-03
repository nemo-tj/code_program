#pragma once

#include "link.h"

#include "common.h"
#include "util.h"
#include "typedef.h"

using namespace nemo;


void test_link() {
  std::vector<int> vec = {4, 5, 2, 1, 3, 4, 7, 9, 8};
  std::cout << "vec: ";
  display(vec);
  Link<int> linker(vec);
  LinkNode<int> *head = linker.getHead();
  linker.display(head);
  head = linker.reverseR(head);
  linker.display(head);
  head = linker.reverse(head);
  linker.display(head);
  for (int i = 1; i < vec.size() + 4; ++i) {
    LinkNode<int> *cur= linker.lastKth(head, i);
    if (nullptr == cur) break;
    std::cout << *cur << ", ";
  }
  LINE;
  // head = linker.pairRev(head);
  linker.display(head);
  std::cout << std::endl;
  head = linker.pairReve(head);
  linker.display(head);
  std::cout << std::endl;
  
}


