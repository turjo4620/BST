#include <bits/stdc++.h>
using namespace std;

// ---------- BST Node ----------
struct Node {
    int data;      // Value of node
    Node* left;    // Left child
    Node* right;   // Right child
    int height;    // Height of subtree rooted at this node (for O(1) height query)

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1; // Leaf node has height 1
    }
};

// ---------- Insert Function ----------
// Inserts a value into BST and updates the height of all affected nodes
Node* insert(Node* root, int val) {
    if (!root) return new Node(val); // Create new node if root is null

    if (val < root->data)
        root->left = insert(root->left, val);  // Go left
    else
        root->right = insert(root->right, val); // Go right

    // Update current node's height after insertion
    int leftHeight = root->left ? root->left->height : 0;
    int rightHeight = root->right ? root->right->height : 0;
    root->height = 1 + max(leftHeight, rightHeight);

    return root;
}

// ---------- Depth Function ----------
// Returns depth of a node in BST (0 for root, -1 if not found)
// Depth is # of ancestors above the node
int depth(Node* root, int key) {
    int d = 0;             // Start at depth 0
    Node* curr = root;

    while (curr) {
        if (key == curr->data)
            return d;      // Node found
        else if (key < curr->data)
            curr = curr->left;   // Go left
        else
            curr = curr->right;  // Go right
        d++;
    }
    return -1;              // Node not found
}

// ---------- Height Function ----------
// Returns height of the tree in O(1) using stored height in root
int getHeight(Node* root) {
    return root ? root->height : 0;
}

// ---------- Main Function ----------
int main() {
    Node* root = nullptr;  // Initialize empty BST
    string line;

    // Read commands line by line (simulate online assignment input)
    while (getline(cin, line)) {
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "I") { // Insert command
            int val;
            ss >> val;
            root = insert(root, val);
            cout << "(" << root->data << ")" << endl; // Optional debug output
        }
        else if (cmd == "P") { // Depth query
            int key;
            ss >> key;
            int d = depth(root, key);
            cout << d << endl; // Depth of node, -1 if not found
        }
        else if (cmd == "H") { // Height query
            cout << getHeight(root) << endl; // Height of BST
        }
        // You can add more commands like Delete (D), Traversals (T), etc.
    }

    return 0;
}
