#include "matching.hpp"
#include <iostream>
using namespace std;

int main(){
    string pattern = "ABABAC";
    int index = match("BCBAABABACAD", pattern);
    if(index == -1)
        cout<<"\""<<pattern<<"\" not in text"<<endl;
    else
        cout<<"Pattern \""<<pattern<<"\" starts from: "<<index<<endl;

    cout<<"Counter: "<<countMatch("BCBCBABCBD","BCB")<<endl;
    cout<<"Cyclic rotation: "<<cyclicRotation("BCBCBABCBD","ABCBDBCBCB")<<endl;
    cout<<"Border length: "<<borderLength("abaababaaba")<<endl;
    cout<<"Period: "<<period("abaababaaba")<<endl;
    cout<<"Tandem repeat: "<<tandemRepeat("abcabcababcababcababc","abcab")<<endl;

    vector<string> patterns = {"ABABAC","BAA", "", "CAD", "STG"};
    vector<int> res = matchList("BCBAABABACAD", patterns);
    for(int i=0; i<res.size(); i++){
        if (res[i]==-1){
            cout<<"\""<<patterns[i]<<"\" not in text"<<endl;
            continue;
        }
        cout<<"Pattern \""<<patterns[i]<<"\" starts from: "<<res[i]<<endl;
    }
    
    return 0;
}