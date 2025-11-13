#include <iostream>
#include <iomanip>
#include <limits> // Used for input cleanup

using namespace std;

#define SIZE 10

// 1. Node structure for chaining
struct Node {
    int key;
    int value;
    Node* next;
};

// 2. HashTable class definition
class HashTable {
private:
    Node* table[SIZE]; // Array of pointers (start of each chain)

    // Hash function using division method: h(k) = k mod m
    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    // Constructor: Initialize all chains to null
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = nullptr;
    }

    // Destructor: Free all dynamically allocated memory
    ~HashTable() {
        for (int i = 0; i < SIZE; ++i) {
            Node* current = table[i];
            Node* next;
            while (current != nullptr) {
                next = current->next;
                delete current;
                current = next;
            }
        }
    }

    // 3. Insert operation: Insert a key-value pair
    void insert(int key, int value) {
        int index = hashFunction(key);
        // Using direct initialization for the new node
        Node* newNode = new Node{key, value, nullptr};

        if (table[index] == nullptr) {
            // No collision: start a new chain
            table[index] = newNode;
        } else {
            // Collision: append to the end of the existing chain (chaining)
            Node* temp = table[index];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }

        cout << "\n[INSERT SUCCESS] Key: " << key << ", Value: " << value << ", Stored at Index: " << index << endl;
    }

    // 4. Search operation: Search for a key
    void search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        
        cout << "\n[SEARCH] Searching for key " << key << " at calculated index " << index << "...\n";

        int position = 0;
        while (temp != nullptr) {
            if (temp->key == key) {
                cout << "[RESULT] Key found! Value: " << temp->value << " (Position in chain: " << position + 1 << ")" << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "[RESULT] Key not found in hash table.\n";
    }

    // 5. Delete operation: Delete a key-value pair
    void deleteKey(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* previous = nullptr;

        cout << "\n[DELETE] Attempting to delete key " << key << " from index " << index << "...\n";

        if (current == nullptr) {
            cout << "[RESULT] Index " << index << " is empty. Deletion failed.\n";
            return;
        }

        // Traverse the chain to find the key
        while (current != nullptr && current->key != key) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "[RESULT] Key not found in the chain.\n";
            return;
        }

        // Case 1: Deleting the head node
        if (previous == nullptr)
            table[index] = current->next;
        // Case 2: Deleting a node in the middle/end
        else
            previous->next = current->next;

        delete current;
        cout << "[RESULT] Key " << key << " deleted successfully from index " << index << ".\n";
    }

    // 6. Display hash table contents
    void display() {
        cout << "\n================== HASH TABLE STATE ======================\n";
        cout << left << setw(8) << "Index" << "| Chain Content (Key, Value)" << endl;
        cout << "------------------------------------------------------------\n";
        for (int i = 0; i < SIZE; i++) {
            cout << left << setw(8) << i << "| ";
            Node* temp = table[i];
            
            if (temp == nullptr) {
                cout << "(Empty)";
            } else {
                while (temp != nullptr) {
                    cout << "(" << temp->key << ", " << temp->value << ")";
                    if (temp->next != nullptr)
                        cout << " --> ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }

        cout << "--------------------------------------------------------------------\n";
    }
};

// Main function for interactive demonstration
int main() {
    HashTable h;
    int choice, key, value;

    // Interactive menu loop
    do {
        cout << "\n========== HASH TABLE MENU (SIZE " << SIZE << ") ==========\n";
        cout << "1. Insert Key-Value Pair\n";
        cout << "2. Search Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Display Hash Table\n";
        cout << "0. Exit\n";
        cout << "------------------------------------------------\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Clearing stream and exiting menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0; // Exit loop on bad input
        }

        switch (choice) {
            case 1:
                cout << "\nEnter Key: ";
                cin >> key;
                cout << "Enter Value: ";
                cin >> value;
                h.insert(key, value);
                break;

            case 2:
                cout << "\nEnter Key to Search: ";
                cin >> key;
                h.search(key);
                break;

            case 3:
                cout << "\nEnter Key to Delete: ";
                cin >> key;
                h.deleteKey(key);
                break;

            case 4:
                h.display();
                break;

            case 0:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please select 1, 2, 3, 4, or 0.\n";
        }

    } while (choice != 0);

    return 0;
}
