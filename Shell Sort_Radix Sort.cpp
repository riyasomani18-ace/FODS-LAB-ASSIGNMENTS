#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

// -------------------------------------------------------------
// SHELL SORT
// -------------------------------------------------------------
void shellSort(int arr[], int n, long long &comparisons, long long &swaps) {
    comparisons = swaps = 0;

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            comparisons++;  // comparison for entering loop
            while (j >= gap && arr[j - gap] > temp) {
                comparisons++;
                arr[j] = arr[j - gap];
                swaps++;
                j -= gap;
            }

            arr[j] = temp;
            swaps++;
        }
    }
}

// -------------------------------------------------------------
// RADIX SORT (Counting Sort as subroutine)
// Tracks number of comparisons & swaps (movement operations)
// -------------------------------------------------------------
void countingSort(int arr[], int n, int exp, long long &comparisons, long long &swaps) {
    int output[n];
    int count[10] = {0};

    // Count occurrences
    for (int i = 0; i < n; i++) {
        comparisons++;
        count[(arr[i] / exp) % 10]++;
    }

    // Convert to cumulative count
    for (int i = 1; i < 10; i++) {
        comparisons++;
        count[i] += count[i - 1];
    }

    // Build output
    for (int i = n - 1; i >= 0; i--) {
        comparisons++;
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        swaps++;
        count[index]--;
    }

    // Copy back
    for (int i = 0; i < n; i++) {
        comparisons++;
        arr[i] = output[i];
        swaps++;
    }
}

void radixSort(int arr[], int n, long long &comparisons, long long &swaps) {
    comparisons = swaps = 0;

    // Find max element
    int maxNum = arr[0];
    for (int i = 1; i < n; i++) {
        comparisons++;
        if (arr[i] > maxNum) maxNum = arr[i];
    }

    // Apply counting sort for every digit
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        comparisons++;
        countingSort(arr, n, exp, comparisons, swaps);
    }
}

// -------------------------------------------------------------
// PRINT ARRAY
// -------------------------------------------------------------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// -------------------------------------------------------------
// MAIN PROGRAM
// -------------------------------------------------------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int original[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> original[i];

    // Copies for both algorithms
    int arrShell[n], arrRadix[n];
    for (int i = 0; i < n; i++) {
        arrShell[i] = original[i];
        arrRadix[i] = original[i];
    }

    long long compShell, swapShell;
    long long compRadix, swapRadix;

    // ---------------------------------------------------------
    // SHELL SORT
    // ---------------------------------------------------------
    auto start1 = high_resolution_clock::now();
    shellSort(arrShell, n, compShell, swapShell);
    auto end1 = high_resolution_clock::now();
    long long timeShell = duration_cast<microseconds>(end1 - start1).count();

    // ---------------------------------------------------------
    // RADIX SORT
    // ---------------------------------------------------------
    auto start2 = high_resolution_clock::now();
    radixSort(arrRadix, n, compRadix, swapRadix);
    auto end2 = high_resolution_clock::now();
    long long timeRadix = duration_cast<microseconds>(end2 - start2).count();

    // ---------------------------------------------------------
    // OUTPUTS
    // ---------------------------------------------------------
    cout << "\n============== SORTED OUTPUT ==============\n";
    cout << "Shell Sort Output: ";
    printArray(arrShell, n);
    cout << "Radix Sort Output: ";
    printArray(arrRadix, n);

    cout << "\n============== PERFORMANCE REPORT ==============\n";

    cout << "\n--- Shell Sort ---\n";
    cout << "Comparisons: " << compShell << endl;
    cout << "Swaps/Shifts: " << swapShell << endl;
    cout << "Time Taken: " << timeShell << " microseconds\n";

    cout << "\n--- Radix Sort ---\n";
    cout << "Comparisons: " << compRadix << endl;
    cout << "Swaps/Moves: " << swapRadix << endl;
    cout << "Time Taken: " << timeRadix << " microseconds\n";

    cout << "\n============== INSIGHTS ==============\n";

    if (timeShell < timeRadix)
        cout << "Shell Sort was faster on this dataset.\n";
    else
        cout << "Radix Sort was faster because it is non-comparative and digit-based.\n";

    if (compShell < compRadix)
        cout << "Shell Sort performed fewer comparisons.\n";
    else
        cout << "Radix Sort made fewer or equal comparisons due to digit-wise processing.\n";

    if (swapShell < swapRadix)
        cout << "Shell Sort required fewer data movements.\n";
    else
        cout << "Radix Sort required fewer movements.\n";

    cout << "\nThank you for using the Sort Performance Analyzer! 🚀\n";

    return 0;
}

