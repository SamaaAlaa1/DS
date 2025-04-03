#include "SortingSystem.h"

template <typename T>
SortingSystem<T>::SortingSystem(int n)
{
  size = n;
  data = new T[size];

  cin.ignore();

  for (int i = 0; i < size; i++)
  {
    cout << "Enter data " << i + 1 << ": ";

    if constexpr (std::is_same<T, std::string>::value)
    {
      getline(cin, data[i]);
    }
    else
    {
      cin >> data[i];
    }
  }
}

template <typename T>
SortingSystem<T>::~SortingSystem()
{
  delete[] data;
  data = nullptr;
}

template <typename T>
void SortingSystem<T>::insertionSort()
{
  cout << "Selection Sort\n";
  displayData();
  for (int i = 1; i < size; i++)
  {
    T key = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > key)
    {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
    displayData();
  }
  cout << "Sorted Data: ";
  displayData();
  cout << endl;
}

template <typename T>
void SortingSystem<T>::bubbleSort()
{
  displayData();
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (data[j] > data[j + 1])
      {
        swap(data[j], data[j + 1]);
      }
    }
    displayData();
  }
}

template <typename T>
void SortingSystem<T>::shellSort()
{
  displayData();
  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; i++)
    {
      T temp = data[i];
      int j;
      for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
      {
        data[j] = data[j - gap];
      }
      data[j] = temp;
    }
    displayData();
  }
}

template <typename T>
void SortingSystem<T>::selectionSort()
{
  displayData();
  for (int i = 0; i < size - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (data[j] < data[minIndex])
      {
        minIndex = j;
      }
    }
    swap(data[i], data[minIndex]);
    displayData();
  }
}

template <typename T>
void SortingSystem<T>::mergeSort(int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
    cout << "Merge Step: ";
    displayData();
  }
}

template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;
  T* LArr = new T[n1];
  T* RArr = new T[n2];
  
  for (int i = 0; i < n1; i++)
  {
    LArr[i] = data[left + i];
  }
  for (int i = 0; i < n2; i++)
  {
    RArr[i] = data[mid + 1 + i];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (LArr[i] <= RArr[j])
    {
      data[k++] = LArr[i++];
    }
    else
    {
      data[k++] = RArr[j++];
    }
  }
  while (i < n1)
    data[k++] = LArr[i++];
  while (j < n2)
    data[k++] = RArr[j++];

  delete[] LArr;
  delete[] RArr;
}

template <typename T>
void SortingSystem<T>::quickSort(int left, int right)
{
  if (left < right)
  {
    int pivotIndex = partition(left, right);
    quickSort(left, pivotIndex - 1);
    quickSort(pivotIndex + 1, right);
    cout << "Quick Sort Step: ";
    displayData();
  }
}

template <typename T>
int SortingSystem<T>::partition(int low, int high)
{
  T pivot = data[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (data[j] <= pivot)
    {
      swap(data[++i], data[j]);
    }
  }
  swap(data[i + 1], data[high]);
  return i + 1;
}

template <typename T>
void SortingSystem<T>::countSort() 
{
  T minElement = data[0], maxElement = data[0];

  for (int i = 1; i < size; i++)
  {
    if (data[i] < minElement)
    {
      minElement = data[i];
    }
    if (data[i] > maxElement)
    {
      maxElement = data[i];
    }
  }

  int range = maxElement - minElement + 1;

  int* count = new int[range](); 

  for (int i = 0; i < size; i++)
  {
    count[data[i] - minElement]++;
  }

  int index = 0;
  for (int i = 0; i < range; i++)
  {
    while (count[i]--)
    {
      data[index++] = i + minElement;
    }
  }

  delete[] count;

  cout << "Count Sort Step: ";
  displayData();
}


template <typename T>
T SortingSystem<T>::getMax()
{
  static_assert(std::is_arithmetic<T>::value, "getMax() only works with numbers");
  T mx = data[0];
  for (int i = 1; i < size; i++)
    if (data[i] > mx)
      mx = data[i];
  return mx;
}

template <typename T>
void SortingSystem<T>::countSort(int exp)
{
  T output[size];
  int count[10] = {0};

  for (int i = 0; i < size; i++)
  {
    count[(data[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++)
  {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--)
  {
    output[count[(data[i] / exp) % 10] - 1] = data[i];
    count[(data[i] / exp) % 10]--;
  }

  for (int i = 0; i < size; i++)
  {
    data[i] = output[i];
  }

  cout << "Radix Sort Step: ";
  displayData();
}

template <typename T>
void SortingSystem<T>::radixSort()
{
  T m = getMax();
  for (int exp = 1; m / exp > 0; exp *= 10)
    countSort(exp);
}

template <typename T>
void SortingSystem<T>::bucketSort() {
  T m = getMax();
  const int bucketSize = 10;
  T buckets[bucketSize][size];
  int bucketCounts[bucketSize] = {0};

  for (int i = 0; i < size; i++) {
    int index = (data[i] * bucketSize) / (m + 1);
    buckets[index][bucketCounts[index]++] = data[i];
  }

  for (int i = 0; i < bucketSize; i++) {
    for (int j = 1; j < bucketCounts[i]; j++) {
      T key = buckets[i][j];
      int k = j - 1;
      while (k >= 0 && buckets[i][k] > key) {
        buckets[i][k + 1] = buckets[i][k];
        k--;
      }
      buckets[i][k + 1] = key;
    }
  }

  int index = 0;
  for (int i = 0; i < bucketSize; i++) {
    for (int j = 0; j < bucketCounts[i]; j++) {
      data[index++] = buckets[i][j];
    }
  }
  displayData();
}



template <typename T>
void SortingSystem<T>::displayData()
{
  cout << "[";
  for (int i = 0; i < size; i++)
  {
    cout << data[i];
    if (i < size - 1)
      cout << ", ";
  }
  cout << "]\n";
}

template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)())
{
  auto start = chrono::high_resolution_clock::now();
  (this->*sortFunc)();
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;
  cout << "Sorting took " << duration.count() << " seconds.\n";
}

template <typename T>
void SortingSystem<T>::showMenu()
{
  cout << "Select a sorting algorithm:\n"
       << "1. Insertion Sort\n"
       << "2. Selection Sort\n"
       << "3. Bubble Sort\n"
       << "4. Shell Sort\n"
       << "5. Merge Sort\n"
       << "6. Quick Sort\n"
       << "7. Count Sort (Only for integers)\n"
       << "8. Radix Sort (Only for integers)\n"
       << "9. Bucket Sort\n"
       << "Enter your choice (1-9):";
}

int main()
{
  char choice;
  do
  {
    int size;
    cout << "Enter the number of items to sort: ";
    cin >> size;

    cout << "Select the data type:\n"
         << "1. Integer\n"
         << "2. Float\n"
         << "3. String\n"
         << "Enter your choice (1-3): ";
    int dataTypeChoice;
    cin >> dataTypeChoice;

    if (dataTypeChoice == 1)
    {
      SortingSystem<int> sortingSystem(size);
      sortingSystem.showMenu();
      int sortChoice;
      cin >> sortChoice;

      switch (sortChoice)
      {
      case 1:
        sortingSystem.measureSortTime(&SortingSystem<int>::insertionSort);
        break;
      case 2:
        sortingSystem.measureSortTime(&SortingSystem<int>::selectionSort);
        break;
      case 3:
        sortingSystem.measureSortTime(&SortingSystem<int>::bubbleSort);
        break;
      case 4:
        sortingSystem.measureSortTime(&SortingSystem<int>::shellSort);
        break;
      case 5:
        sortingSystem.mergeSort(0, size - 1);
        break;
      case 6:
        sortingSystem.quickSort(0, size - 1);
        break;
      case 7:
        sortingSystem.measureSortTime(&SortingSystem<int>::countSort);
        break;
      case 8:
        sortingSystem.measureSortTime(&SortingSystem<int>::radixSort);
        break;
      case 9:
        sortingSystem.measureSortTime(&SortingSystem<int>::bucketSort);
        break;
      default:
        cout << "Invalid choice. Please select a number between 1-9.\n";
      }
    }
    else if (dataTypeChoice == 2)
    {
      SortingSystem<float> sortingSystem(size);
      sortingSystem.showMenu();
      int sortChoice;
      cin >> sortChoice;

      switch (sortChoice)
      {
      case 1:
        sortingSystem.measureSortTime(&SortingSystem<float>::insertionSort);
        break;
      case 2:
        sortingSystem.measureSortTime(&SortingSystem<float>::selectionSort);
        break;
      case 3:
        sortingSystem.measureSortTime(&SortingSystem<float>::bubbleSort);
        break;
      case 4:
        sortingSystem.measureSortTime(&SortingSystem<float>::shellSort);
        break;
      case 5:
        sortingSystem.mergeSort(0, size - 1);
        break;
      case 6:
        sortingSystem.quickSort(0, size - 1);
        break;
      case 9:
        sortingSystem.measureSortTime(&SortingSystem<float>::bucketSort);
        break;
      default:
        cout << "Invalid choice. Please select a number between 1-9.\n";
      }
    }
    else if (dataTypeChoice == 3)
    {
      SortingSystem<string> sortingSystem(size);
      sortingSystem.showMenu();
      int sortChoice;
      cin >> sortChoice;

      switch (sortChoice)
      {
      case 1:
        sortingSystem.measureSortTime(&SortingSystem<string>::insertionSort);
        break;
      case 2:
        sortingSystem.measureSortTime(&SortingSystem<string>::selectionSort);
        break;
      case 3:
        sortingSystem.measureSortTime(&SortingSystem<string>::bubbleSort);
        break;
      case 4:
        sortingSystem.measureSortTime(&SortingSystem<string>::shellSort);
        break;
      case 5:
        sortingSystem.mergeSort(0, size - 1);
        break;
      case 6:
        sortingSystem.quickSort(0, size - 1);
        break;
      default:
        cout << "Invalid choice. Please select a number between 1-9.\n";
      }
    }
    else
    {
      cout << "Invalid data type choice. Please select a number between 1-3.\n";
    }

    cout << "Do you want to sort another dataset? (y/n): ";
    cin >> choice;

  } while (choice == 'y' || choice == 'Y');

  cout << "Thank you for using the sorting system! Goodbye!\n";
  return 0;
}
