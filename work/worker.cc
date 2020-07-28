#include "work/worker.h"
#include "comp/base.h"

namespace nemo {
  namespace leetcode{

int run_link_list(){
  // build list
  std::vector<int> vec = {1,3,8,2,5};
  show_vec(vec);
  LinkList<int> link(vec);
  // show
  Node<int> *head = link.GetHead();
  link.Display(head);
  // reverse
  head = link.Reverse(head);
  link.Display(head);
  // taik `K`
  int k = 2;
  Node<int>* tailk = link.TailK(head, k);
  if (tailk == nullptr) {
    std::cout << "nullptr: " << k << std::endl;
  } else {
    std::cout << "tail K: "<< tailk->val << std::endl;
  }
  return 0;
}


int run_priority_heap() {
  // build list
  std::vector<int> vec = {1,3,8,2,2,5};
  show_vec(vec);
  PriorityHeap<int> ph(vec);
  std::vector<int> v;
  // ph.sort(v);
  show_vec(v);
  // push, pop
  PriorityHeap<int> pq;
  pq.push(4);
  pq.push(2);
  pq.push(2);
  pq.push(-8);
  pq.push(1);
  pq.sort(v);
  show_vec(v);
  /*
  */

  return 0;
}

int run_sorter() {
  std::cout << "sorter ..." << std::endl;

  Sorter<int> st;
  std::vector<int> vec = {1,2,4,3,8,2,5};
  show_vec(vec);
  // st.bub_sort(vec);
  // st.quick_sort(vec);
  st.merge_sort(vec);

  return 0;
}

} // namespace leetcode
} // namespace nemo
