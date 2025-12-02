#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n, long long &comparisons, long long &swaps) {
    comparisons = swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void insertionSort(int arr[], int n, long long &comparisons, long long &shifts) {
    comparisons = shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        comparisons++; // first comparison
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }
        arr[j + 1] = key;
        shifts++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int original[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> original[i];

    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) arr1[i] = original[i];
    for (int i = 0; i < n; i++) arr2[i] = original[i];

    long long compBubble, swapBubble;
    long long compInsertion, shiftInsertion;

    // Bubble Sort
    auto start1 = high_resolution_clock::now();
    bubbleSort(arr1, n, compBubble, swapBubble);
    auto end1 = high_resolution_clock::now();

    long long timeBubble = duration_cast<microseconds>(end1 - start1).count();

    // Insertion Sort
    auto start2 = high_resolution_clock::now();
    insertionSort(arr2, n, compInsertion, shiftInsertion);
    auto end2 = high_resolution_clock::now();

    long long timeInsertion = duration_cast<microseconds>(end2 - start2).count();

    cout << "\n============== SORTED OUTPUT ==============\n";
    cout << "Bubble Sorted Array: ";
    printArray(arr1, n);
    cout << "Insertion Sorted Array: ";
    printArray(arr2, n);

    cout << "\n============== PERFORMANCE REPORT ==============\n";

    cout << "\n--- Bubble Sort ---\n";
    cout << "Comparisons: " << compBubble << endl;
    cout << "Swaps: " << swapBubble << endl;
    cout << "Time Taken: " << timeBubble << " microseconds\n";

    cout << "\n--- Insertion Sort ---\n";
    cout << "Comparisons: " << compInsertion << endl;
    cout << "Shifts: " << shiftInsertion << endl;
    cout << "Time Taken: " << timeInsertion << " microseconds\n";

    cout << "\n============== INSIGHTS ==============\n";

    if (timeBubble < timeInsertion)
        cout << "Bubble Sort was faster on this dataset.\n";
    else
        cout << "Insertion Sort was faster on this dataset.\n";

    if (compBubble < compInsertion)
        cout << "Bubble Sort performed fewer comparisons.\n";
    else
        cout << "Insertion Sort performed fewer comparisons.\n";

    if (swapBubble < shiftInsertion)
        cout << "Bubble Sort did fewer movements.\n";
    else
        cout << "Insertion Sort required fewer element shifts.\n";

    cout << "\nThank you for using the Performance Analyzer! 🚀\n";

    return 0;
}

