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
        int run_priority_heap();
        int run_sorter();

      private:
        Runner(){}
        Runner(const Runner &);
        Runner& operator=(const Runner &);
    };

    } // namespace leetcode
} // namespace nemo
