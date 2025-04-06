#ifndef SORTINGSYSTEM_H
#define SORTINGSYSTEM_H
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SortingSystem
{
    T *data;
    int size;

public:
    SortingSystem(int n);
    ~SortingSystem();
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(int left, int right);
    void quickSort(int left, int right);
    void countSort();
    void countSort(int exp);
    void radixSort();
    void bucketSort();
    void merge(int left, int mid, int right);
    int partition(int low, int high);

    void displayData();
    void measureSortTime(void (SortingSystem::*sortFunc)());
    void showMenu();
    T getMax();
    void setDataAt(int index, T value);
    void inputData();
    void loadFromFile(string filename, int& size);

};

#endif // SORTINGSYSTEM_H
