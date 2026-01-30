#include <iostream>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right; 

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int second_largest(Node* root){
    if(root == nullptr || root->left == nullptr && root->right == nullptr){
        return -1;
    }
    Node* parent = nullptr;
    Node* current = root;

    while(current->right != nullptr){
        parent = current;
        current = current->right;
    }
    if(current->left != nullptr){
        current = current->left;
        while(current->right != nullptr){
            current = current->right;
        }
        return current->data;
    }
    return parent->data;
}


int main() {
    /*
            20
           /  \
         10    30
        /  \     \
       5   15     40
    */

    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right->right = new Node(40);

    // Store pointers for easy testing
    Node* p = root->left->left;   // Node 5
    Node* q = root->left->right;  // Node 1

    // if (ans != nullptr)
    //     cout << "Answer: " << ans->data << endl;
    // else
    //     cout << "Answer: NULL" << endl;

    return 0;
}
