#include <iostream>
#include <stack>
using namespace std;

long long factorialStack(int n) {
    if (n < 0) {
        throw runtime_error("Factorial is not defined for negative numbers");
    }

    stack<int> st;
    long long result = 1;

    // Push all numbers onto stack
    for (int i = n; i > 1; i--)
        st.push(i);

    // Pop and multiply
    while (!st.empty()) {
        result *= st.top();
        st.pop();
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    try {
        long long result = factorialStack(n);
        cout << "Factorial of " << n << " is " << result << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
