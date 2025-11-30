#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *prev;
    Node *next;

    Node(char c) {
        data = c;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node *head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(char c) {
        Node *newNode = new Node(c);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Check palindrome
    bool isPalindrome() {
        if (head == NULL) return true;

        Node *left = head;
        Node *right = head;

        // Move right pointer to last node
        while (right->next != NULL)
            right = right->next;

        // Compare from both ends
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;

    // Example: "MADAM"
    dll.insert('M');
    dll.insert('A');
    dll.insert('D');
    dll.insert('A');
    dll.insert('M');

    if (dll.isPalindrome())
        cout << "The Doubly Linked List is a Palindrome.\n";
    else
        cout << "The Doubly Linked List is NOT a Palindrome.\n";

    return 0;
}
