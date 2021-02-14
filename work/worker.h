#pragma once

#include "comp/common.h"

namespace nemo {
  namespace leetcode {

    class Runner{

      public:
        static Runner& GetInstance() { // singletone pattern
          static Runner runner;
          return runner;
        }
        int run_link_list();
        int run_bi_tree();
        int run_sorter();
        int run_func();

      private:
        Runner(){}
        Runner(const Runner &);
        Runner& operator=(const Runner &);
    };

    } // namespace leetcode
} // namespace nemo
