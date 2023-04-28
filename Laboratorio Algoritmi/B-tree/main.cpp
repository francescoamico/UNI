#include "btree.hpp"
#include <vector>
#include <string>

int main(){
    BTree<int, string> tree;

    vector<tuple<int,string,string>> test{
        {12, "ciao", "add"},
        {57, "a", "add"},
        {22, "tutti", "add"},
        {77, "Mi", "add"},
        {11, "chiamo", "add"},
        {12, "Francesco", "add"},
        {33, "Amico", "add"},
        {100, "e", "add"},
        {14, "studio", "add"},
        {101, "informatica", "add"},
        {12, "", "search"},
        {34, "", "search"},
        {100, "", "search"},
        {120, "", "search"}
    };

    for(auto [key,val,action] : test){
        if (action == "add") {
            cout<<"Add: ["<<key<<", "<<val<<"]\n\n";
            tree.add(key,val);
            tree.print();
        }else if (action == "search") {
            cout<<"Search: "<<key<<"\n";
            optional<string> val = tree.search(key);
            if(val.has_value())
                cout<<"Value: "<<val.value()<<"\n";
            else
                cerr<<"no value for key "<<key<<"\n";
        }
        cout<<"----------------\n";
    }
    
    return 0;
}