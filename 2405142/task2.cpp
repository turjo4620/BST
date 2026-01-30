#include <iostream>
#include <fstream>
#include <string>
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
        return 1;
    }

    // TODO: Declare data structures to track bid statistics for each item
    // You need to track: total bids, successful bids, rejected bids for each item
    // Hint: You may use additional BSTs or other data structures
    // Start your code here
    ListBST<string, int>* present = new ListBST<string, int>();
    ListBST<string, int>* accept = new ListBST<string, int>();
    ListBST<string, int>* reject = new ListBST<string, int>();
    int total_bids = 0;
    int successfull_bids = 0;
    int rejected_bids = 0;
    string array[1000];
    int index = 0;
    // End your code here

    int n;
    string name;
    int price;
    in_file >> n;
    for (int i = 0; i < n; ++i) {
        // TODO: Implement the logic to read initial items and their starting bids
        // Initialize statistics tracking for each item
        // Start your code here
        in_file>>name;
        in_file>>price;
        present->insert(name, price);
        accept->insert(name, 0);
        reject->insert(name, 0);
        array[index++] = name;
        
        
        // End your code here
    }

    // TODO: Implement the logic to print the initial auction state
    // Start your code here
    cout<<"Initial auction items:"<<endl;
    cout<<"BST (In-order): ";
    present->print('I');
    cout<<endl;

    // End your code here
    cout << "\nAuction starts!\n\n";
    cout << "==============================\n";

    string operation;
    while (in_file >> operation) {
        // TODO: Implement the logic to process operations (ADD, BID, CHECK, STATS, REPORT) and print auction state after each operation
        // For BID operations: update statistics (total bids, successful/rejected counts)
        // For STATS operations: display statistics for the specified item
        // For REPORT operations: display comprehensive auction statistics
        // For other operations: print auction state using in-order traversal
        // Start your code here
        if(operation == "BID"){
            in_file>>name;
            in_file>>price;
            int accept_count = 0;
            int reject_count = 0;
            if(present->get(name) < price){
                present->update(name, price);
                cout<<"Bid of "<<price<<" on "<<name<<" accepted. Current bid: "<<price<<endl;
                cout<<"BST (In-order): ";
                present->print('I');
                accept_count = accept->get(name) + 1;
                accept->update(name, accept_count);
                successfull_bids++;
                total_bids++;

            }
            else{
                cout<<"Bid of "<<price<<" on "<<name<<" rejected. Current bid: "<<present->get(name)<<endl;
                cout<<"BST (In-order): ";
                present->print('I');
                reject_count = reject->get(name) + 1;
                reject->update(name, reject_count);
                rejected_bids++;
                total_bids++;
            }
            cout<<endl;
        }
        else if(operation == "CHECK"){
            in_file>>name;
            cout<<"Current bid for "<<name<<": "<<present->get(name)<<endl;
            cout<<"BST (In-order): ";
            present->print('I');
            cout<<endl;
        }
        else if(operation == "STATS"){
            in_file>>name;
            cout<<"Statistics for "<<name<<":"<<endl;
            cout<<"  Current highest bid: "<<present->get(name)<<endl;
            cout<<"  Total bids placed: "<<accept->get(name) + reject->get(name)<<endl;
            cout<<"  Successful bids: "<<accept->get(name)<<endl;
            cout<<"  Rejected bids: "<<reject->get(name)<<endl;
        }
        else if(operation == "ADD"){
            in_file>>name;
            in_file>>price;
            present->insert(name, price);
            cout<<"Item "<<name<<" added with starting bid "<<price<<endl;
            cout<<"BST (In-order): ";
            present->print('I');
            accept->insert(name, 0);
            reject->insert(name, 0);
            array[index++] = name;
        }
        else if(operation == "REPORT"){
            cout<<"Auction Report:"<<endl;
            cout<<"Total items: "<<present->size()<<endl;
            cout<<"Total bids placed: "<<total_bids<<endl;
            cout<<"Total successful bids: "<<successfull_bids<<endl;
            cout<<"Total rejected bids: "<<rejected_bids<<endl<<endl;
            cout<<"Item Statistics:"<<endl;

            for(int i = 0; i < index - 1; i++){
                for(int j = 0; j < index - i - 1; j++){
                    if (array[j] > array[j + 1])
                    {
                        string temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
            for(int i = 0; i < index; i++){
                cout<<"  "<<array[i]<<": "<<"Current bids: "<<present->get(array[i])<<", Total bids: "<<accept->get(array[i]) + reject->get(array[i])<<", Successful: "<<accept->get(array[i])<<", Rejected: "<<reject->get(array[i])<<endl;
            }
        }

        
        

        

        // End your code here
        cout << "\n==============================\n";
    }

    in_file.close();
    // TODO: Delete data structures you created
    // Start your code here
    delete present;
    delete accept;
    delete reject;
    // End your code here
    return 0;
}
