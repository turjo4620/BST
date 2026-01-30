// C++ program to count BST nodes within 
// a given range
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Returns count of nodes in BST in range [l, h]
int getCount(Node *root, int l, int h) {
    
    // Base case
    if (root == nullptr) return 0;

    // If current node is in range, then 
    // include it in count and recur for 
    // left and right children of it
    if (root->data <= h && root->data >= l)
         return 1 + getCount(root->left, l, h) +
                    getCount(root->right, l, h);

    // If current node is smaller than low, 
    // then recur for right child
    else if (root->data < l)
         return getCount(root->right, l, h);

    // Else recur for left child
    else return getCount(root->left, l, h);
}

int main() {
    
    // Create a hard coded bst.
    //        10
    //       /  \
    //      5   50 
    //     /   /  \    
    //    1   40  100
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5;
    int h = 45;
    
    cout << getCount(root, l, h) << endl;
    
    return 0;
}