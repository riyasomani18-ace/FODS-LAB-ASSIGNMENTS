#include <iostream>
using namespace std;

// Recursive factorial function
long long factorial(int n) {
    if (n <= 1) return 1; // base case
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers!" << endl;
        return 0;
    }

    long long result = factorial(n);
    cout << "Factorial of " << n << " is " << result << endl;

    return 0;
}
