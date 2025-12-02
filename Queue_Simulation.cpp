#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Structure to represent a print job
struct PrintJob {
    int jobId;
    string documentName;
    int pages;
};

int main() {
    queue<PrintJob> printQueue;
    int choice;
    int nextJobId = 1;

    cout << "--- Printer Spooling Simulation ---\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Next Job\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clear newline

        switch (choice) {
            case 1: {
                PrintJob job;
                job.jobId = nextJobId++;

                cout << "Enter document name: ";
                getline(cin, job.documentName);

                cout << "Enter number of pages: ";
                cin >> job.pages;
                cin.ignore();

                printQueue.push(job);
                cout << "Print Job [" << job.jobId << "] added to the queue.\n";
                break;
            }

            case 2: {
                if (printQueue.empty()) {
                    cout << "No jobs to process. Queue is empty.\n";
                } else {
                    PrintJob job = printQueue.front();
                    printQueue.pop();
                    cout << "Processing Job [" << job.jobId << "] - "
                         << job.documentName << " (" << job.pages << " pages)\n";
                }
                break;
            }

            case 3: {
                if (printQueue.empty()) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Current Print Queue:\n";
                    queue<PrintJob> tempQueue = printQueue;
                    while (!tempQueue.empty()) {
                        PrintJob job = tempQueue.front();
                        tempQueue.pop();
                        cout << "Job [" << job.jobId << "] - "
                             << job.documentName << " (" << job.pages << " pages)\n";
                    }
                }
                break;
            }

            case 4:
                cout << "Exiting simulation...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

