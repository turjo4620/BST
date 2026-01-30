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

void levelorderrec(Node* root, int level, vector<vector<int>>&vec){
    if(root == nullptr) return;
    if(vec.size() <= level){
        vec.push_back({});
    }

    vec[level].push_back(root->data);
    levelorderrec(root, level + 1, vec);
    levelorderrec(root, level + 1, vec);

}

vector<vector<int>> level_order(Node* root){
    vector<vector<int>>vec;
    levelorderrec(root, 0, vec);

    return vec;
}
int main(){
    
    return 0;
}