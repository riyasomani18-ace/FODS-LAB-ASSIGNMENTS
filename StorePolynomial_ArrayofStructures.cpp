#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

// Function to input polynomial
void inputPoly(Term p[], int n) {
    cout << "\nEnter each term as: coefficient exponent\n";
    for (int i = 0; i < n; i++) {
        cout << "Term " << i+1 << ": ";
        cin >> p[i].coeff >> p[i].exp;
    }
}

// Function to display polynomial
void displayPoly(Term p[], int n) {
    for (int i = 0; i < n; i++) {
        if (p[i].coeff != 0) {
            cout << p[i].coeff << "x^" << p[i].exp;
            if (i != n - 1)
                cout << " + ";
        }
    }
    cout << endl;
}

// Polynomial Addition using structure array
int addPoly(Term p1[], int n1, Term p2[], int n2, Term result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (p1[i].exp == p2[j].exp) {
            result[k].coeff = p1[i].coeff + p2[j].coeff;
            result[k].exp = p1[i].exp;
            i++; j++; k++;
        }
        else if (p1[i].exp > p2[j].exp) {
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

    // Multiply all pairs of terms
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result[k].coeff = p1[i].coeff * p2[j].coeff;
            result[k].exp = p1[i].exp + p2[j].exp;
            k++;
        }
    }

    // Combine like terms
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (result[i].exp == result[j].exp) {
                result[i].coeff += result[j].coeff;
                result[j].coeff = 0;  // eliminate duplicate term
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
