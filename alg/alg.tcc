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

} // end nemo namespace
