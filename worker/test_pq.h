#pragma once

#include "priority_queue.h"
#include "util.h"

using namespace nemo;

void test_pq()
{
  INFO("test_pq");
  std::vector<int> vec = {4, 5, 2, 1, 3, 4, 7, 9, 6};
  std::cout << "vec: ";
  display<int>(vec);
  PQ<int> pq(vec);
  std::cout << "sh : ";
  pq.show(); // skip top 1

  pq.order();
  std::cout << "pq : ";
  display<int>(pq.getPQ());
  std::cout << "sht: ";
  pq.show();
  LINE;
  std::vector<int> v = {5, 5, 12, 1, 3, 4, 7, 9};
  std::cout << "vec: ";
  display(v);
  LINE;
  // sort v and cut head
  pq.sort(v);
  display(v);
  v = std::vector<int>(v.begin()+1, v.end());
  std::cout << "srt: ";
  display<int>(v);
  LINE;
  // v
  pq.sort(v, v.size());
  std::cout << "srt: ";
  display<int>(std::vector<int>(v.begin()+1, v.end()));
  LINE;
  INFO("destroy");
}


