#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node *head = NULL;

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;   // circular link
            return;
        }

        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int getSize() {
        if (head == NULL) return 0;

        int count = 0;
        Node *temp = head;

        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(5);
    cll.insertAtEnd(10);
    cll.insertAtEnd(15);
    cll.insertAtEnd(20);

    cout << "Size of Circular Linked List = " << cll.getSize() << endl;

    return 0;
}
