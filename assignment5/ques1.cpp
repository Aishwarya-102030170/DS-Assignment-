#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void insertBefore(int target, int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == target) {
        insertAtBeginning(value);
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Target node not found.\n";
        return;
    }
    Node* newNode = new Node{value, curr};
    prev->next = newNode;
}

void insertAfter(int target, int value) {
    Node* curr = head;
    while (curr && curr->data != target)
        curr = curr->next;
    if (!curr) {
        cout << "Target node not found.\n";
        return;
    }
    Node* newNode = new Node{value, curr->next};
    curr->next = newNode;
}

void deleteFromBeginning() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteNode(int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Node not found.\n";
        return;
    }
    prev->next = curr->next;
    delete curr;
}

void searchNode(int value) {
    Node* temp = head;
    int position = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Node found at position: " << position << "\n";
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Node not found.\n";
}

void displayList() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int choice, value, target;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert before " << target << ": ";
                cin >> value;
                insertBefore(target, value);
                break;
            case 4:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert after " << target << ": ";
                cin >> value;
                insertAfter(target, value);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;
            case 9:
                displayList();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}
