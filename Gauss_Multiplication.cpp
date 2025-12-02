#include <iostream>
using namespace std;

long long gauss_calls = 0, gauss_mult = 0, gauss_add = 0;

long long gaussMultiply(long long x, long long y) {
    gauss_calls++;

    if (x < 10 && y < 10) {
        gauss_mult++;
        return x * y;
    }

    long long a = x / 10;
    long long b = x % 10;
    long long c = y / 10;
    long long d = y % 10;

    long long p1 = gaussMultiply(a, c);
    long long p2 = gaussMultiply(b, d);

    gauss_add += 2;
    long long p3 = gaussMultiply(a + b, c + d);

    gauss_add += 2;
    long long mid = p3 - p1 - p2;

    return p1 * 100 + mid * 10 + p2;
}

int main() {
    long long x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    long long result = gaussMultiply(x, y);

    cout << "\nGauss Multiplication Result: " << result << endl;
    cout << "Recursive Calls: " << gauss_calls << endl;
    cout << "Multiplications: " << gauss_mult << endl;
    cout << "Additions/Subtractions: " << gauss_add << endl;

    return 0;
}

