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
int height(Node* root){
    if(root == nullptr){
        return -1;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);
    
    return max(left_height, right_height) + 1;

}

int main(){
    


    return 0;
}