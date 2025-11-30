#include<iostream>
using namespace std;

const int SIZE = 100;

int arr[SIZE];
int n = 0; // number of elements

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if(n == 0){
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements are: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    int pos, val;
    cout << "Enter position to insert (0 to " << n << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;

    if(pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }

    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;

    cout << "Element inserted.\n";
    display();  // Show new array
}

void del() {
    int pos;
    cout << "Enter position to delete (0 to " << n-1 << "): ";
    cin >> pos;

    if(pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }

    for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i+1];
    }
    n--;

    cout << "Element deleted.\n";
    display();  // Show updated array
}

void linearSearch() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    bool found = false;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at position: " << i << endl;
            found = true;
            break;
        }
    }

    if(!found) {
        cout << "Element not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 6);

    return 0;
}
