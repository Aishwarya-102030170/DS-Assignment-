#include <iostream>
using namespace std;

class stack {
    int top;
    int arr[100];

public:
    stack() {
        top = -1;
    }

    void push(int val) {
        if (top >= 99) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++top] = val;
        cout << val << " pushed into stack." << endl;
    }

    int pop() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1;  // return an invalid value
        }
        return arr[top--];
    }

    int peek() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top < 0;
    }

    void display() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    stack s;
    int choice, val;

    do {
        cout << "\n Menu \n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;

        case 2:
            val = s.pop();
            if (val != -1)
                cout << "Popped value: " << val << endl;
            break;

        case 3:
            val = s.peek();
            if (val != -1)
                cout << "Top element: " << val << endl;
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting program" << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}
