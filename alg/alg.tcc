#include <algorithm>
#include <chrono>
#include <random>


namespace nemo {

  template <class T>
    int Alg<T>::binSearch(std::vector<T> &vec, int i, int j, T target) {
      j = j -1;
      while (i <= j) {
        int x = i + (j-i) / 2;
        if (vec[x] == target) return x;
        else if (vec[x] < target) i = x +1;
        else j = x - 1;
      }
      return i;
    }

  template <class T>
    void Alg<T>::shuffleVec(std::vector<T> &vec) {
      /*
      std::random_device rd;
      std::mt19937 rng(rd());
      std::shuffle(vec.begin(), vec.end(), rng);
      */
      unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
      std::shuffle(vec.begin(), vec.end(), std::default_random_engine(seed));
    }

	template <class T>
		int Alg<T>::maxProfit(std::vector<int> &prices) {
			if (prices.size() <= 1) return 0;
			int s = 0, i = 0, j = 1;
			while (j <= prices.size()) {
				int next = (j == prices.size()) ? 0 : prices[j];
				if (prices[j-1] > next && j-1 > i) {
					s += (prices[j-1] - prices[i]);
					i = j;
				}
				++j;
			}
			return s;
		}

	template <class T>
		std::vector<int> Alg<T>::targetAvg(std::vector<int> &nums, int avg) {
			for (int i = 0; i < nums.size(); ++i) {
				nums[i] -= avg;
			}
			int s = 0;
			std::unordered_map<int, int> mp;
			mp[s] = -1;
			for (int i = 0; i < nums.size(); ++i) {
				s += nums[i];
				auto it = mp.find(s);
				if (it != mp.end()) {
					return std::vector<int>(nums.begin() + it->second + 1, nums.begin() + i + 1);
				}
				mp[s] = i;
			}
			return { -1, -1 };
		}

	template <class T>
		std::vector<int> Alg<T>::targetSum(std::vector<int> &nums, int target) {
			int i = 0, s = 0;
			std::unordered_map<int, int> mp;
			mp[s] = -1;
			while (i < nums.size()) {
				s += nums[i];
				if (mp.find(s - target) != mp.end()) {
					return std::vector<int>(nums.begin() + mp[s-target] + 1, nums.begin() + i + 1);
				}
				mp[s] = i;
				++i;
			}
			return { -1, -1 };
		}

	template <class T>
		int Alg<T>::miss2(std::vector<int> &nums) {
			int i = 0;
			while (i < nums.size()) {
				int x = nums[i];
				if (x <= 0 || x > nums.size()) { i++; continue; }
				x = x - 1;
				if (x >= 0 && x < nums.size() && nums[i] != nums[x]) {
					int t = nums[x];
					nums[x] = nums[i];
					nums[i] = t;
				}
			}
			for (int i = 0; i < nums.size(); ++i) {
				if (i + 1 == nums[i]) return i + 1;
			}
			return nums.size() + 1;
		}

	template <class T>
		int Alg<T>::miss(std::vector<int> &nums) {
			int nan = nums.size() + 1;
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] <= 0) nums[i] = nan;
			}
			for (int i = 0; i < nums.size(); ++i) {
				int x = std::max(nums[i], -nums[i]);
				if (x <= nums.size()) {
					x = x - 1;
					nums[x] = std::min(nums[x], -nums[x]);
				}
			}
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] > 0) return i + 1;
			}
			return nan;
		}
	
	template <class T>
		std::string Alg<T>::contains(std::string &s1, std::string &s2) {
			std::unordered_map<char, int> need;
			for (char c : s1) if (need.count(c) > 0) need[c]++; else need[c] = 1;
			int i = 0, j = 0, valid = 0;
			std::unordered_map<char, int> window;
			if (need.count(s2[0]) > 0) {
				window[s2[0]] = 1;
				valid++;
				++j;
				if (need.size() == 1) return s1;
			}
			int len = INT_MAX, start = 0;
			while (j < s2.size()) {
				char c = s2[j];	
				if (need.count(c)) {
					window[c]++;
					if (window[c] == need[c]) valid++;
				}
				while (valid >= need.size()) {
					start = i;
					len = std::min(len, j - i + 1);
					char t = s2[i];
					if (need.count(t)) {
						window[t]--;
						if (need[t] > window[t])  valid --;
					}
					++i;
				}
				++j;
			}
			return s2.substr(start, len);
		}



	template <class T>
		int Alg<T>::minJump(std::vector<int> &nums) {	
			int cur = 0, reach = 0, jump = 0;
			for (int i = 0; i < nums.size(); ++i) {
				reach = std::max(reach, i + nums[i]);
				if (cur == i) {
					cur = reach;
					++jump;
				}
			}
			return jump;
		}

	template <class T>
		int Alg<T>::maxSubstr(std::string &s) {
			if (s.size() <= 1) return s.size();
			int i = 0, j = 1, r = 1;
			std::unordered_map<char, int> mp;
			mp[s[i]] = i;
			while (j < s.size()) {
				auto it = mp.find(s[j]);
				if (it == mp.end() || it->second < i) {
					r = std::max(r, j - i + 1);
				} else {
					i = it->second + 1;
				}
				mp[s[j]] = j;
				++j;
			}
			return r;
		}

	template <class T>
		int Alg<T>::minCnt(std::vector<int> nums, int target) {
			int i = 0, j = 1, r = INT_MAX;
			int s = nums[i];
			while (j < nums.size()) {
				if (s < target) {
					s += nums[j];
					++j;
				}
				while (s >= target) {
					r = std::min(r, j - i);
					s -= nums[i];
					++i;
				}
			}
			return r == INT_MAX ? 0 : r;
		}

	template <class T>
		 int Alg<T>::maxValV2(std::vector<int> &weight, std::vector<int> &value, int capacity) {
			 // dp[i][j] = std::max(dp[i-1][j], dp[i][j-w[i]] + v[i])
			 int sz = weight.size();
			 std::vector<int> dp(capacity + 1, 0);
			 for (int i = 0; i < sz; ++i) {
				 for (int j = weight[i]; j <= capacity; ++j) {
					 dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
				 }
			 }
			 return dp[capacity];
		 }

	template <class T>
		 int Alg<T>::maxVal(std::vector<int> &weight, std::vector<int> &value, int capacity) {
			 // dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - w[i]] + v[i])
			 if (weight.size() != value.size()) return -1;
			 int sz = weight.size();
			 std::vector<int> dp(capacity+1, 0);
			 for (int i = 0; i < sz; ++i) {
				 for (int j = capacity; j >= weight[i]; --j) {
					 dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
				 }
			 }
			 return dp[capacity];
		 }

	template <class T>
		int Alg<T>::minCoinCnt(std::vector<int> &coins, int target) {
			std::vector<int> dp(target + 1, INT_MAX);
			dp[0] = 0;
			for (int w = 1; w <= target; ++w) {
				for (auto coin : coins) {
					if (w >= coin && dp[w-coin] != INT_MAX) dp[w] = std::min(dp[w], dp[w - coin] + 1);
				}
			}
			return dp[target];
		}

	template <class T>
		int Alg<T>::coinCombosCnt(std::vector<int> &coins, int target) {
			std::vector<int> dp(target+1, 0);
			dp[0] = 1;
			for (auto coin : coins) {
				for (int w = coin; w <= target; ++w) {
					dp[w] += dp[w - coin];
				}
			}
			return dp[target];
		}

} // end nemo namespace
