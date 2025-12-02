#include <iostream>
using namespace std;

class LinearQueue {
private:
    int front, rear, capacity;
    int* queue;

public:
    LinearQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    ~LinearQueue() {
        delete[] queue;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (isEmpty()) front = 0;
        queue[++rear] = value;
        cout << value << " inserted into queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }

        cout << queue[front] << " removed from queue.\n";

        if (front == rear) { // Queue becomes empty
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Peek front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element: " << queue[front] << endl;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter queue capacity: ";
    cin >> size;

    LinearQueue q(size);
    int choice, value;

    while (true) {
        cout << "\n--- Linear Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
