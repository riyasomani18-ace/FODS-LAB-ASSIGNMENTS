#include <iostream>
using namespace std;

// Structure to store a polynomial term
struct Term {
    int coeff;  // coefficient
    int power;  // power of x
};

// Function to input polynomial
void inputPoly(Term poly[], int n) {
    cout << "\nEnter the terms (coefficient and power):\n";
    for (int i = 0; i < n; i++) {
        cout << "Term " << i + 1 << ": ";
        cin >> poly[i].coeff >> poly[i].power;
    }
}

// Function to display polynomial
void displayPoly(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        cout << poly[i].coeff << "x^" << poly[i].power;
        if (i != n - 1)
            cout << " + ";
    }
    cout << endl;
}

// Polynomial Addition
int addPoly(Term p1[], int n1, Term p2[], int n2, Term result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (p1[i].power == p2[j].power) {
            result[k].coeff = p1[i].coeff + p2[j].coeff;
            result[k].power = p1[i].power;
            i++; j++; k++;
        }
        else if (p1[i].power > p2[j].power) {
            result[k] = p1[i];
            i++; k++;
        }
        else {
            result[k] = p2[j];
            j++; k++;
        }
    }

    while (i < n1) result[k++] = p1[i++];
    while (j < n2) result[k++] = p2[j++];

    return k;
}

// Polynomial Multiplication
int multiplyPoly(Term p1[], int n1, Term p2[], int n2, Term result[]) {
    int k = 0;

    // Multiply each term
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result[k].coeff = p1[i].coeff * p2[j].coeff;
            result[k].power = p1[i].power + p2[j].power;
            k++;
        }
    }

    // Combine like terms
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (result[i].power == result[j].power) {
                result[i].coeff += result[j].coeff;
                result[j].coeff = 0;
            }
        }
    }

    return k;
}

int main() {
    int n1, n2;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;
    Term p1[n1];

    cout << "Enter number of terms in second polynomial: ";
    cin >> n2;
    Term p2[n2];

    inputPoly(p1, n1);
    inputPoly(p2, n2);

    cout << "\nPolynomial 1: ";
    displayPoly(p1, n1);

    cout << "Polynomial 2: ";
    displayPoly(p2, n2);

    // Addition
    Term addResult[n1 + n2];
    int addSize = addPoly(p1, n1, p2, n2, addResult);

    cout << "\nAddition Result: ";
    displayPoly(addResult, addSize);

    // Multiplication
    Term mulResult[n1 * n2];
    int mulSize = multiplyPoly(p1, n1, p2, n2, mulResult);

    cout << "\nMultiplication Result: ";
    displayPoly(mulResult, mulSize);

    return 0;
}
