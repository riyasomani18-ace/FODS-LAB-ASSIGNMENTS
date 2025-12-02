#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long comparisons = 0;
long long swapsCount = 0;

// Swapping with counter
void swapCount(int &a, int &b) {
    swapsCount++;
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swapCount(arr[i], arr[j]);
        }
    }
    swapCount(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Clone original array for reporting
    vector<int> original = arr;

    // Start time
    auto start = high_resolution_clock::now();

    // Sorting
    quickSort(arr, 0, n - 1);

    // End time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Output
    cout << "\n==================== Quick Sort Report ====================\n";
    cout << "Original Array: ";
    for (int x : original) cout << x << " ";

    cout << "\nSorted Array:   ";
    for (int x : arr) cout << x << " ";

    cout << "\n------------------------------------------------------------\n";
    cout << "Time Taken          : " << duration.count() << " microseconds\n";
    cout << "Total Comparisons   : " << comparisons << "\n";
    cout << "Total Swaps         : " << swapsCount << "\n";
    cout << "------------------------------------------------------------\n";
    cout << "Insight: Quick Sort shines with O(n log n) avg performance, \n"
         << "but can fall back to O(n²) if pivoting goes sideways.\n"
         << "Still a corporate favorite for fast, scalable workloads.\n";
    cout << "============================================================\n";

    return 0;
}

