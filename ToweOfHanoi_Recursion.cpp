#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux, int& moves) {
    if (n == 0) return;

    // Move n-1 disks from 'from' to 'aux'
    towerOfHanoi(n - 1, from, aux, to, moves);

    // Move nth disk from 'from' to 'to'
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    moves++;

    // Move n-1 disks from 'aux' to 'to'
    towerOfHanoi(n - 1, aux, to, from, moves);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    int moves = 0;
    cout << "\nTower of Hanoi Moves:\n";
    towerOfHanoi(n, 'A', 'C', 'B', moves);

    cout << "\nTotal moves: " << moves << endl;
    return 0;
}
