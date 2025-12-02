#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    int priority; // lower value = higher priority (you can invert if needed)
    Node* next;
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    // Insert based on priority
    void enqueue(int value, int prio) {
        Node* newNode = new Node{value, prio, nullptr};

        // If queue is empty or new node has higher priority than front
        if (isEmpty() || prio < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            // Traverse to find correct position
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority <= prio) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << value << " inserted with priority " << prio << ".\n";
    }

    // Delete element with highest priority (lowest number)
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow! Nothing to delete.\n";
            return;
        }

        Node* temp = front;
        cout << front->data << " dequeued (priority " << front->priority << ").\n";
        front = front->next;
        delete temp;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty.\n";
            return;
        }

        cout << "Queue elements (Data : Priority): ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << ":" << temp->priority << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value, priority;

    while (true) {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter priority (lower number = higher priority): ";
                cin >> priority;
                pq.enqueue(value, priority);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
