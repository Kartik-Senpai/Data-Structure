#include <iostream>
using namespace std;

#define MAX 10

class CallQueue {
    int front, rear;
    int customerID[MAX];
    int callTime[MAX];

public:
    // Constructor to initialize queue
    CallQueue() {
        front = -1;
        rear = -1;
    }

    // Function to add a call to the queue
    void addCall(int id, int time) {
        if (rear == MAX - 1) {
            cout << "Queue is full. Cannot add more calls.\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        customerID[rear] = id;
        callTime[rear] = time;

        cout << "Call added for Customer ID: " << id 
             << " with call time: " << time << " minutes.\n";
    }

    // Function to answer and remove the first call
    void answerCall() {
        if (isQueueEmpty()) {
            cout << "No calls to answer. Queue is empty.\n";
            return;
        }
        cout << "Answering call of Customer ID: " << customerID[front] 
             << " (Call time: " << callTime[front] << " minutes).\n";
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue when empty
        }
    }

    // Function to display all calls in the queue
    void viewQueue() {
        if (isQueueEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "\nCurrent Call Queue:\n";
        cout << "---------------------------------------\n";
        cout << "Customer ID\t|\tCall Time (minutes)\n";
        cout << "---------------------------------------\n";
        for (int i = front; i <= rear; i++) {
            cout << customerID[i] << "\t\t|\t" << callTime[i] << endl;
        }
        cout << "---------------------------------------\n";
    }

    // Function to check if queue is empty
    bool isQueueEmpty() {
        return (front == -1 || front > rear);
    }
};

int main() {
    CallQueue cq;
    int choice, id, time;

    do {
        cout << "\n--- Call Center Queue Menu ---\n";
        cout << "1. Add Call\n";
        cout << "2. Answer Call\n";
        cout << "3. View Queue\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter Call Time (in minutes): ";
                cin >> time;
                cq.addCall(id, time);
                break;

            case 2:
                cq.answerCall();
                break;

            case 3:
                cq.viewQueue();
                break;

            case 4:
                if (cq.isQueueEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
