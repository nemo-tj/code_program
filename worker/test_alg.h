#include "link.h"
#include "btree.h"
#include "sorter.h"

#include "perm.h"

#include "util.h"
#include "node.h"

#include <algorithm>
#include <random>

using namespace nemo;

void test_alg() {
  INFO("test_alg");
  std::vector<int> vec = {4, 5, 2, 1, 3, 4, 2, 9};
  std::cout << "vec: ";
  display(vec);
  // desc sort
  std::sort(vec.begin(), vec.end(), [](const int &a, const int &b) { return a > b; } );
  std::cout << "sort: ";
  display(vec);
  LINE;
  
  SorterFactory<int> factory;
  Sorter<int> *sorter;
  Alg<int> *alg = Alg<int>::getInstance();

  INFO("HEAP");
  sorter = factory.create(HEAP);
  sorter->sort(vec, 2, vec.size());
  display(vec);

  INFO("SHUFFLE");
  alg->shuffleVec(vec);
  display(vec);

  INFO("QUICK");
  sorter = factory.create(QUICK);
  sorter->sort(vec, 0, vec.size());
  display(vec);

  INFO("SHUFFLE");
  alg->shuffleVec(vec);
  display(vec);

  INFO("INSERT");
  sorter = factory.create(INSERT);
  sorter->sort(vec, 0, vec.size());
  display(vec);

  INFO("end test alg");
}
