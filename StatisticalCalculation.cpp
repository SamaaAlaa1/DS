
#include "StatisticalCalculation.h"
template <class T>
StatisticalCalculation<T>::StatisticalCalculation() {
  data = new T[size];
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
T StatisticalCalculation<T>::findMedian() {
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
    cout << "Welcome to the Statistical Calculation Program!";
    while (true) {
        int choice1;
        cout << "\nSelect an option:\n1. Enter the input\n2. Input from file\n3. Exit Program.\nEnter Your Choice: ";
        cin >> choice1;
        if (choice1 == 1) {
            cout << "Enter number of elements: ";
            cin >> size;
            delete[] data;
            data = new T[size];
            inputData();

            int choice;
            cout << "\nSelect a statistical calculation:\n";
            cout << "1. Find Median\n"
                 << "2. Find Minimum\n"
                 << "3. Find Maximum\n"
                 << "4. Find Mean\n"
                 << "5. Find Summation\n";
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            if (choice == 1) {
                cout << "Median: " << findMedian() << '\n';
            }
            else if (choice == 2) {
                cout << "Minimum: " << findMin() << '\n';
            }
            else if (choice == 3) {
                cout << "Maximum: " << findMax() << '\n';
            }
            else if (choice == 4) {
                cout << "Mean: " << findMean() << '\n';
            }
            else if (choice == 5) {
                cout << "Summation: " << findSummation() << '\n';
            }
            else {
                cout << "Invalid choice!\n";
            }
        }
        else if (choice1 == 2) {
            string filename = "TestCasesForStatisticalCalculation.txt";
            ifstream file(filename);
            if (!file) {
                cout << "Error: Cannot open file " << filename << '\n';
                return;
            }
            while (true) {
                int size;
                if (!(file >> size)) {
                    cout << "No more test cases in the file.\n";
                    break;
                }
                delete[] data;
                data = new T[size];
                for (int i = 0; i < size; ++i) {
                    file >> data[i];
                }
                int choice;
                file >> choice;
                cout << "\nProcessing test case from file:\n";
                if (choice == 1) {
                    cout << "Median: " << findMedian() << '\n';
                }
                else if (choice == 2) {
                    cout << "Minimum: " << findMin() << '\n';
                }
                else if (choice == 3) {
                    cout << "Maximum: " << findMax() << '\n';
                }
                else if (choice == 4) {
                    cout << "Mean: " << findMean() << '\n';
                }
                else if (choice == 5) {
                    cout << "Summation: " << findSummation() << '\n';
                }
                else {
                    cout << "Invalid choice in file!\n";
                }
                char next;
                cout << "\nDo you want to process the next test case from file or input your own? (f for file, i for input): ";
                cin >> next;
                if (next == 'f' || next == 'F') {
                    continue;
                }
                else if (next == 'i' || next == 'I') {
                    break;
                }
                else {
                    cout << "Invalid option, returning to main menu.\n";
                    break;
                }
            }
        }
        else if (choice1 == 3) {
            cout << "\nThanks for using my program!\n";
            break;
        }
        else {
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }
}
