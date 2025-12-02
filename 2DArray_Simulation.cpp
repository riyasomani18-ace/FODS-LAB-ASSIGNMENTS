#include <iostream>
#include <vector>
using namespace std;

class TwoDArray {
private:
    int rows, cols;
    vector<int> arr;   // 1D array simulating 2D

public:
    TwoDArray(int r, int c) : rows(r), cols(c) {
        arr.resize(r * c, 0);
    }

    // Row-major index formula: index = r * cols + c
    int rowMajorIndex(int r, int c) {
        return r * cols + c;
    }

    // Column-major index formula: index = c * rows + r
    int colMajorIndex(int r, int c) {
        return c * rows + r;
    }

    // Insert value
    void insert(int r, int c, int val) {
        arr[rowMajorIndex(r, c)] = val;
    }

    // Delete -> set value to 0
    void remove(int r, int c) {
        arr[rowMajorIndex(r, c)] = 0;
    }

    // Merge another 2D array
    void merge(TwoDArray &other) {
        if (other.rows != rows || other.cols != cols) {
            cout << "Merge failed: Dimensions mismatch." << endl;
            return;
        }
        for (int i = 0; i < rows * cols; i++) {
            arr[i] += other.arr[i];
        }
    }

    // Display row-major memory layout
    void printRowMajorWithAddress() {
        cout << "\nRow-Major Order (Value : Address):\n";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int idx = rowMajorIndex(r, c);
                cout << arr[idx] << " : " << ( &arr[idx] ) << "   ";
            }
            cout << endl;
        }
    }

    // Display column-major memory layout
    void printColMajorWithAddress() {
        cout << "\nColumn-Major Order (Value : Address):\n";
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                int idx = colMajorIndex(r, c);
                cout << arr[idx] << " : " << ( &arr[idx] ) << "   ";
            }
            cout << endl;
        }
    }

    // Print full 2D structure
    void print2D() {
        cout << "\n2D Structure:\n";
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << arr[rowMajorIndex(r, c)] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    int r = 3, c = 3;

    TwoDArray A(r, c);
    TwoDArray B(r, c);

    // Insert Values (Demo)
    A.insert(0, 0, 5);
    A.insert(0, 1, 7);
    A.insert(1, 2, 9);

    cout << "\nOriginal Array A:";
    A.print2D();

    // Delete a value
    A.remove(0, 1);

    cout << "\nAfter Deleting A[0][1]:";
    A.print2D();

    // Insert in B for merging
    B.insert(0, 0, 2);
    B.insert(1, 2, 3);

    cout << "\nArray B:";
    B.print2D();

    // Merge A and B
    A.merge(B);

    cout << "\nAfter Merging A and B:";
    A.print2D();

    // Print Memory Layouts
    A.printRowMajorWithAddress();
    A.printColMajorWithAddress();

    return 0;
}
