#include "StatisticalCalculation.h"

template <class T>
StatisticalCalculation<T>::StatisticalCalculation() {
    size = 0; // Fix: Initialize size
    data = nullptr;
}

template <class T>
StatisticalCalculation<T>::~StatisticalCalculation() {
    if (data) {
        delete[] data;
        data = nullptr;
    }
}

template <class T>
void StatisticalCalculation<T>::sort() {
    if (size > 0) {
        std::sort(data, data + size);
    }
}

template <class T>
T StatisticalCalculation<T>::findMedian() {
    if (size == 0) {
        throw runtime_error("Cannot find median of an empty dataset.");
    }
    sort();
    if (size % 2 == 0) {
        return static_cast<double>(data[size / 2 - 1] + data[size / 2]) / 2;
    }
    return data[size / 2];
}

template <class T>
T StatisticalCalculation<T>::findMax() {
    if (size == 0) {
        throw runtime_error("Dataset is empty.");
    }
    sort();
    return data[size - 1];
}

template <class T>
T StatisticalCalculation<T>::findMin() {
    if (size == 0) {
        throw runtime_error("Dataset is empty.");
    }
    sort();
    return data[0];
}

template <class T>
double StatisticalCalculation<T>::findMean() {
    if (size == 0) {
        throw runtime_error("Dataset is empty.");
    }
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return static_cast<double>(sum) / size;
}

template <class T>
T StatisticalCalculation<T>::findSummation() {
    if (size == 0) {
        throw runtime_error("Dataset is empty.");
    }
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

template <class T>
void StatisticalCalculation<T>::displayArray() {
    if (size == 0) {
        cout << "No data available.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << '\n';
}

template <class T>
void StatisticalCalculation<T>::inputData() {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> data[i];
    }
}

template <class T>
void StatisticalCalculation<T>::statisticsMenu() {
    cout << "Welcome to the Statistical Calculation Program!\n";
    while (true) {
        int choice1;
        cout << "\nSelect an option:\n1. Enter the input\n2. Input from file\n3. Exit Program.\nEnter Your Choice: ";
        cin >> choice1;
        if (choice1 == 1) {
            cout << "Enter number of elements: ";
            cin >> size;
            if (size <= 0) {
                cout << "Invalid size!\n";
                continue;
            }
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

            try {
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
            } catch (const exception& e) {
                cout << "Error: " << e.what() << '\n';
            }
        }
        else if (choice1 == 2) {
            string filename = "TestCasesForStatisticalCalculation.txt";
            ifstream file(filename);
            if (!file) {
                cout << "Error: Cannot open file " << filename << '\n';
                continue;
            }
            while (file >> size) {
                if (size <= 0) {
                    cout << "Invalid size in file!\n";
                    continue;
                }
                delete[] data;
                data = new T[size];
                for (int i = 0; i < size; i++) {
                    file >> data[i];
                }
                int choice;
                file >> choice;
                cout << "\nProcessing test case from file:\n";
                try {
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
                }
                catch (const exception& e) {
                    cout << "Error: " << e.what() << '\n';
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