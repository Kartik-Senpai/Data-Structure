#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Customer {
public:
    int customerid;
    string name;

    void setdata(int id, string name) {
        this->customerid = id;
        this->name = name;
    }
};

// ---------- LINEAR SEARCH ----------
int doSearchLinearly(Customer arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i].customerid == target)
            return i;
    }
    return -1;
}

// ---------- BUBBLE SORT FOR BINARY SEARCH ----------
void bubbleSort(Customer arr[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        bool swapped = false;
        for (int i = 0; i < size - pass - 1; i++) {
            if (arr[i].customerid > arr[i + 1].customerid) {
                Customer temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// ---------- BINARY SEARCH ----------
int doBinarySearch(Customer arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].customerid == target)
            return mid;
        else if (arr[mid].customerid < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// ---------- MAIN FUNCTION ----------
int main() {
    int size;
    cout << "Enter number of Customers: ";
    cin >> size;

    Customer c[size];
    int id;
    string name;

    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter Id of Customer " << i + 1 << ": ";
        cin >> id;
        cout << "Enter Name of Customer " << i + 1 << ": ";
        cin >> name;
        cout<<endl;
        c[i].setdata(id, name);
    }

    cout << "\nEnter Customer ID to search: ";
    int target;
    cin >> target;

    // -------- Linear Search --------
    cout << "\n----- LINEAR SEARCH -----" << endl;
    int linearResult = doSearchLinearly(c, size, target);
    if (linearResult != -1) {
        cout << "Customer found at index: " << linearResult << endl;
        cout << "Customer ID: " << c[linearResult].customerid << endl;
        cout << "Customer Name: " << c[linearResult].name << endl;
    } else {
        cout << "Customer ID not found." << endl;
    }

    // -------- Binary Search --------
    cout << "\n----- BINARY SEARCH -----" << endl;
    bubbleSort(c, size);
    cout << "List after sorting by ID:\n";
    cout << left << setw(15) << "Customer ID" << setw(15) << "Customer Name" << endl;
    for (int i = 0; i < size; i++)
        cout << left << setw(15) << c[i].customerid << setw(15) << c[i].name << endl;

    int binaryResult = doBinarySearch(c, size, target);
    if (binaryResult != -1) {
        cout << "\nCustomer found at index (sorted list): " << binaryResult << endl;
        cout << "Customer ID: " << c[binaryResult].customerid << endl;
        cout << "Customer Name: " << c[binaryResult].name << endl;
    } else {
        cout << "\nCustomer ID not found in binary search." << endl;
    }

    cout << "\nResult: Binary Search is faster but requires sorted data.\n";
    return 0;
}
