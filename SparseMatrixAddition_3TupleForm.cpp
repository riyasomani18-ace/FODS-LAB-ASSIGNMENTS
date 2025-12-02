#include <iostream>
using namespace std;

struct Triple {
    int row, col, value;
};

void printTuple(Triple A[], int n) {
    cout << "\nRow  Col  Val\n";
    for (int i = 0; i < n; i++)
        cout << A[i].row << "    " << A[i].col << "     " << A[i].value << endl;
}

int main() {
    int r1, c1, t1, r2, c2, t2;

    cout << "Enter rows, cols & non-zero terms for Matrix A: ";
    cin >> r1 >> c1 >> t1;

    cout << "Enter rows, cols & non-zero terms for Matrix B: ";
    cin >> r2 >> c2 >> t2;

    if (r1 != r2 || c1 != c2) {
        cout << "Matrix dimensions must match for addition!";
        return 0;
    }

    Triple A[100], B[100], C[200];

    A[0] = {r1, c1, t1};
    B[0] = {r2, c2, t2};

    cout << "\nEnter (row col value) for Matrix A:\n";
    for (int i = 1; i <= t1; i++)
        cin >> A[i].row >> A[i].col >> A[i].value;

    cout << "\nEnter (row col value) for Matrix B:\n";
    for (int i = 1; i <= t2; i++)
        cin >> B[i].row >> B[i].col >> B[i].value;

    int i = 1, j = 1, k = 1;

    // Header for result matrix
    C[0] = {r1, c1, 0};

    // Merge-like addition
    while (i <= t1 && j <= t2) {

        // Compare positions (row-major order)
        if (A[i].row < B[j].row ||
            (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        else if (B[j].row < A[i].row ||
                 (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        }
        else { // Same position → add values
            int sum = A[i].value + B[j].value;
            if (sum != 0) {
                C[k++] = {A[i].row, A[i].col, sum};
            }
            i++;
            j++;
        }
    }

    // Copy remaining elements
    while (i <= t1) C[k++] = A[i++];
    while (j <= t2) C[k++] = B[j++];

    // Update non-zero count
    C[0].value = k - 1;

    // Output
    cout << "\nSparse Matrix A (3-tuple):";
    printTuple(A, t1 + 1);

    cout << "\nSparse Matrix B (3-tuple):";
    printTuple(B, t2 + 1);

    cout << "\nResultant Sparse Matrix C = A + B (3-tuple):";
    printTuple(C, C[0].value + 1);

    return 0;
}
