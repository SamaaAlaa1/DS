#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

template <typename T>
class Poly {
private:
    int order;
    T* coefficients;

public:
    Poly() : order(0), coefficients(nullptr) {}

    Poly(int ord) : order(ord), coefficients(new T[order + 2]()) {}

    ~Poly() {
        delete[] coefficients;
    }

    int getOrder() const { return order; }

    void setOrder(int o) {
        order = o;
        delete[] coefficients;
        coefficients = new T[order + 2]();
    }

    T* getCoefficients() const { return coefficients; }

    void input_Polynomial(istream& input) {
        for (int i = 0; i <= order + 1; i++) {
            input >> coefficients[i];
        }
    }

    void display_Polynomial() const {
        bool firstTerm = true;

        for (int i = order + 1; i > 0; i--) {
            if (coefficients[i] != 0) {
                if (!firstTerm) {
                    cout << (coefficients[i] > 0 ? " + " : " - ");
                } else if (coefficients[i] < 0) {
                    cout << "-";
                }

                T absCoeff = abs(coefficients[i]);
                if (i - 1 == 1) {
                    cout << absCoeff << "X";
                }
                else if (i - 1 > 1) {
                    cout << absCoeff << "X^" << (i - 1);
                }
                else {
                    cout << absCoeff;
                }

                firstTerm = false;
            }
        }

        if (firstTerm) {
            cout << "0";
        }

        cout << " = " << coefficients[0] << endl;
    }
};


template <typename T>
void sumTwoPoly(const Poly<T>& a, const Poly<T>& b, Poly<T>& result) {
    int maxOrder = max(a.getOrder(), b.getOrder());
    result.setOrder(maxOrder);

    for (int i = 0; i <= maxOrder + 1; i++) {
        T aCoeff = (i <= a.getOrder() + 1) ? a.getCoefficients()[i] : 0;
        T bCoeff = (i <= b.getOrder() + 1) ? b.getCoefficients()[i] : 0;
        result.getCoefficients()[i] = aCoeff + bCoeff;
    }
}


template <typename T>
void differenceTwoPoly(const Poly<T>& a, const Poly<T>& b, Poly<T>& result) {
    int maxOrder = max(a.getOrder(), b.getOrder());
    result.setOrder(maxOrder);

    for (int i = 0; i <= maxOrder + 1; i++) {
        T aCoeff = (i <= a.getOrder() + 1) ? a.getCoefficients()[i] : 0;
        T bCoeff = (i <= b.getOrder() + 1) ? b.getCoefficients()[i] : 0;
        result.getCoefficients()[i] = bCoeff - aCoeff;
    }
}


template <typename T>
bool processTestCase(istream& input, bool fromFile) {
    int first_order, second_order;

    if (fromFile) {
        if (!(input >> first_order)) return false;
    }
    else {
        cout << "Enter order of first polynomial: ";
        input >> first_order;
    }

    Poly<T> p1(first_order);

    if (fromFile) {
        cout << "Reading first polynomial coefficients from file..." << endl;
    }
    else {
        cout << "Enter coefficients for first polynomial (highest to lowest order): ";
    }
    p1.input_Polynomial(input);

    if (fromFile) {
        if (!(input >> second_order)) return false;
    }
    else {
        cout << "Enter order of second polynomial: ";
        input >> second_order;
    }

    Poly<T> p2(second_order);

    if (fromFile) {
        cout << "Reading second polynomial coefficients from file..." << endl;
    }
    else {
        cout << "Enter coefficients for second polynomial (highest to lowest order): ";
    }
    p2.input_Polynomial(input);

    cout << "\nFirst polynomial: ";
    p1.display_Polynomial();
    cout << "Second polynomial: ";
    p2.display_Polynomial();

    Poly<T> sumResult;
    sumTwoPoly(p1, p2, sumResult);
    cout << "Sum of polynomials: ";
    sumResult.display_Polynomial();

    Poly<T> diffResult;
    differenceTwoPoly(p1, p2, diffResult);
    cout << "Difference of polynomials: ";
    diffResult.display_Polynomial();

    return true;
}


int main() {
    char choice;
    cout << "Read from file? (y/n): ";
    cin >> choice;
    cin.ignore();

    if (choice == 'y' || choice == 'Y') {
        string filename;
        cout << "Enter filename: ";
        getline(cin, filename);

        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return 1;
        }

        int testCase = 1;
        while (true) {
            cout << "\n=== Test Case " << testCase << " ===" << endl;
            if (!processTestCase<double>(file, true)) break;
            testCase++;

            cout << "\nProcess another test case? (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y') break;
            cin.ignore();
        }
        file.close();
    }
    else {
        int testCase = 1;
        do {
            cout << "\n=== Test Case " << testCase << " ===" << endl;
            processTestCase<double>(cin, false);
            testCase++;

            cout << "\nEnter another test case? (y/n): ";
            cin >> choice;
            cin.ignore();
        } while (choice == 'y' || choice == 'Y');
    }

    return 0;
}
