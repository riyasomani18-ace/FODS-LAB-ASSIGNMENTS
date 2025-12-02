#include <iostream>
using namespace std;

struct Triple {
    int row, col, value;
};

void printTuple(Triple t[], int n) {
    cout << "\nRow  Col  Val\n";
    for (int i = 0; i < n; i++)
        cout << t[i].row << "    " << t[i].col << "    " << t[i].value << endl;
}

// =============================
// SIMPLE TRANSPOSE
// =============================
void simpleTranspose(Triple A[], Triple B[], int n) {
    int rows = A[0].row;
    int cols = A[0].col;
    int terms = A[0].value;

    B[0].row = cols;
    B[0].col = rows;
    B[0].value = terms;

    int index = 1;

    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= terms; i++) {
            if (A[i].col == c) {
                B[index].row = A[i].col;
                B[index].col = A[i].row;
                B[index].value = A[i].value;
                index++;
            }
        }
    }
}

// =============================
// FAST TRANSPOSE
// =============================
void fastTranspose(Triple A[], Triple B[], int n) {
    int rows = A[0].row;
    int cols = A[0].col;
    int terms = A[0].value;

    int count[100] = {0};     // Count of each column
    int startPos[100] = {0};  // Starting index in B

    B[0].row = cols;
    B[0].col = rows;
    B[0].value = terms;

    // Count elements in each column of A
    for (int i = 1; i <= terms; i++)
        count[A[i].col]++;

    // Compute starting position for each column
    startPos[0] = 1;
    for (int i = 1; i < cols; i++)
        startPos[i] = startPos[i - 1] + count[i - 1];

    // Fill B using starting positions
    for (int i = 1; i <= terms; i++) {
        int colIndex = A[i].col;
        int pos = startPos[colIndex]++;

        B[pos].row = A[i].col;
        B[pos].col = A[i].row;
        B[pos].value = A[i].value;
    }
}

int main() {
    int rows, cols, terms;

    cout << "Enter number of rows, columns, and non-zero terms: ";
    cin >> rows >> cols >> terms;

    Triple A[100], B1[100], B2[100];

    A[0] = {rows, cols, terms};

    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 1; i <= terms; i++)
        cin >> A[i].row >> A[i].col >> A[i].value;

    // Simple Transpose
    simpleTranspose(A, B1, terms);

    // Fast Transpose
    fastTranspose(A, B2, terms);

    cout << "\nOriginal Sparse Matrix (3-Tuple):";
    printTuple(A, terms + 1);

    cout << "\nSimple Transpose (3-Tuple):";
    printTuple(B1, terms + 1);

    cout << "\nFast Transpose (3-Tuple):";
    printTuple(B2, terms + 1);

    return 0;
}
