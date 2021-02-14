#include "work/worker.h"
#include "comp/base.h"

namespace nemo {
  namespace leetcode{

int Runner::run_bi_tree() {
  std::cout << "link_list : " << std::endl;
  // build list
  std::vector<int> vec = {1,3,8,2,5,1,3,8,2,5,4,4,6};
  // std::vector<int> vec = {1,3,8,2};
  show_vec(vec);
  BiTree<int> bitree(vec);
  TreeNode<int> *root = bitree.GetRoot(); 
  std::cout << "level K display..." << std::endl;
  bitree.DisplayK(root, 4);
  std::cout << std::endl;
  std::cout << bitree.Level(root) << std::endl;
  bitree.Display(root);
  // root = bitree.Mirror(root);
  bitree.DisplayK(root, 4);
  std::cout << std::endl;
  bitree.Display(root);
  std::cout << " sum : " << bitree.SumTree(root) << std::endl;
  std::cout << "pre: " << std::endl;
  bitree.RPreVisit(root);
  std::cout << "\n raw pre-visit:" << std::endl;
  bitree.PreVisit(root);
  std::cout << std::endl;
  std::cout << "mid: " << std::endl;
  bitree.RMidVisit(root);
  std::cout << "\n raw mid-visit:" << std::endl;
  bitree.MidVisit(root);
  std::cout << std::endl;
  std::cout << "Post visit:" << std::endl;
  bitree.RPostVisit(root);
  std::cout << std::endl;
  std::cout << "raw post visit:" << std::endl;
  bitree.PostVisit(root);
  std::cout << std::endl;
  std::cout << "raw post visit v2:" << std::endl;
  bitree.PostVisitV2(root);
  std::cout << std::endl;
  return 0;
}

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
  head = link.Reverse(head);
  link.Display(head);
  head = link.Reverser(head);
  link.Display(head);
  std::cout << "------------------" << std::endl;
  // Insert Sort
  link.Display(head);
  std::cout << "------------------" << std::endl;
  std::cout << "insert sort: " << std::endl;
  head = link.Sort(head);
  link.Display(head);
  std::cout << "bub sort: " << std::endl;
  head = link.BubSort(head);
  link.Display(head);
  std::cout << "Q sort: " << std::endl;
  head = link.QSort(head);
  link.Display(head);
  // taik `K`
  std::cout << "tailK : " << std::endl;
  for (int k = 1; k < 8; ++k) {
    Node<int>* tailk = link.TailK(head, k);
    if (tailk == nullptr) {
      std::cout << "nullptr: " << k << std::endl;
    } else {
      std::cout << "K= "<< k << ", val=" << tailk->val << std::endl;
    }
    std::cout << "-------------" << std::endl;
  }

  std::cout << "------run_link_list END-------" << std::endl;
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

int Runner::run_func() {
  std::vector<int> vec = {1,2,4};
  Func<int> fun;
  fun.permute(vec, 0, vec.size());
  fun.display();
  std::cout << "-------------" << std::endl;
  const int n = 4;
  std::cout << "number of permutation of " << n << " : ";
  std::cout << fun.q(n, n) << std::endl;
  std::cout << "-------------" << std::endl;
  std::vector<int> vec2 = {1,2,4,4,4,5,7};
  show_vec(vec2);
  std::cout << "binary search:" <<  fun.binarySearch(vec2, 5) << std::endl;
  std::vector<int> vc = fun.boundSearch(vec2, 4); 
  std::cout << "bound of 4 is [" << vc.at(0) << "," << vc.at(1) << "]" << std::endl;
  //
  std::cout << "myPow(9, 2) " << fun.myPow(9,2)
            << ", myPow(9,-1) " << fun.myPow(9,-1) << std::endl;
  std::cout << "sqrt(9) : " << fun.sqrt(9) 
            << ", sqrt(16)" << fun.sqrt(16) 
            << ", sqrt(3)" << fun.sqrt(3) 
            << ", sqrt(8)" << fun.sqrt(8) 
            << std::endl;
  return 0;
}


} // namespace leetcode
} // namespace nemo
