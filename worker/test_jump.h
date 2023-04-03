#pragma once

#include "jump_stair.h"
#include "common.h"

void test_jump() {
  for (int N = 4; N < 10; ++N) {
      std::cout << "N:" << N << ", jump kinds:" << kind(N) << std::endl;
      std::cout << "N:" << N << ", jump kindR:" << kindR(N) << std::endl;
  }
}
