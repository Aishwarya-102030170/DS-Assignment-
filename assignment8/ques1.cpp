#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
node * buildtree(vector<int>&preorder,int &idx){
    idx++;
    if(preorder[idx]==-1) return NULL;
    node* root=new node(preorder[idx]);
    root->left=buildtree(preorder,idx);
    root->right=buildtree(preorder,idx);
    return root;
}

void preorderTraversal(node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// In-order: Left → Root → Right
void inorderTraversal(node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Post-order: Left → Right → Root
void postorderTraversal(node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    node* root = buildtree(preorder, idx);
    
    cout << "Pre-order: ";
    preorderTraversal(root);
    cout << endl;
    
    cout << "In-order: ";
    inorderTraversal(root);
    cout << endl;
    
    cout << "Post-order: ";
    postorderTraversal(root);
    cout << endl;
    
    return 0;
}