#include <iostream>
#include <string>
using namespace std;

// Node structure for each song
struct Node {
    string songName;
    Node* next;
    Node* prev;
};

// Add song at the end
void addSong(Node*& head, Node*& current, string name) {
    Node* newNode = new Node{name, NULL, NULL};

    if (head == NULL) {
        head = current = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a song by name
void deleteSong(Node*& head, Node*& current, string name) {
    if (head == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->songName != name)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Song not found!" << endl;
        return;
    }

    if (temp == head)
        head = head->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (current == temp)
        current = temp->next != NULL ? temp->next : temp->prev;

    delete temp;
}

// Move to next song
void nextSong(Node*& current) {
    if (current == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    if (current->next == NULL) {
        cout << "Already at last song!" << endl;
        return;
    }
    current = current->next;
}

// Move to previous song
void previousSong(Node*& current) {
    if (current == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    if (current->prev == NULL) {
        cout << "Already at first song!" << endl;
        return;
    }
    current = current->prev;
}

// Display playlist
void displayPlaylist(Node* head, Node* current) {
    if (head == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    cout << "\n--- Playlist ---\n";
    while (head != NULL) {
        if (head == current)
            cout << "> " << head->songName << "  (Currently Playing)\n";
        else
            cout << "  " << head->songName << endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    Node* current = NULL;

    int choice;
    string name;

    while (true) {
        cout << "\n--- Music Playlist Manager ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Next Song\n";
        cout << "4. Previous Song\n";
        cout << "5. Display Playlist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                cin.ignore();
                getline(cin, name);
                addSong(head, current, name);
                break;

            case 2:
                cout << "Enter song name to delete: ";
                cin.ignore();
                getline(cin, name);
                deleteSong(head, current, name);
                break;

            case 3:
                nextSong(current);
                break;

            case 4:
                previousSong(current);
                break;

            case 5:
                displayPlaylist(head, current);
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
