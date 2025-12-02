#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int sentinelSearch(int arr[], int n, int key, int &comparisons) {
    comparisons = 0;
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;

    while (arr[i] != key) {
        comparisons++;
        i++;
    }

    arr[n - 1] = last;
    if (i < n - 1 || last == key) return i;
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int choice, key, comparisons, index;

    do {
        cout << "\n====== SEARCH MENU ======\n";
        cout << "1. Linear Search\n";
        cout << "2. Sentinel Search\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to search: ";
                cin >> key;
                index = linearSearch(arr, n, key, comparisons);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found!\n";
                cout << "Comparisons = " << comparisons << endl;
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                index = sentinelSearch(arr, n, key, comparisons);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found!\n";
                cout << "Comparisons = " << comparisons << endl;
                break;

            case 3:
                cout << "Exiting…" << endl;
                break;

            default:
                cout << "Invalid option!\n";
        }
    } while (choice != 3);

    return 0;
}
