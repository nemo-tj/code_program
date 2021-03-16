#include "comp/function.h"

namespace nemo {
  template <class T>
  void Func<T>::permute(std::vector<T> &vec, int k , int m) {
    if (k == m) {
      std::vector<T> vt(vec.begin(), vec.begin() + m);
      p_results.push_back(vt);
      return;
    }
    for (int i = k; i < m; i++) {
      swap_val(vec[k], vec[i]);
      permute(vec, k+1, m);
      swap_val(vec[k], vec[i]);
    }
  }

  template <class T>
  void Func<T>::display() {
    show_vec_vec(p_results);
  }

  template <class T>
  int Func<T>::q(int n, int m) {
    if (n == 1 || m == 1) return 1;
    if (n < m) return q(n, n);
    if (n == m) return q(n, n-1) + 1;
    return q(n, m-1) + q(n-m, m);
  }

  template <class T>
  int Func<T>::binaryRS(const std::vector<T> &vec, const T &t, int i, int j) {
    int ix = -1;
    if (i > j) return ix;
    int mid = i + (j - i)/2;
    if (vec.at(mid) == t) {
      ix = mid;
    } else if (vec.at(mid) < t) {
      ix = binaryRS(vec, t, mid + 1, j);
    } else {
      ix = binaryRS(vec, t, i, mid - 1);
    }
    return ix;
  }

  template <class T>
  int Func<T>::binaryNear(const std::vector<T> &vec, const T &t) {
    int s = 0, e = vec.size()-1;
    while (s <= e) {
      int m = (s + e) / 2;
      if (t < vec[m]) e = m;
      else s = m;
      if (vec[m] <= t && t <= vec[m+1]) break;
    }
    return 0;
  }

  template <class T>
  int Func<T>::binarySearch(const std::vector<T> &vec, const T &t) {
    int s = 0, e = vec.size()-1;
    while (s <= e) {
      int mid = (s + e) / 2;
      if (vec[mid] == t) return mid;
      if (vec[mid] < t) s = mid + 1;
      else e = mid - 1;
    }
    return -1;
  }

  template <class T>
  std::vector<int> Func<T>::boundSearch(const std::vector<T> &vec, const T &t) {
    int s = 0, e = vec.size()-1;
    int mid = 0;
    while (s <= e) {
      mid = s + (e - s) / 2;
      if (vec[mid] == t) break;
      if (vec[mid] < t) s = mid + 1;
      else e = mid - 1;
    }
    // left s : mid
    int ee = mid;
    while (vec[s] != t) {
      if (vec[s+1] == t) { s +=1; break;}
      int m = (s + ee) / 2;
      if (vec[m] != t) s = m;
      else ee = m;
    }
    // right mid : e
    int ss = mid;
    while (vec[e] != t) {
      if (vec[e-1] == t) {e -= 1; break;}
      int m = (ss + e) / 2;
      if (vec[m] != t) e = m;
      else ss = m;
    }
    return {s, e};
  }

  template <class T>
  double Func<T>::myPow(const T &x, int n) {
    if (n == 0) return 1;
    double half = myPow(x, n / 2);
    if (n % 2 == 0) return half * half; // even
    else if (n > 0) return half * half * x; // positive odd
    else return half * half  * (1.0 / x); // negative odd
  }

  template <class T>
  int Func<T>::sqrt(const int &n) {
    int left = 0;
    int right = n;
    while (true) {
      int mid = (left + right) / 2;
      int val = mid * mid;
      if (val == n) return mid;
      if (val < n) left = mid;
      else right = mid; 
      if (right - left <= 1) break;
    }
    return left;
  }


  #define _EXPLICIT_DEFINE(CT) template class Func<CT>
  _EXPLICIT_DEFINE(char);
  _EXPLICIT_DEFINE(int);
  _EXPLICIT_DEFINE(float);
  _EXPLICIT_DEFINE(double);
  #undef _EXPLICIT_DEFINE
}
