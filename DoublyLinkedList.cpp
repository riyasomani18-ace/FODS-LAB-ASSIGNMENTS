#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Insert at beginning
void insertBegin(Node*& head, int value) {
    Node* newNode = new Node{value, head, NULL};
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at specific position
void insertPos(Node*& head, int value, int pos) {
    if (pos == 1) {
        insertBegin(head, value);
        return;
    }

    Node* newNode = new Node{value, NULL, NULL};
    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete from beginning
void deleteBegin(Node*& head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete from end
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
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
}

// Delete from specific position
void deletePos(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 1) {
        deleteBegin(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// Display forward
void displayForward(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "DLL (Forward): ";
    while (head != NULL) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Display reverse
void displayReverse(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    cout << "DLL (Reverse): ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
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

int main() {
    Node* head = NULL;
    int choice, value, pos;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Reverse\n";
        cout << "9. Search Element\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBegin(head, value);
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
                insertPos(head, value, pos);
                break;

            case 4:
                deleteBegin(head);
                break;

            case 5:
                deleteEnd(head);
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletePos(head, pos);
                break;

            case 7:
                displayForward(head);
                break;

            case 8:
                displayReverse(head);
                break;

            case 9:
                cout << "Enter element to search: ";
                cin >> value;
                pos = search(head, value);
                if (pos == -1)
                    cout << "Element not found!" << endl;
                else
                    cout << "Element found at position " << pos << endl;
                break;

            case 10:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
