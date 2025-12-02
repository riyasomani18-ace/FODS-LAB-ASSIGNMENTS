#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int amount;

    cout << "Enter amount: ";
    cin >> amount;

    vector<int> used;

    for (int c : coins) {
        while (amount >= c) {
            amount -= c;
            used.push_back(c);
        }
    }

    cout << "\nCoins/Notes Used:\n";
    for (int x : used) cout << x << " ";

    cout << "\nTotal Count: " << used.size() << endl;
    return 0;
}

