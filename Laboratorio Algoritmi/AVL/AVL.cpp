#include "AVL.hpp"
#include <iostream>

using namespace std;

AVL::AVL(){ 
  root = nullptr;
  level = 0;
}

void AVL::addNode(int val){
    add(root,val);
}

void AVL::deleteNode(int val){
    del(root,val);
}

void AVL::print(){ 
    if (root!=nullptr) 
        treePrint(root,true);
    cout<<"------------------------\n";
}

void AVL::printHeights(){
    if (root!=nullptr) 
        treePrint(root,false);
    cout<<"------------------------\n";
}

void AVL::add(Node* &r, int val){ 
    if(r==nullptr){
        r = new Node(val);
    }else if(val<r->data){
        add(r->left,val);
        r->height = max(r->height,1+r->left->height);
        fixAVL(r);
    }else if(val>r->data){
        add(r->right,val);
        r->height = max(r->height,1+r->right->height);
        fixAVL(r);
    }
}

void AVL::fixAVL(Node* &r){
    int bf = balanceFactor(r);
    
    if(bf>=-1 && bf<=1)
        return;

    if (bf==-2){ //unbalance to the right of r
        if(balanceFactor(r->right)==1) //unbalance to the left of r->right
            rotdx(r->right);
        rotsx(r);
    }else{ //unbalance to the left of r
        if(balanceFactor(r->left)==-1) //unbalance to the right of r->left
            rotsx(r->left);
        rotdx(r);
    }
}

int AVL::balanceFactor(Node* r){
    int leftHeight = r->left ? r->left->height:-1;
    int rightHeight = r->right ? r->right->height:-1;
    return leftHeight-rightHeight;
}

void AVL::rotsx(Node* &r){
    Node* newroot = r->right;

    int leftHeight = r->left ? r->left->height:-1;
    int rightHeight = newroot->left ? newroot->left->height:-1;
    r->height = 1+max(leftHeight,rightHeight);
    rightHeight = newroot->right ? newroot->right->height:-1;
    newroot->height = 1+max(r->height,rightHeight);

    r->right = newroot->left;
    newroot->left = r;
    r = newroot;
}
        
void AVL::rotdx(Node* &r){
    Node* newroot = r->left;

    int rightHeight = r->right ? r->right->height:-1;
    int leftHeight = newroot->right ? newroot->right->height:-1;
    r->height = 1+max(leftHeight,rightHeight);
    leftHeight = newroot->left ? newroot->left->height:-1;
    newroot->height = 1+max(r->height,leftHeight);

    r->left = newroot->right;
    newroot->right = r;
    r = newroot;
}

void AVL::del(Node* &r,int val){
    if(r==nullptr){
        cout<<val<<" not in tree\n";
    }else if(val<r->data){
        del(r->left,val);
        int leftHeight = r->left ? r->left->height:-1;
        int rightHeight = r->right ? r->right->height:-1;
        r->height = 1+max(leftHeight,rightHeight);
        fixAVL(r);
    }else if(val>r->data){
        del(r->right,val);
        int leftHeight = r->left ? r->left->height:-1;
        int rightHeight = r->right ? r->right->height:-1;
        r->height = 1+max(leftHeight,rightHeight);
        fixAVL(r);
    }else{
        if(r->right==nullptr){ 
            Node* tmp = r->left;
            delete r;
            r = tmp;
        }else if(r->left==nullptr){
            Node* tmp = r->right;
            delete r;
            r = tmp;
        }else{
            Node* min = findMin(r->right);
            r->data = min->data;
            del(r->right,min->data);
            int leftHeight = r->left ? r->left->height:-1;
            int rightHeight = r->right ? r->right->height:-1;
            r->height = 1+max(leftHeight,rightHeight);
            fixAVL(r);
        }
    }
}

Node* AVL::findMin(Node* r){
    if(r->left==nullptr)
        return r;
    return findMin(r->left);
}
    
void AVL::treePrint(Node* r,bool val) {
    if (r==nullptr)
        return;
    this->level++;
    treePrint(r->right,val);  
    val ? printf(">%*s%5d\n", level*5, "", r->data):printf(">%*s%5d\n", level*5, "", r->height);      
    treePrint(r->left,val);
    this->level--;                           
} 