#include "work/worker.h"

using namespace nemo::leetcode;
int main(int argc, char ** argv) {
  Runner::GetInstance().run_link_list();
  Runner::GetInstance().run_priority_heap();
  Runner::GetInstance().run_sorter();
  for (int i = 0; i < -1; ++i) {
    std::cout << "no kidding"<< std::endl;
  }
  return 0;
}
