#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &comparisons) {
    int low = 0, high = n - 1;
    comparisons = 0;

    while (low <= high) {
        comparisons++;
        int mid = (low + high) / 2;

        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int fibonacciSearch(int arr[], int n, int key, int &comparisons) {
    comparisons = 0;

    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        comparisons++;

        int i = min(offset + fib2, n - 1);

        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > key) {
            fib = fib2;
            fib1 -= fib2;
            fib2 = fib - fib1;
        }
        else return i;
    }

    if (fib1 && arr[offset + 1] == key) {
        comparisons++;
        return offset + 1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int choice, key, comparisons, index;

    do {
        cout << "\n====== SEARCH MENU ======\n";
        cout << "1. Binary Search\n";
        cout << "2. Fibonacci Search\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                index = binarySearch(arr, n, key, comparisons);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found!\n";
                cout << "Comparisons = " << comparisons << endl;
                break;

            case 2:
                cout << "Enter key: ";
                cin >> key;
                index = fibonacciSearch(arr, n, key, comparisons);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found!\n";
                cout << "Comparisons = " << comparisons << endl;
                break;

            case 3:
                cout << "Exiting…\n";
                break;

            default:
                cout << "Invalid option!\n";
        }
    } while (choice != 3);

    return 0;
}

