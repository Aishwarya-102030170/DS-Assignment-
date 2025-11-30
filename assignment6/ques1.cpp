#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (head == NULL) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void insertBefore(int key, int val) {
        if (head == NULL) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        do {
            if (temp->next->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void deleteNode(int key) {
        if (head == NULL) return;

        if (head->data == key && head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        do {
            if (temp->data == key) {
                if (temp == head) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    head = head->next;
                    last->next = head;
                    delete temp;
                    return;
                }
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }

    void search(int key) {
        if (head == NULL) {
            cout << "Not Found\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Not Found\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
};

int main() {
    CircularLinkedList cll;
    int ch, val, key;

    do {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Insert Before\n5. Delete Node\n6. Search\n7. Display\n8. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cin >> val;
            cll.insertAtBeginning(val);
            break;
        case 2:
            cin >> val;
            cll.insertAtEnd(val);
            break;
        case 3:
            cin >> key >> val;
            cll.insertAfter(key, val);
            break;
        case 4:
            cin >> key >> val;
            cll.insertBefore(key, val);
            break;
        case 5:
            cin >> key;
            cll.deleteNode(key);
            break;
        case 6:
            cin >> key;
            cll.search(key);
            break;
        case 7:
            cll.display();
            break;
        case 8:
            break;
        default:
            cout << "Invalid\n";
        }

    } while (ch != 8);

    return 0;
}
