#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert (no duplicates)
Node* insertNode(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else if (val > root->data) {
        root->right = insertNode(root->right, val);
    }
    // if val == root->data, do nothing (no duplicate)
    return root;
}

Node* buildBST(const vector<int>& arr) {
    Node* root = nullptr;
    for (int v : arr) {
        root = insertNode(root, v);
    }
    return root;
}

void inorderPrint(Node* root) {
    if (root == nullptr) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

// (a) Search — Recursive
bool searchRecursive(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

// (a) Search — Non-Recursive (iterative)
bool searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur != nullptr) {
        if (cur->data == key) return true;
        else if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return false;
}

// (b) Maximum element of BST
Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    Node* cur = root;
    while (cur->right != nullptr) {
        cur = cur->right;
    }
    return cur;
}

// (c) Minimum element of BST
Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    Node* cur = root;
    while (cur->left != nullptr) {
        cur = cur->left;
    }
    return cur;
}

// (d) In-order successor of given key in BST
// Returns pointer to successor node (or nullptr if none)
Node* inorderSuccessor(Node* root, int key) {
    Node* successor = nullptr;
    Node* cur = root;
    while (cur != nullptr) {
        if (cur->data > key) {
            successor = cur;
            cur = cur->left;
        } else {
            // cur->data <= key
            cur = cur->right;
        }
    }
    return successor;
}

// (e) In-order predecessor of given key in BST
Node* inorderPredecessor(Node* root, int key) {
    Node* predecessor = nullptr;
    Node* cur = root;
    while (cur != nullptr) {
        if (cur->data < key) {
            predecessor = cur;
            cur = cur->right;
        } else {
            // cur->data >= key
            cur = cur->left;
        }
    }
    return predecessor;
}

int main() {
    vector<int> arr = {20, 10, 5, 15, 30, 25, 35};
    Node* root = buildBST(arr);

    cout << "Inorder traversal: ";
    inorderPrint(root);
    cout << "\n";

    int key = 15;
    cout << "Search " << key << " (recursive): " 
         << (searchRecursive(root, key) ? "Found" : "Not Found") << "\n";
    cout << "Search " << key << " (iterative): " 
         << (searchIterative(root, key) ? "Found" : "Not Found") << "\n";

    Node* maxNode = findMax(root);
    if (maxNode) cout << "Maximum element: " << maxNode->data << "\n";
    else cout << "Tree is empty\n";

    Node* minNode = findMin(root);
    if (minNode) cout << "Minimum element: " << minNode->data << "\n";
    else cout << "Tree is empty\n";

    Node* succ = inorderSuccessor(root, key);
    if (succ) cout << "In-order successor of " << key << " is: " << succ->data << "\n";
    else cout << "No in-order successor for " << key << "\n";

    Node* pred = inorderPredecessor(root, key);
    if (pred) cout << "In-order predecessor of " << key << " is: " << pred->data << "\n";
    else cout << "No in-order predecessor for " << key << "\n";

    return 0;
}
