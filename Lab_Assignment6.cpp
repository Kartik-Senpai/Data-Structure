#include <iostream>
#include <iomanip>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];
    int flag[SIZE]; // 0 = empty, 1 = occupied, -1 = deleted

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;
            flag[i] = 0;
        }
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int start = index;
        do {
            if (flag[index] == 0 || flag[index] == -1) {
                table[index] = key;
                flag[index] = 1;
                cout << "Inserted key " << key << " at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
        } while (index != start);
        cout << "Hash table is full! Cannot insert key " << key << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        int start = index;
        do {
            if (flag[index] == 0) {
                cout << "Key " << key << " not found." << endl;
                return;
            }
            if (table[index] == key && flag[index] == 1) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
        } while (index != start);
        cout << "Key " << key << " not found." << endl;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        int start = index;
        do {
            if (flag[index] == 0) {
                cout << "Key not found, cannot delete!" << endl;
                return;
            }
            if (table[index] == key && flag[index] == 1) {
                flag[index] = -1;
                table[index] = -1;
                cout << "Key " << key << " deleted successfully." << endl;
                return;
            }
            index = (index + 1) % SIZE;
        } while (index != start);
        cout << "Key not found!" << endl;
    }

    void display() {
        cout << "\n---------------- HASH TABLE ----------------\n";
        cout << left << setw(10) << "Index" << "Status / Value" << endl;
        cout << "-------------------------------------------\n";

        for (int i = 0; i < SIZE; i++) {
            cout << left << setw(10) << i;
            if (flag[i] == 1)
                cout << table[i];
            else if (flag[i] == -1)
                cout << "Deleted";
            else
                cout << "Empty";
            cout << endl;
        }

        cout << "-------------------------------------------\n";
    }
};

int main() {
    HashTable h;
    int choice, key;

    do {
        cout << "\n========== HASH TABLE MENU ==========\n";
        cout << "1. Insert Key\n";
        cout << "2. Search Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Display Table\n";
        cout << "0. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            h.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            h.search(key);
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            h.deleteKey(key);
            break;
        case 4:
            h.display();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
