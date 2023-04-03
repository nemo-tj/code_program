#pragma once

#include <vector>
#include <iostream>
#include <pthread.h>


namespace nemo {

  enum SORTER {
    BUB,
    INSERT,
    HEAP,
    SELECTION,
    QUICK,
  };
  
  template <class T>
    class Sorter {
      public:
        virtual void sort(std::vector<T> &vec, int start, int end) = 0;
        virtual ~Sorter() = 0;
    };

  template <class T>
    Sorter<T>::~Sorter() { std::cout << "destroying sorter" << std::endl; }

  /******************************************************/


  // BubSorter : hungry, create when initialised

  template <class T>
    class BubSorter : public Sorter<T> {
      protected:
        BubSorter() { std::cout << "BUB" << std::endl; }
        ~BubSorter() { std::cout << "bub destroying" << std::endl; }
      private:
        static Sorter<T> *sorter;
      public:
        static Sorter<T> *getInstance();
        void sort(std::vector<T> &vec, int start, int end);
    };

  template <class T>
    Sorter<T>* BubSorter<T>::sorter = new BubSorter<T>();

  template <class T>
    Sorter<T>* BubSorter<T>::getInstance() {
      return sorter;
    }


  // SelectionSort : lazy, create when necessary

  template <class T>
    class SelectionSorter : public Sorter<T> {
      private:
        SelectionSorter() {
          pthread_mutex_init(&mutex, NULL);
          std::cout << "SELECTION" << std::endl;
        }
        ~SelectionSorter() { 
          pthread_mutex_destroy(&mutex);
          std::cout << "selection destroying" << std::endl;
        }
      public:
        static pthread_mutex_t mutex;
        static Sorter<T>* getInstance();

      public:
        void sort(std::vector<T> &vec, int start, int end);
    };

  template <class T>
    pthread_mutex_t SelectionSorter<T>::mutex;

  template <class T>
    Sorter<T>* SelectionSorter<T>::getInstance() {
      pthread_mutex_lock(&mutex);
      // pthread_mutex_trylock(&mutex);
      static SelectionSorter<T> sorter;
      pthread_mutex_unlock(&mutex);
      return &sorter;
    }
  

  // HeapSorter:

  template <class T>
    class HeapSorter : public Sorter<T> {
      private:
        HeapSorter() { std::cout << "HEAP" << std::endl; };
        HeapSorter(const HeapSorter<T> &sorter) {};
        HeapSorter& operator=(const HeapSorter<T> &sorter) {};
      public:
        ~HeapSorter() { std::cout << "HEAP destroying.." << std::endl; };
      private:
        static Sorter<T>* sorter;
      public:
        static Sorter<T>* getInstance();
        void sort(std::vector<T> &vec, int start, int end);
      private:
        void sink(std::vector<T> &vec, int s, int k, int N);
        void exch(std::vector<T> &vec, int i, int j);
        bool less(T &a, T &b);
      private:
        void swin(std::vector<T> &vec, int s, int k);
    };

  template <class T>
    Sorter<T>* HeapSorter<T>::sorter = new HeapSorter<T>();

  template <class T>
    Sorter<T>* HeapSorter<T>::getInstance() { return sorter; }


  // InsertSorter : 


  template <class T>
    class InsertSorterFactory {
      public:
        ~InsertSorterFactory() { if (nullptr != sorter) delete sorter; }
      private:
        static Sorter<T> *sorter;
      public:
        static Sorter<T> *getInstance();
    };

  template <class T> class InsertSorter;

  template <class T>
    Sorter<T>* InsertSorterFactory<T>::sorter = new InsertSorter<T>();
  template <class T>
    Sorter<T>* InsertSorterFactory<T>::getInstance() {
      return sorter;
    }

  template <class T>
    class InsertSorter : public Sorter<T> {
      public:
        void sort(std::vector<T> &vec, int start, int end);
        void sortV1(std::vector<T> &vec, int start, int end);
        friend class InsertSorterFactory<T>;
      private:
        InsertSorter() { std::cout << "INSERT" << std::endl; }
        InsertSorter(const InsertSorter<T> &vec) {};
        InsertSorter<T>& operator=(const InsertSorter<T> &vec) {};
        ~InsertSorter() { std::cout << "insert destroying" << std::endl; }
    };


  // QuickSort:

  template <class T>
    class QuickSorterFactory {
      public:
        QuickSorterFactory() {
          std::cout << "QUICK FACTORY" << std::endl;
          pthread_mutex_init(&mutex, NULL);
        }
        ~QuickSorterFactory() {
          pthread_mutex_destroy(&mutex);
          std::cout << "quick_factory destroying" << std::endl;
        }

      public:
        Sorter<T> *getInstance();

      private:
        pthread_mutex_t mutex;
        Sorter<T> *instance = nullptr;
    };

  // Declare class
  template <class T> class QuickSorter;

  template <class T>
    Sorter<T>* QuickSorterFactory<T>::getInstance() {
      if (nullptr == instance) {
        pthread_mutex_lock(&mutex);
        if (nullptr == instance) {
          instance = new QuickSorter<T>();
        }
        pthread_mutex_unlock(&mutex);
      }
      return instance;
    }

  template <class T>
    class QuickSorter : public Sorter<T> {
      public:
        void sort(std::vector<T> &vec, int start, int end);
        void sortV1(std::vector<T> &vec, int start, int end);
        friend class QuickSorterFactory<T>;
        /*
      private:
        QuickSorter() {
          std::cout << "QUICK" << std::endl;
        }
        ~QuickSorter() {
          std::cout << "quick destroying" << std::endl;
        }
        */
    };


  // ------------------------------------------------ //

  template <class T>
    class SorterFactory {
      private:
        QuickSorterFactory<T> quickSorterFactory;
      public:
        Sorter<T> *create(const SORTER &st) {
          switch (st) {
            case HEAP:
              return HeapSorter<T>::getInstance();
            case BUB:
              return BubSorter<T>::getInstance();
            case SELECTION:
              return SelectionSorter<T>::getInstance();
            case INSERT:
              return InsertSorterFactory<T>::getInstance();
            case QUICK:
              return quickSorterFactory.getInstance();
            default:
              break;
          };
          return nullptr;
        }
    };


} // end nemo namespace

#include "sorter.tcc"
