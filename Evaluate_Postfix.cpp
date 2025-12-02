#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

// Function to evaluate postfix expression
double evaluatePostfix(const string& postfix) {
    stack<double> st;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        // If token is number
        if (isdigit(token[0])) {
            st.push(stod(token));
        }
        // If token is operator
        else if (token.size() == 1 && string("+-*/^").find(token[0]) != string::npos) {
            if (st.size() < 2) throw runtime_error("Error: Insufficient operands");

            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double res;

            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if (b == 0) throw runtime_error("Error: Division by zero");
                    res = a / b;
                    break;
                case '^': res = pow(a, b); break;
                default: throw runtime_error("Error: Unknown operator");
            }

            st.push(res);
        }
        else {
            throw runtime_error("Error: Invalid token '" + token + "'");
        }
    }

    if (st.size() != 1) throw runtime_error("Error: Invalid postfix expression");

    return st.top();
}

int main() {
    string postfix;

    cout << "Enter a postfix expression (space-separated): ";
    getline(cin, postfix);

    try {
        double result = evaluatePostfix(postfix);
        cout << "Result: " << result << endl;
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}

