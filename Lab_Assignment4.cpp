#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Student class
class Student {
public:
    int rollNo;
    string name;
    float marks;

    Student(int r = 0, string n = "", float m = 0.0) {
        rollNo = r;
        name = n;
        marks = m;
    }

    void display() const {
        cout << left << setw(10) << rollNo << setw(20) << name << setw(10) << marks << endl;
    }
};

// Node class for doubly linked list
class Node {
public:
    Student data;
    Node* next;
    Node* prev;

    Node(Student s) {
        data = s;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    // Add new student
    void addStudent(Student s) {
        Node* newNode = new Node(s);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "\nStudent added successfully.\n";
        cout << "---------------------------------------------\n";
        cout << left << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Marks" << endl;
        cout << "---------------------------------------------\n";
        newNode->data.display();
        cout << "---------------------------------------------\n";
    }

    // Delete student by roll number
    void deleteStudent(int roll) {
        Node* temp = head;
        while (temp && temp->data.rollNo != roll)
            temp = temp->next;

        if (!temp) {
            cout << "Student with Roll No " << roll << " not found!\n";
            return;
        }

        if (temp == head)
            head = head->next;
        if (temp == tail)
            tail = tail->prev;
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Student deleted successfully.\n";
    }

    // Update student record
    void updateStudent(int roll) {
        Node* temp = head;
        while (temp) {
            if (temp->data.rollNo == roll) {
                cout << "\nExisting Record:\n";
                cout << left << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Marks" << endl;
                cout << "---------------------------------------------\n";
                temp->data.display();
                cout << "---------------------------------------------\n";

                char confirm;
                cout << "Do you want to update this record? (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    string newName;
                    float newMarks;
                    cout << "Enter new Name: ";
                    cin >> newName;
                    cout << "Enter new Marks: ";
                    cin >> newMarks;
                    temp->data.name = newName;
                    temp->data.marks = newMarks;
                    cout << "Record updated successfully.\n";
                } else {
                    cout << "Update cancelled.\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    // Search student by roll number
    void searchStudent(int roll) {
        Node* temp = head;
        while (temp) {
            if (temp->data.rollNo == roll) {
                cout << "\nStudent found:\n";
                cout << left << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Marks" << endl;
                cout << "---------------------------------------------\n";
                temp->data.display();
                cout << "---------------------------------------------\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    // Sort records by marks (ascending or descending)
    void sortByMarks(bool ascending = true) {
        if (!head) {
            cout << "No records to sort.\n";
            return;
        }

        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if ((ascending && i->data.marks > j->data.marks) ||
                    (!ascending && i->data.marks < j->data.marks)) {
                    swap(i->data, j->data);
                }
            }
        }
        cout << "Records sorted by marks (" << (ascending ? "Ascending" : "Descending") << ").\n";
    }

    // Sort records by roll number
    void sortByRoll(bool ascending = true) {
        if (!head) {
            cout << "No records to sort.\n";
            return;
        }

        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if ((ascending && i->data.rollNo > j->data.rollNo) ||
                    (!ascending && i->data.rollNo < j->data.rollNo)) {
                    swap(i->data, j->data);
                }
            }
        }
        cout << "Records sorted by roll number (" << (ascending ? "Ascending" : "Descending") << ").\n";
    }

    // Display all records
    void displayRecords() {
        Node* temp = head;
        if (!temp) {
            cout << "No student records found.\n";
            return;
        }

        cout << "\n--- Student Records ---\n";
        cout << left << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Marks" << endl;
        cout << "---------------------------------------------\n";
        while (temp) {
            temp->data.display();
            temp = temp->next;
        }
        cout << "---------------------------------------------\n";
    }
};

// Main Function
int main() {
    List studentList;
    int choice;

    do {
        cout << "\n===== STUDENT RECORD MANAGEMENT SYSTEM (DLL) =====\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Update Student\n";
        cout << "4. Search Student\n";
        cout << "5. Sort by Marks\n";
        cout << "6. Sort by Roll Number\n";
        cout << "7. Display All Records\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            float marks;
            cout << "\nEnter Student Details:\n";
            cout << "----------------------\n";
            cout << "Enter Roll No: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Marks: ";
            cin >> marks;
            studentList.addStudent(Student(roll, name, marks));

        } else if (choice == 2) {
            int roll;
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            studentList.deleteStudent(roll);

        } else if (choice == 3) {
            int roll;
            cout << "Enter Roll No to update: ";
            cin >> roll;
            studentList.updateStudent(roll);

        } else if (choice == 4) {
            int roll;
            cout << "Enter Roll No to search: ";
            cin >> roll;
            studentList.searchStudent(roll);

        } else if (choice == 5) {
            int order;
            cout << "1. Ascending\n2. Descending\nEnter choice: ";
            cin >> order;
            studentList.sortByMarks(order == 1);

        } else if (choice == 6) {
            int order;
            cout << "1. Ascending\n2. Descending\nEnter choice: ";
            cin >> order;
            studentList.sortByRoll(order == 1);

        } else if (choice == 7) {
            studentList.displayRecords();

        } else if (choice == 0) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
