#include <iostream>

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
Node* lcaBST(Node* root, int u, int v) {
    while (root != nullptr) {

        if (u < root->data && v < root->data) {
            root = root->left;
        }
        else if (u > root->data && v > root->data) {
            root = root->right;
        }
        else {
            return root;
        }
    }
    return nullptr;
}
int main(){
    


    return 0;
}