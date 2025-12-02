#include <iostream>
#include <cmath>
using namespace std;

long long kara_calls = 0, kara_mult = 0, kara_add = 0;

long long karatsuba(long long x, long long y) {
    kara_calls++;

    if (x < 10 && y < 10) {
        kara_mult++;
        return x * y;
    }

    int n = max((int)log10(x) + 1, (int)log10(y) + 1);
    int m = n / 2;

    long long p = pow(10, m);

    long long a = x / p;
    long long b = x % p;
    long long c = y / p;
    long long d = y % p;

    long long p1 = karatsuba(a, c);
    long long p2 = karatsuba(b, d);

    kara_add += 2;
    long long p3 = karatsuba(a + b, c + d);

    kara_add += 2;
    long long mid = p3 - p1 - p2;

    return p1 * (long long)pow(10, 2 * m) + mid * p + p2;
}

int main() {
    long long x, y;
    cout << "Enter two large integers: ";
    cin >> x >> y;

    long long result = karatsuba(x, y);

    cout << "\nKaratsuba Multiplication Result: " << result << endl;
    cout << "Recursive Calls: " << kara_calls << endl;
    cout << "Multiplications: " << kara_mult << endl;
    cout << "Additions/Subtractions: " << kara_add << endl;

    return 0;
}
