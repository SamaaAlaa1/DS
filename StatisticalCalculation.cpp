
#include "StatisticalCalculation.h"
template <class T>
StatisticalCalculation<T>::StatisticalCalculation() {
  cout << "Enter the number of elements: ";
  cin >> size;
  data = new T[size];
  inputData();
}

template <class T>
StatisticalCalculation<T>::~StatisticalCalculation(){
  delete[] data;
  data = nullptr;
}

template <class T>
void StatisticalCalculation<T>::sort(){
  std::sort(data,data+size);
}

template <class T>
double StatisticalCalculation<T>::findMedian() {
  sort();
  if (size % 2 == 0){
    return (data[size / 2 - 1] + data[size / 2]) / 2;
  }
  return data[size / 2];
}

template <class T>
T StatisticalCalculation<T>::findMax(){
  sort();
  return data[size-1];
}

template <class T>
T StatisticalCalculation<T>::findMin(){
  sort();
  return data[0];
}

template <class T>
double StatisticalCalculation<T>::findMean() {
  T sum = 0;
  for (int i = 0; i < size; i++) {
    sum += data[i];
  }
  return static_cast<double>(sum) / size;
}

template <class T>
T StatisticalCalculation<T>::findSummation() {
  T sum = 0;
  for (int i = 0; i < size; i++) {
    sum += data[i];
  }
  return sum;
}

template <class T>
void StatisticalCalculation<T>::displayArray() {
  cout << "Array elements: ";
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout<<'\n';
}

template <class T>
void StatisticalCalculation<T>::inputData() {
  for (int i = 0; i < size; i++) {
    cout << "Enter element " << i + 1 << ": ";
    cin >> data[i];
  }
  cout<<'\n';
}

template <class T>
void StatisticalCalculation<T>::statisticsMenu() {
  int choice;
  cout << "\nSelect a statistical calculation:\n";
  cout << "1. Find Median\n"
      <<"2. Find Minimum\n"
      <<"3. Find Maximum\n"
      <<"4. Find Mean\n"
      <<"5. Find Summation\n";
  cout << "Enter your choice (1-5): ";
  cin >> choice;
  if (choice == 1) {
    cout << "Median: " << findMedian() <<'\n';
  }
  else if (choice == 2) {
    cout << "Minimum: " << findMin() <<'\n';
  }
  else if (choice == 3) {
    cout << "Maximum: " << findMax() <<'\n';
  }
  else if (choice == 4) {
    cout << "Mean: " << findMean() <<'\n';
  }
  else if (choice == 5) {
    cout << "Summation: " << findSummation() <<'\n'
        ;
  }
  else {
    cout << "Invalid choice! Please enter a number between 1 and 5.\n";
  }
}

