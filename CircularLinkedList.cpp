#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at beginning
void insertBegin(Node*& tail, int value) {
    Node* newNode = new Node{value, NULL};

    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
        return;
    }

    newNode->next = tail->next;
    tail->next = newNode;
}

// Insert at end
void insertEnd(Node*& tail, int value) {
    insertBegin(tail, value);
    tail = tail->next; // update tail to new last node
}

// Delete from beginning
void deleteBegin(Node*& tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* head = tail->next;

    if (tail == head) { // Only one node
        delete head;
        tail = NULL;
        return;
    }

    tail->next = head->next;
    delete head;
}

// Delete from end
void deleteEnd(Node*& tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* head = tail->next;

    if (tail == head) { // Only one node
        delete tail;
        tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != tail)
        temp = temp->next;

    temp->next = tail->next;
    delete tail;
    tail = temp;
}

// Traverse & display
void display(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = tail->next;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(head)" << endl;
}

// Search element
bool search(Node* tail, int key) {
    if (tail == NULL) return false;

    Node* temp = tail->next;
    do {
        if (temp->data == key) return true;
        temp = temp->next;
    } while (temp != tail->next);

    return false;
}

int main() {
    Node* tail = NULL; // tail pointer of circular list
    int choice, value;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display List\n";
        cout << "6. Search Element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBegin(tail, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(tail, value);
                break;

            case 3:
                deleteBegin(tail);
                break;

            case 4:
                deleteEnd(tail);
                break;

            case 5:
                display(tail);
                break;

            case 6:
                cout << "Enter element to search: ";
                cin >> value;
                if (search(tail, value))
                    cout << "Element found!" << endl;
                else
                    cout << "Element not found!" << endl;
                break;

            case 7:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
