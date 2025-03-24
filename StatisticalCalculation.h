#ifndef STATISTICALCALCULATION_H
#define STATISTICALCALCULATION_H
#include<bits/stdc++.h>
using namespace std;
template <class T>
class StatisticalCalculation {
    T* data;
    int size;
    public:
      StatisticalCalculation();
      ~StatisticalCalculation();
      void sort();
      double findMedian();
      T findMin();
      T findMax();
      double findMean();
      T findSummation();

      // Utility Function
      void displayArray();
      void inputData();
      void statisticsMenu();
};



#endif //STATISTICALCALCULATION_H
