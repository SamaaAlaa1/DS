#include "SortingSystem.h"

template <typename T>
SortingSystem<T>::SortingSystem(int n) {
    cout << "Enter the number of items to sort: ";
  cin >> n;
  size = n;
  data = new T[size];
  for (int i = 0; i < size; i++) {
    cout << "Enter data " << i + 1 << ": ";
    cin >> data[i];
  }
}

template <typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
    data = nullptr;
}

template <typename T>
void SortingSystem<T>::insertionSort() {
  displayData("Initial Data");
  for (int i = 1; i < size; i++) {
    T key = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > key) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
    displayData("Iteration " + to_string(i));
  }
}

template <typename T>
void SortingSystem<T>::bubbleSort() {
  displayData("Initial Data");
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (data[j] > data[j + 1]){
        swap(data[j], data[j + 1]);
      }
    }
    displayData("Iteration " + to_string(i + 1));
  }
}

template <typename T>
void SortingSystem<T>::shellSort() {
  displayData("Initial Data");
  for (int gap = size / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < size; i++) {
      T temp = data[i];
      int j;
      for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
        data[j] = data[j - gap];
      }
      data[j] = temp;
    }
    displayData("Iteration (gap=" + to_string(gap) + ")");
  }
}

template <typename T>
void SortingSystem<T>::selectionSort() {
  displayData("Initial Data");
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (data[j] < data[minIndex]){
        minIndex = j;
      }
    }
    swap(data[i], data[minIndex]);
    displayData("Iteration " + to_string(i + 1));
  }
}

template <typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
    cout << "Merge Step: ";
    displayData();
  }
}

template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<T> LArr(n1), RArr(n2);
  for (int i = 0; i < n1; i++) {
    LArr[i] = data[left + i];
  }
  for (int i = 0; i < n2; i++) {
    RArr[i] = data[mid + 1 + i];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (LArr[i] <= RArr[j]) {
      data[k++] = LArr[i++];
    }
    else {
      data[k++] = RArr[j++];
    }
  }
  while (i < n1) data[k++] = LArr[i++];
  while (j < n2) data[k++] = RArr[j++];
}

template <typename T>
void SortingSystem<T>::quickSort(int left, int right) {
  if (left < right) {
    int pivotIndex = partition(left, right);
    quickSort(left, pivotIndex - 1);
    quickSort(pivotIndex + 1, right);
    cout << "Quick Sort Step: ";
    displayData();
  }
}

template <typename T>
int SortingSystem<T>::partition(int low, int high) {
  T pivot = data[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (data[j] <= pivot) {
      swap(data[++i], data[j]);
    }
  }
  swap(data[i + 1], data[high]);
  return i + 1;
}


template <typename T>
void SortingSystem<T>::countSort() {
  T minElement = data[0], maxElement = data[0];
  for (int i = 1; i < size; i++) {
    if (data[i] < minElement) {
      minElement = data[i];
    }
    if (data[i] > maxElement){
      maxElement = data[i];
    }
  }
  int range = maxElement - minElement + 1;
  vector<int> count(range, 0);
  for (int i = 0; i < size; i++) {
    count[data[i] - minElement]++;
  }
  int index = 0;
  for (int i = 0; i < range; i++) {
    while (count[i]--) {
      data[index++] = i + minElement;
    }
  }
  cout << "Count Sort Step: ";
  displayData();
}

template <typename T>
void SortingSystem<T>::radixSort() {

}

template <typename T>
void SortingSystem<T>::bucketSort() {

}

template <typename T>
void SortingSystem<T>::displayData() {
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
  auto start = chrono::high_resolution_clock::now();
  (this->*sortFunc)();
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;
  cout << "Sorting took " << duration.count() << " seconds.\n";
}

template <typename T>
void SortingSystem<T>::showMenu() {

}
