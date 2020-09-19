#pragma once

#include "component/common.h"

namespace nemo {

 template <class T>
 class PriorityHeap {
   public:
     PriorityHeap(int sz=0) {
       size = sz;
       capacity = (sz > 0)? (sz<<1) : (1);
       vec.resize(capacity);
     }

     PriorityHeap(const std::vector<T>& ve) {
       if (ve.size()  > capacity) {
         capacity = 2 * ve.size();
         vec.resize(capacity);
       }
       for (int i = 0; i < ve.size(); ++i) {
         vec[i] = ve[i];
       }
       size = ve.size();
       for (int i = 0; i < (size>>1); ++i) {
         sink(i);
       }
     }

     void sort(std::vector<T> &result) {
       // info("sort start");
       result.clear();
       result.reserve(size);
       while (!empty()) {
         result.push_back(top());
         pop();
       }
       // info("sort end");
     }
     
     void pop() {
       if (size == 0) return;
       shrink(); 
       T v = vec[0];
       vec[0] = vec[--size];
       vec[size] = v;
       sink(0);
     }

     bool push(T v) {
       if (size >= capacity) {
         expand();
       }
       vec[size] = v;
       size += 1;
       swing(size);
       return true;
     }

     T top() {
       if (empty()) return INT_MAX;
       return vec.at(0);
     }

     bool empty() { return size == 0; }

     std::vector<T> GetVec() { return vec;}

   private:
     void info(std::string str = "") {
       std::cout << "-------------" << std::endl;
       std::cout << str << " : " << std::endl;
       std::cout << "size: " << size 
                 << ", capacity:" << capacity
                 << std::endl;
     }

     bool expand() {
       if (vec.empty()) {
         vec.resize(2);
         return true;
       }
       std::vector<T> ve(vec);
       // size = ve.size();
       capacity = 2 * size;
       vec.resize(capacity);
       for (int i = 0; i < size; ++i) {
        vec[i] = ve[i]; 
       }
       return true;
     }
     
     bool shrink() {
       if (capacity > 2 * size) {
         capacity = 2 * size;
         vec.resize(capacity);
       }
       return true;
     }

     void swing(int j) {
       int i = (j+1)/2 -1;
       if (i < 0) return;
       int k = 2 * (i+1) - 1;
       int g = k + 1;
       int val = vec[i];
       if (g >= size) {
         if (k < size) {
          T min = std::min(vec[k], val); 
          vec[k] = (vec[k] + val) - min;
          vec[i] = min;
         } else {
           ;
         }
       } else {
         T min = vec[k];
         T max = vec[g];
         if (val < min) {
           vec[k] = min;
           vec[g] = max;
         } else if (val < max) {
           vec[i] = min;
           vec[k] = val;
           vec[g] = max;
         } else {
           vec[i] = min;
           vec[k] = max;
           vec[g] = val;
         }
       }
       swing(i);
     }

     void sink(int i) {
       int k = 2 * (i+1) - 1;
       int g = k + 1;
       int val = vec[i];
       if (g >= size) {
         if (k < size) {
          T min = std::min(vec[k], val); 
          vec[k] = (vec[k] + val) - min;
          vec[i] = min;
         } else {
           ;
         }
         return;
       } else {
         T min = std::min(vec[k], vec[g]);
         T max = (vec[k] + vec[g]) - min;
         if (val < min) {
           vec[k] = min;
           vec[g] = max;
         } else if (val < max) {
           vec[i] = min;
           vec[k] = val;
           vec[g] = max;
         } else {
           vec[i] = min;
           vec[k] = max;
           vec[g] = val;
         }
       }
       sink(k);
       sink(g);
     }

   private:
     std::vector<T> vec;
     int capacity;
     int size;
 };

}  // nemo
