#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    float salary;

    void setData(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }
};

class Company {
    int n;
    Employee emp[50];

public:
    // Input employee details
    void input() {
        cout << "Enter number of employees: ";
        cin >> n;

        cout << "\nEnter details of employees:\n";
        for (int i = 0; i < n; i++) {
            int id;
            string name;
            float salary;
            cout << "\nEmployee " << i + 1 << ":\n";
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Salary: ";
            cin >> salary;

            emp[i].setData(id, name, salary);
        }
    }

    // Selection Sort by Salary
    void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (emp[j].salary < emp[minIdx].salary)
                    minIdx = j;
            }
            Employee temp = emp[i];
            emp[i] = emp[minIdx];
            emp[minIdx] = temp;
        }
    }

    // Bubble Sort by Salary
    void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (emp[j].salary > emp[j + 1].salary) {
                    Employee temp = emp[j];
                    emp[j] = emp[j + 1];
                    emp[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }

    // Display all employee records
    void displayAll() {
        cout << "\n-----------------------------------------------------------\n";
        cout << left << setw(15) << "Employee ID"
             << setw(20) << "Employee Name"
             << setw(15) << "Salary" << endl;
        cout << "-----------------------------------------------------------\n";
        for (int i = 0; i < n; i++) {
            cout << left << setw(15) << emp[i].id
                 << setw(20) << emp[i].name
                 << setw(15) << fixed << setprecision(2) << emp[i].salary << endl;
        }
        cout << "-----------------------------------------------------------\n";
    }

    // Display top 5 highest salaries
    void displayTopFive() {
        cout << "\nTop 5 Highest Salaries:\n";
        cout << "-----------------------------------------------------------\n";
        cout << left << setw(15) << "Employee ID"
             << setw(20) << "Employee Name"
             << setw(15) << "Salary" << endl;
        cout << "-----------------------------------------------------------\n";
        int count = (n < 5) ? n : 5;
        for (int i = n - 1; i >= n - count; i--) {
            cout << left << setw(15) << emp[i].id
                 << setw(20) << emp[i].name
                 << setw(15) << fixed << setprecision(2) << emp[i].salary << endl;
        }
        cout << "-----------------------------------------------------------\n";
    }

    int getCount() {
        return n;
    }

    // Copy employees for independent sorting
    void copyFrom(const Company &other) {
        n = other.n;
        for (int i = 0; i < n; i++)
            emp[i] = other.emp[i];
    }
};

// ---------- MAIN FUNCTION ----------
int main() {
    Company c1, c2;

    // Input employee details
    c1.input();
    c2.copyFrom(c1); // Duplicate data for both sorts

    // ---- Selection Sort ----
    cout << "\n===== SELECTION SORT =====" << endl;
    c1.selectionSort();
    c1.displayAll();
    c1.displayTopFive();

    // ---- Bubble Sort ----
    cout << "\n===== BUBBLE SORT =====" << endl;
    c2.bubbleSort();
    c2.displayAll();
    c2.displayTopFive();

    cout << "\nNOTE: Both sorting algorithms produce the same results, "
         << "but Selection Sort generally performs fewer swaps.\n";
    return 0;
}
