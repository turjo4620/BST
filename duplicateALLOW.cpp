// ========================
// CHANGES TO SUPPORT DUPLICATES
// ========================

/* 1️⃣ Add a count variable in Node */
class Node {
public:
    Key key;
    Value value;
    int count;      // NEW: counts duplicates
    Node* left;
    Node* right;

    Node(Key k, Value v) : key(k), value(v), count(1), left(nullptr), right(nullptr) {}
};

/* 2️⃣ Modify insert to handle duplicates */
bool insert(Key key, Value value) override {
    Node* new_node = new Node(key, value);

    if (root == nullptr) {
        root = new_node;
        node_count++;
        return true;
    }

    Node* current = root;
    while (true) {
        if (key == current->key) {
            current->count++;  // NEW: increment count
            delete new_node;
            node_count++;
            return true;
        } else if (key < current->key) {
            if (current->left == nullptr) {
                current->left = new_node;
                node_count++;
                return true;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                current->right = new_node;
                node_count++;
                return true;
            }
            current = current->right;
        }
    }
}

/* 3️⃣ Modify remove to handle duplicates */
if (remove_node->count > 1) {
    remove_node->count--;  // NEW: just reduce count for duplicates
    node_count--;
    return true;           // Node still exists, no physical deletion
}

/* 4️⃣ Modify find to return count instead of bool */
int find(Key key) const override {
    Node* node = node_finder(root, key);
    return node ? node->count : 0;  // NEW: returns number of occurrences
}

/* 5️⃣ Modify print functions to show count if >1 */
cout << "(" << root_element->key;
if (root_element->count > 1) cout << "[" << root_element->count << "]"; // NEW: show count
cout << ":" << root_element->value << ") ";
