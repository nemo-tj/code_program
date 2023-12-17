#pragma once

#include "common.h"

namespace nemo {

  template <class T>
    class Alg {
      private:
        Alg() {};
        Alg(const Alg<T>& alg) {};
        Alg& operator=(const Alg<T> &alg) {};
        ~Alg() {}

      private:
        static Alg *alg;
      public:
        static Alg* getInstance();
        int binSearch(std::vector<T> &vec, int s, int e, T target); // [s, e)
        void shuffleVec(std::vector<T> &vec);
			public:
				int coinCombosCnt(std::vector<int> &coins, int target);
				int minCoinCnt(std::vector<int> &coins, int target);
				// 0-1
				int maxVal(std::vector<int> &weight, std::vector<int> &value, int capacity);
				// complete bag
				int maxValV2(std::vector<int> &weight, std::vector<int> &value, int capacity);
				// slide target with minimun numbers
				int minCnt(std::vector<int> nums, int target);
				// maximun unique substr
				int maxSubstr(std::string &s);
				// jump
				int minJump(std::vector<int> &nums);
				// min len contain substr
				std::string contains(std::string &s1, std::string &s2);
				// min missing
				int miss(std::vector<int> &nums);
				int miss2(std::vector<int> &nums);
				// target sum
				std::vector<int> targetSum(std::vector<int> &nums, int target);
				std::vector<int> targetAvg(std::vector<int> &nums, int avg);
				// max profit
				int maxProfit(std::vector<int> &prices);
    };

  template <class T>
    Alg<T>* Alg<T>::alg = new Alg<T>();

  template <class T>
    Alg<T>* Alg<T>::getInstance() { return alg; }

} // end nemo namespace

#include "alg.tcc"
