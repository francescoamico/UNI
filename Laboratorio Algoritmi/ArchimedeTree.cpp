#include <bits/stdc++.h>
using namespace std;
 
static int level = 0;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* BuildArchimedeTree(vector<int> archimede) { 
    Node* root = nullptr;
    stack<Node*> stack;
    Node* tmp = new Node(archimede[0]);
    Node* node;
    Node* el;
    int min = INT_MAX;
    stack.push(tmp);
    for(int i=1; i<archimede.size(); i++){
        node = new Node(archimede[i]);
        if(node->data<min){
            min = node->data;
            root = node;
        }
        if(node->data>tmp->data)
            tmp->right=node;
        else{
            do{
                el = stack.top();
                stack.pop();
            }while(!stack.empty() && el->data>node->data);

            if(stack.empty() && i==archimede.size()-1){
                node->left = el->right;
                el->right = node;
            }else if(stack.empty()){
                node->left = el;
            }else{
                el->right = node;
                node->left = tmp;
            }
        }
        tmp = node;
        stack.push(tmp);
    }
    return root;
}

void printTree(Node* r) {
    if (r!=nullptr) {
        level++;
        printTree(r->right);         
        printf(">%*s%5d\n", level*5, "", r->data);      
        printTree(r->left);
        level--;
    }                           
} 

int main(){
    vector<int> archimede={9,3,7,1,8,12,10,20,15,18,5};
    Node* root = BuildArchimedeTree(archimede);
    printTree(root);
    return 0;
}