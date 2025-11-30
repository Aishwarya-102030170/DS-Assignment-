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

class LinkedList {
public:
    Node *head = NULL;

    // Insert at end (normal singly linked list)
    void insertAtEnd(int val) {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Function to check if list is circular
    bool isCircular() {
        if (head == NULL)
            return true;  // empty list considered circular

        Node *temp = head->next;

        // Traverse until NULL or reach back to head
        while (temp != NULL && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    LinkedList ll;

    // Create normal list (not circular)
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);

    if (ll.isCircular())
        cout << "The Linked List is Circular.\n";
    else
        cout << "The Linked List is NOT Circular.\n";

    return 0;
}
