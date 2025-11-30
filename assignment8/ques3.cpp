#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BST {
    Node *root;

    Node* insertNode(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertNode(node->left, val);
        } else if (val > node->data) {
            node->right = insertNode(node->right, val);
        } else {
            // val == node->data → duplicate, do nothing
        }
        return node;
    }

    Node* findMinNode(Node* node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) {
            return nullptr;
        }
        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            // found the node to delete
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                // both children exist
                Node* succ = findMinNode(node->right);
                node->data = succ->data;
                node->right = deleteNode(node->right, succ->data);
            }
        }
        return node;
    }

    int maxDepthNode(Node* node) {
        if (node == nullptr) return 0;
        int leftDepth = maxDepthNode(node->left);
        int rightDepth = maxDepthNode(node->right);
        if (leftDepth > rightDepth) {
            return 1 + leftDepth;
        } else {
            return 1 + rightDepth;
        }
    }

    int minDepthNode(Node* node) {
        if (node == nullptr) return 0;
        // If one subtree is empty, we must go down the other
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        } else if (node->left == nullptr) {
            return 1 + minDepthNode(node->right);
        } else if (node->right == nullptr) {
            return 1 + minDepthNode(node->left);
        } else {
            int leftDepth = minDepthNode(node->left);
            int rightDepth = minDepthNode(node->right);
            if (leftDepth < rightDepth) {
                return 1 + leftDepth;
            } else {
                return 1 + rightDepth;
            }
        }
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertNode(root, val);
    }

    void remove(int val) {
        root = deleteNode(root, val);
    }

    int getMaxDepth() {
        return maxDepthNode(root);
    }

    int getMinDepth() {
        return minDepthNode(root);
    }

    void printInorder() {
        inorderTraversal(root);
        cout << "\n";
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.printInorder();

    cout << "Max depth: " << tree.getMaxDepth() << "\n";
    cout << "Min depth: " << tree.getMinDepth() << "\n";

    cout << "Deleting 20\n";
    tree.remove(20);
    cout << "Inorder: "; tree.printInorder();

    cout << "Deleting 30\n";
    tree.remove(30);
    cout << "Inorder: "; tree.printInorder();

    cout << "Deleting 50\n";
    tree.remove(50);
    cout << "Inorder: "; tree.printInorder();

    cout << "Max depth after deletions: " << tree.getMaxDepth() << "\n";
    cout << "Min depth after deletions: " << tree.getMinDepth() << "\n";

    return 0;
}
