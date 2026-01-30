#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>


using std::cout;
using std::endl;

/**
 * Binary Search Tree implementation using linked list structure
 *
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t node_count;

    // TODO: Implement private helper functions as needed
    // Start your private helper functions here

    Node* node_finder(Node *root_element, Key key) const
    {
        if (root_element == nullptr)
            return nullptr;
        Node *current = root_element;
        while (current != nullptr)
        {
            if (key == current->key)
            {
                return current;
            }
            else if (key > current->key)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }

        return nullptr;
    }

    Node* parent_finder(Node* root_element, Key key){
        if(root_element == nullptr || root_element->key == key) return nullptr;
        Node* current = root_element;
        while(current != nullptr){
            if(current->left != nullptr && current->left->key == key ){
                return current;
            }
            else if( current->right != nullptr && current->right->key == key){
                return current;
            }
            if(current->key < key){
                if(current->right == nullptr) return nullptr;
                else{
                    current = current->right;
                }
            }
            else{
                if(current->left == nullptr) return nullptr;
                else{
                    current = current->left;
                }
            }
        }
        return nullptr;
    }
    Node* get_successor(Node* node) {
        Node* current = node;
        while (current != nullptr && current->left != nullptr)
            current = current->left;
        return current;
    }

    void print_preorder(const Node* root_element) const{
        if(root_element == nullptr)return;


        cout<<"(";
        cout<<root_element->key<<":"<<root_element->value;
        cout<<") ";

        print_preorder(root_element->left);

        print_preorder(root_element->right);
    }

    void print_inorder(const Node* root_element) const{
        if(root_element == nullptr) return;

        print_inorder(root_element->left);

        cout<<"(";
        cout<<root_element->key<<":"<<root_element->value;
        cout<<") ";

        print_inorder(root_element->right);
        
    }
    
    void print_postorder(const Node* root_element) const{
        if(root_element == nullptr) return;

        print_postorder(root_element->left);

        print_postorder(root_element->right);
        cout<<"(";
        cout<<root_element->key<<":"<<root_element->value;
        cout<<") ";
    }

    void destructor(Node* root_element){
        if(root_element != nullptr){
            destructor(root_element->left);
            destructor(root_element->right);
            delete root_element;
        }
    }

    void print_default(Node* root_element) const{
        if(root_element == nullptr) return;
        cout<<"("<<root_element->key<<":"<<root_element->value;
        if(root_element->left != nullptr || root_element->right != nullptr){
            cout<<" ";
        
        if(root_element->left != nullptr){
            print_default(root_element->left);
        }
        else{
            cout<<"()";
        }
        if(root_element->right != nullptr){
            cout<<" ";
            print_default(root_element->right);
        }
    }
        cout<<")";
    }
    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}

    /**
     * Destructor
     */
    ~ListBST()
    {
        // TODO: Implement destructor to free memory
        destructor(root);
        
    }

    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override
    {
        // TODO: Implement insertion logic

        Node *new_node = new Node(key, value);

        if (root == nullptr)
            {
                root = new_node;
                node_count++;
                return true;
            }
        Node *current = root;
        while (true)
        {
            if (current->key < key)
            {
                if (current->right == nullptr)
                {
                    current->right = new_node;
                    node_count++;
                    return true;
                }
                current = current->right;
            }
            else if(current->key > key){
                if(current->left == nullptr){
                    current->left = new_node;
                    node_count++;
                    return true;
                }
                current = current->left;
            }
            else{
                delete new_node;
                return false;
            }
        }
    }

    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override
    {
        // TODO: Implement removal logic
        Node* remove_node = node_finder(root, key);

        if(remove_node == nullptr) return false;

        Node* parent_node= parent_finder(root, remove_node->key);

        

        if(remove_node->right != nullptr && remove_node->left != nullptr){
            Node* succesor_node = get_successor(remove_node->right);
            Node* parent = parent_finder(root, succesor_node->key);

            remove_node->key = succesor_node->key;
            remove_node->value = succesor_node->value;

            remove_node = succesor_node;
            parent_node = parent;


        }
        else{
            parent_node = parent_finder(root, remove_node->key);
        }
        if(remove_node->left == nullptr && remove_node->right == nullptr){
            if(parent_node == nullptr){
                root = nullptr;
            }
            else if(parent_node->left == remove_node){
                parent_node->left = nullptr;
            }
            else
            {parent_node->right = nullptr;}


        }
        else if(remove_node->left == nullptr && remove_node->right != nullptr){
            Node* temp = remove_node->right;
            if(parent_node == nullptr) root = temp;
            else if(parent_node->left == remove_node){
                parent_node->left = temp;
            }
            else{
                parent_node->right = temp;
            }


        }
        else if(remove_node->right == nullptr && remove_node->left != nullptr){
            Node* temp = remove_node->left;
            if(parent_node == nullptr) root = temp;
            else if(parent_node->left == remove_node){
                parent_node->left = temp;
            }
            else{
                parent_node->right = temp;
            }
            
            
        }

        
        
        node_count--;

        delete remove_node;

        return true;
    }

    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override
    {
        // TODO: Implement find logic

        if (node_finder(root, key) != nullptr)
            return true;
        else
            return false;
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override
    {
        // TODO: Implement get logic

        Node *result = node_finder(root, key);
        if (result == nullptr)
            return Value();
        else
            return result->value;
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override
    {
        // TODO: Implement update logic

        Node *update = node_finder(root, key);
        if (update != nullptr)
            update->value = value;
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override
    {
        // TODO: Implement clear logic
        destructor(root);
        root = nullptr;
        node_count = 0;
    }

    /**
     * Get the number of keys in the BST
     */
    size_t size() const override
    {
        // TODO: Implement size logic
        return node_count;
    }

    /**
     * Check if the BST is empty
     */
    bool empty() const override
    {
        // TODO: Implement empty check logic
        if(root == nullptr) return true;
        else return false;
    }

    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override
    {
        // TODO: Implement find_min logic
        if(root == nullptr) return Key();

        Node* current = root;
        while(current->left != nullptr){
            current = current->left;
        }
        return current->key;


    }

    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override
    {
        // TODO: Implement find_max logic
        if(root == nullptr) return Key();

        Node* current = root;
        while(current->right != nullptr){
            current = current->right;
        }
        return current->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override
    {
        // TODO: Implement print logic

        switch (traversal_type)
        {
        case  'I':
            print_inorder(root);
            break;
        
        case 'P':
            print_preorder(root);
            break;

        case 'S':
            print_postorder(root);
            break;

        case 'D':
            print_default(root);
            break;
        }
    }
};

#endif //LISTBST_H