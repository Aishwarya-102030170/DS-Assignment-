#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

class Tree {
public:
    Node* insert(Node* root, int val) {
        if (root == NULL)
            return new Node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    bool isBSTUtil(Node* root, int min, int max) {
        if (root == NULL)
            return true;

        // check current node
        if (root->data <= min || root->data >= max)
            return false;

        // check left and right
        return isBSTUtil(root->left, min, root->data) &&
               isBSTUtil(root->right, root->data, max);
    }

    bool isBST(Node* root) {
        return isBSTUtil(root, -1000000, 1000000); // big range
    }
};

int main() {

    Tree t;
    Node* root = NULL;

    // Example: Build a BST
    root = t.insert(root, 8);
    t.insert(root, 3);
    t.insert(root, 10);
    t.insert(root, 1);
    t.insert(root, 6);
    t.insert(root, 14);

    if (t.isBST(root))
        cout << "Tree is a BST";
    else
        cout << "Tree is NOT a BST";

    return 0;
}
