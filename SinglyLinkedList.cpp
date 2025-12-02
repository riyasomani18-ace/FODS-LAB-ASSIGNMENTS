#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at beginning
void insertBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at specific position
void insertPosition(Node*& head, int value, int pos) {
    if (pos == 1) {
        insertBeginning(head, value);
        return;
    }

    Node* newNode = new Node{value, NULL};
    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at beginning
void deleteBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete at end
void deleteEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete at specific position
void deletePosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 1) {
        deleteBeginning(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Search element
int search(Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

// Display list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Linked List: ";
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int choice, value, pos;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search Element\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(head, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(head, value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insertPosition(head, value, pos);
                break;

            case 4:
                deleteBeginning(head);
                break;

            case 5:
                deleteEnd(head);
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletePosition(head, pos);
                break;

            case 7:
                cout << "Enter element to search: ";
                cin >> value;
                pos = search(head, value);
                if (pos == -1)
                    cout << "Element not found!" << endl;
                else
                    cout << "Element found at position " << pos << endl;
                break;

            case 8:
                display(head);
                break;

            case 9:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

