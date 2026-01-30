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

Node* lowestCommmonAncestor(Node* root, Node* p, Node* q){
    if(root == nullptr || root == p || root == q){
        return root;
    }
    Node* left = lowestCommmonAncestor(root->left, p, q);
    Node* right = lowestCommmonAncestor(root->right, p, q);

    if(left == nullptr) return right;
    else if(right == nullptr) return left;
    else return root;
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
    Node* q = root->left->right;  // Node 15

    // 🔽 Change ONLY this line for different problems
    Node* ans = lowestCommmonAncestor(root, p, q);

    if (ans != nullptr)
        cout << "Answer: " << ans->data << endl;
    else
        cout << "Answer: NULL" << endl;

    return 0;
}
