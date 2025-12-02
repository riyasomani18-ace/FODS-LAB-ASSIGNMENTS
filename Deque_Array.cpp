#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front, rear, capacity;

public:
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    // Insert at front
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot insert " << value << " at front.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }

        arr[front] = value;
        cout << value << " inserted at front.\n";
    }

    // Insert at rear
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot insert " << value << " at rear.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        cout << value << " inserted at rear.\n";
    }

    // Delete from front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Nothing to delete at front.\n";
            return;
        }

        cout << arr[front] << " deleted from front.\n";

        if (front == rear) { // only one element
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // Delete from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! Nothing to delete at rear.\n";
            return;
        }

        cout << arr[rear] << " deleted from rear.\n";

        if (front == rear) { // only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
    }

    // Display deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of deque: ";
    cin >> size;

    Deque dq(size);
    int choice, value;

    while (true) {
        cout << "\n--- Deque Menu ---\n";
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
