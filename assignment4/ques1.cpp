#include <iostream>
using namespace std;

class queue {
    int front, rear;
    int arr[100];

public:
    queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear >= 99) {
            cout << "Queue overflow: cannot insert " << x << endl;
            return;
        }
        if (front == -1) { 
            front = 0; 
        }
        arr[++rear] = x;
        cout << x << " inserted into queue" << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << arr[front] << " removed from queue" << endl;
        front++;
    }

    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    queue q;
    int choice, value;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
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
