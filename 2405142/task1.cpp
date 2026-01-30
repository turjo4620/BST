#include <iostream>
#include <fstream>
#include<cstring>
#include "listBST.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst) {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c) {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here

        if(c == 'F'){
            in_file>>val;
            if(bst->find(val) == true){
                cout<<"Key "<<val<<" found in BST."<<endl;
            }
            else{
                cout<<"Key "<<val<<" not found in BST."<<endl;
            }
        }
        else if(c == 'I'){
            in_file>>val;
            if(bst->insert(val ,val) == true){
                cout<<"Key "<<val<<" inserted into BST, BST (Default): ";
            }
            else{
                cout<<"Insertion failed! Key "<<val<<" already exists in BST, BST (Default): ";
            }
            bst->print('D');
            cout<<endl;
        }
        else if(c == 'M'){
            in_file>>str;

            if(strcmp(str, "Min") == 0){
                cout<<"Minimum value: "<<bst->find_min()<<endl;    
            }
            else if(strcmp(str, "Max") == 0){
                cout<<"Maximum value: "<<bst->find_max()<<endl;
            }

        // End your code here
    }
    else if(c == 'T'){
        in_file>>str;
        if(strcmp(str, "Pre") == 0){
            cout<<"BST (Pre-order): ";
            bst->print('P');
        }
        else if(strcmp(str, "Post") == 0){
            cout<<"BST (Post-order): ";
            bst->print('S');
        }
        else if(strcmp(str, "In") == 0){
            cout<<"BST (In-order): ";
            bst->print('I');
        }
        cout<<endl;
    }
    else if(c == 'S'){
        cout<<"Size: "<<bst->size()<<endl;
    }
    else if(c == 'E')
    {
        if(bst->empty() == true){
            cout<<"Empty"<<endl;
        }
    }
    else if(c == 'D'){
        in_file>>val;
        if(bst->remove(val) == true){
            cout<<"Key "<<val<<" removed from BST, BST (Default): ";
        }
        else{
            cout<<"Removal failed! Key "<<val<<" not found in BST, BST (Default): ";
        }
        bst->print('D');
        cout<<endl;
    }
}
    in_file.close();
    delete bst;
    return 0;
}
