#include <iostream>
#include <string>
using namespace std;

struct GLL {
    int tag;         // 0 = atom, 1 = sublist
    string data;     // used when tag = 0
    GLL* sublist;    // used when tag = 1
    GLL* next;       // next node in same list
};

// Create atom node
GLL* createAtom(string value) {
    GLL* temp = new GLL();
    temp->tag = 0;
    temp->data = value;
    temp->sublist = NULL;
    temp->next = NULL;
    return temp;
}

// Create sublist node
GLL* createSublist(GLL* list) {
    GLL* temp = new GLL();
    temp->tag = 1;
    temp->sublist = list;
    temp->next = NULL;
    return temp;
}

// Build GLL interactively
GLL* buildGLL() {
    int choice;
    cout << "\n1. Atom\n2. Sublist\n3. End List\nEnter choice: ";
    cin >> choice;

    if (choice == 3) return NULL;

    GLL* head = NULL;
    GLL* tail = NULL;

    while (choice != 3) {
        GLL* node = NULL;

        if (choice == 1) {
            string val;
            cout << "Enter atom value: ";
            cin >> val;
            node = createAtom(val);
        }
        else if (choice == 2) {
            cout << "Creating sublist...\n";
            node = createSublist(buildGLL());
        }

        if (head == NULL)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }

        cout << "\n1. Atom\n2. Sublist\n3. End List\nEnter choice: ";
        cin >> choice;
    }

    return head;
}

// Display the GLL in proper format
void displayGLL(GLL* head) {
    cout << "(";
    while (head != NULL) {
        if (head->tag == 0) {
            cout << head->data; // print atom
        }
        else {
            displayGLL(head->sublist); // print sublist
        }

        head = head->next;
        if (head != NULL) cout << ", ";
    }
    cout << ")";
}

int main() {
    cout << "Build your Generalized Linked List:\n";
    GLL* gll = buildGLL();

    cout << "\nGeneralized Linked List: ";
    displayGLL(gll);

    cout << endl;
    return 0;
}

