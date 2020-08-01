#include "work/worker.h"
#include "comp/base.h"

namespace nemo {
  namespace leetcode{

int Runner::run_link_list(){
  std::cout << "link_list : " << std::endl;
  // build list
  std::vector<int> vec = {1,3,8,2,5};
  show_vec(vec);
  LinkList<int> link(vec);
  // show
  std::cout << "show : " << std::endl;
  Node<int> *head = link.GetHead();
  link.Display(head);
  // reverse
  std::cout << "reverse : " << std::endl;
  // head = link.Reverse(head);
  Node<int> *phead = link.Reverser(head);
  head->next = nullptr;
  head = phead;
  link.Display(head);
  // taik `K`
  std::cout << "tailK : " << std::endl;
  int k = 2;
  Node<int>* tailk = link.TailK(head, k);
  if (tailk == nullptr) {
    std::cout << "nullptr: " << k << std::endl;
  } else {
    std::cout << "K= "<< k << ", val=" << tailk->val << std::endl;
  }
  std::cout << "-------------" << std::endl;
  return 0;
}


int Runner::run_priority_heap() {
  std::cout << ("priority_heap") << std::endl;
  // build list
  std::vector<int> vec = {1,3,8,2,2,5};
  show_vec(vec);
  PriorityHeap<int> ph(vec);
  std::vector<int> v;
  ph.sort(v);
  show_vec(v);
  std::cout << "end ph" << std::endl;
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

  std::cout << "-------------" << std::endl;
  return 0;
}

int Runner::run_sorter() {
  std::cout << "sorter ..." << std::endl;

  Sorter<int> st;
  std::vector<int> vec = {1,2,4,3,8,2,5};
  show_vec(vec);
  // st.bub_sort(vec);
  // st.quick_sort(vec);
  st.merge_sort(vec);

  std::cout << "-------------" << std::endl;
  return 0;
}

} // namespace leetcode
} // namespace nemo
