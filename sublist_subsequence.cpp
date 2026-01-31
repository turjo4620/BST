#include <iostream>
#include <vector>
using namespace std;

// ---------- BST Node ----------
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// ---------- Recursive Inorder Traversal ----------
void check(Node* root, const vector<int>& seq, int& sublistCnt, int& subIdx) {
    if (!root) return;

    // Traverse left
    check(root->left, seq, sublistCnt, subIdx);

    int val = root->data;

    // ---- Sublist (contiguous) ----
    if (sublistCnt < seq.size()) {
        if (val == seq[sublistCnt])
            sublistCnt++;
        else
            sublistCnt = (val == seq[0]) ? 1 : 0;
    }

    // ---- Subsequence (ordered) ----
    if (subIdx < seq.size() && val == seq[subIdx])
        subIdx++;

    // Traverse right
    check(root->right, seq, sublistCnt, subIdx);
}

// ---------- Main Solve Function ----------
string solve(Node* root, const vector<int>& seq) {
    int sublistCnt = 0;
    int subIdx = 0;

    check(root, seq, sublistCnt, subIdx);

    if (sublistCnt == seq.size()) return "sublist";
    if (subIdx == seq.size()) return "subsequence";
    return "none";
}

// ---------- BST Insert ----------
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// ---------- Main ----------
int main() {
    Node* root = nullptr;

    // Build BST
    vector<int> bstVals = {8,3,10,1,6,14,4,7,13};
    for (int x : bstVals)
        root = insert(root, x);

    // Test sequences
    vector<int> seq1 = {4,6,7};      // contiguous → sublist
    vector<int> seq2 = {1,6,10,14};  // ordered → subsequence
    vector<int> seq3 = {6,1,8};      // none

    cout << solve(root, seq1) << endl; // sublist
    cout << solve(root, seq2) << endl; // subsequence
    cout << solve(root, seq3) << endl; // none

    return 0;
}
