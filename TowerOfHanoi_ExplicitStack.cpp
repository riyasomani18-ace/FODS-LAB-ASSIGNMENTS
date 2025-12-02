#include <iostream>
#include <stack>
using namespace std;

struct Move {
    int n;
    char from, to, aux;
};

void towerOfHanoiIterative(int n, char from, char to, char aux) {
    stack<Move> st;
    st.push({n, from, to, aux});

    int moves = 0;

    while (!st.empty()) {
        Move curr = st.top();
        st.pop();

        if (curr.n == 1) {
            cout << "Move disk 1 from " << curr.from << " to " << curr.to << endl;
            moves++;
        } else if (curr.n > 1) {
            // Push moves in reverse order of recursion
            st.push({curr.n - 1, curr.aux, curr.to, curr.from}); // Step 3
            st.push({1, curr.from, curr.to, curr.aux});           // Step 2
            st.push({curr.n - 1, curr.from, curr.aux, curr.to}); // Step 1
        }
    }

    cout << "\nTotal moves: " << moves << endl;
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nTower of Hanoi Moves (Iterative using Stack):\n";
    towerOfHanoiIterative(n, 'A', 'C', 'B');

    return 0;
}

