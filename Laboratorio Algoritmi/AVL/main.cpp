#include "AVL.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int main(){
    AVL tree;

    vector<tuple<int,string>> test{
    {0,"addNode"},
    {2,"addNode"},
    {3, "addNode"},
    {5, "addNode"},
    {2, "deleteNode"},
    {-2, "addNode"},
    {-1, "addNode"},
    {-3, "addNode"},
    {5, "deleteNode"},
    {-4, "addNode"},
    {-10, "addNode"},
    {-3, "deleteNode"},
  };

  for(auto [val,action] : test){
    if(action == "addNode") {
        cout<<"Insert: "<<val<<"\n";
        tree.addNode(val);
    }
    else if(action == "deleteNode"){ 
        cout<<"Delete: "<<val<<"\n";
        tree.deleteNode(val);
    }
    tree.print();
    tree.printHeights();
  }

    return 0;
}