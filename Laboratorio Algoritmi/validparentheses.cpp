#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool validparenthesis(char parenthesis[],int n){
    stack<char> stack;
    map<char,char> map;
    map[')'] = '(';
    map[']'] = '[';
    map['}'] = '{';

    for(int i=0; i<n; i++){
        if(map.count(parenthesis[i])==1){ //closing bracket
            if(!stack.empty()){
                if(map[parenthesis[i]] != stack.top())
                    return false;
                stack.pop();
            }else 
                return false;
        }else
            stack.push(parenthesis[i]);
    }

    return stack.empty();
}

int main(){
    char parenthesis[] = {'[','(',')',']','{','}','{','[','(',')','(',')','(',')',']','(',')','}'}; 

    if(validparenthesis(parenthesis,18))
        cout<<"input is valid"<<endl;
    else
        cout<<"input is not valid"<<endl;
}