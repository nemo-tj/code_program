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
	std::vector<int> coins = {1, 2, 5};
	int target = 5;

	INFO("coins change");
	std::cout << "conbos cnt: " << alg->coinCombosCnt(coins, target) << std::endl;
	std::cout << "min coins cnt: " << alg->minCoinCnt(coins, target) << std::endl;
	std::cout << std::endl;

	INFO("min miss");
	std::vector<int> num = {2,1,4,0, 5,-1, 1000};
	std::vector<int> targ = alg->targetSum(num, 9);
	std::cout << "target sum = 9" << std::endl;
	display(targ);
	std::vector<int> avg = alg->targetAvg(num, 3);
	display(avg);
	
	display(num);
	std::cout << "miss: " << alg->miss(num) << std::endl;

	INFO("stock profit");
	std::vector<int> stock = {1,2,5,4, 5};
	display(stock);
	std::cout << alg->maxProfit(stock) << std::endl;
	

	INFO("MIN CNT");
	std::vector<int> nums = {1,2,3,2,3,4};
	display(nums);
	std::cout << "7, min cnt: " << alg->minCnt(nums, 7) << std::endl;
	std::cout << "4, 1 4 4: " << alg->minCnt({1,4,4}, 4) << std::endl;

	INFO("SUBSTR LEN");
	std::string s = "aabcaa";
	std::cout << "substr len:" << s << alg->maxSubstr(s) << std::endl;

  INFO("INSERT");
  sorter = factory.create(INSERT);
  sorter->sort(vec, 0, vec.size());
  display(vec);

  INFO("end test alg");
}
