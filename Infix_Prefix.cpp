#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

// Function to check precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Check if character is operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to reverse a string and swap '(' <-> ')'
string reverseAndSwapParentheses(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    for (char &ch : reversed) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    return reversed;
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> st;
    stringstream postfix;
    int n = infix.length();

    for (int i = 0; i < n; ) {
        char ch = infix[i];

        // Skip spaces
        if (ch == ' ') {
            i++;
            continue;
        }

        // If digit (multi-digit support)
        if (isdigit(ch)) {
            while (i < n && isdigit(infix[i])) {
                postfix << infix[i];
                i++;
            }
            postfix << ' '; // separate operands
        }
        // If '(' push to stack
        else if (ch == '(') {
            st.push(ch);
            i++;
        }
        // If ')' pop until '('
        else if (ch == ')') {
            bool found = false;
            while (!st.empty()) {
                char top = st.top(); st.pop();
                if (top == '(') {
                    found = true;
                    break;
                } else {
                    postfix << top << ' ';
                }
            }
            if (!found) throw runtime_error("Error: Mismatched parentheses");
            i++;
        }
        // If operator
        else if (isOperator(ch)) {
            while (!st.empty() && precedence(st.top()) > precedence(ch)) {
                if (st.top() == '(') break;
                postfix << st.top() << ' ';
                st.pop();
            }
            st.push(ch);
            i++;
        }
        else {
            throw runtime_error(string("Error: Invalid character '") + ch + "'");
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        if (st.top() == '(') throw runtime_error("Error: Mismatched parentheses");
        postfix << st.top() << ' ';
        st.pop();
    }

    return postfix.str();
}

// Convert infix to prefix
string infixToPrefix(const string& infix) {
    string revInfix = reverseAndSwapParentheses(infix);
    string revPostfix = infixToPostfix(revInfix);

    stringstream ss(revPostfix);
    string token, prefix;
    while (ss >> token) {
        prefix = token + " " + prefix;
    }
    return prefix;
}

int main() {
    string infix;

    cout << "Enter a valid infix expression: ";
    getline(cin, infix);

    try {
        string prefix = infixToPrefix(infix);
        cout << "Prefix Expression: " << prefix << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}

