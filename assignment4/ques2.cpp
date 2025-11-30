#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear;
    int arr[100];
    int size;

public:
    CircularQueue(int s = 100) {
        size = s;
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
            cout << "Queue overflow: cannot insert " << x << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
        cout << x << " inserted into queue" << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue underflow" << endl;
            return;
        }

        cout << arr[front] << " removed from queue" << endl;

        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements are: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5); 
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
