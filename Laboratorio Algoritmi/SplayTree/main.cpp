#include "SPLAY.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int main(){
    SPLAY<int> tree;

    vector<tuple<int,string>> test{
        {7,"addNode"},
        {6,"addNode"},
        {5, "addNode"},
        {4, "addNode"},
        {3, "addNode"},
        {2, "addNode"},
        {1, "addNode"},
        {8, "addNode"},
        {8, "addNode"},
        {4, "searchNode"},
        {18, "searchNode"},
        {5, "deleteNode"},
        {5, "searchNode"},
        {2, "deleteNode"},
        {4, "deleteNode"},
    };

    for(auto [val,action] : test){
        if (action == "addNode") {
            cout<<"Insert: "<<val<<"\n\n";
            tree.addNode(val);
        }else if (action == "searchNode") {
            cout<<"Search: "<<val<<"\n\n";
            tree.searchNode(val);
        }else if (action == "deleteNode") {
            cout<<"Delete: "<<val<<"\n\n";
            tree.deleteNode(val);
        }
        tree.print();
    }

    return 0;
}