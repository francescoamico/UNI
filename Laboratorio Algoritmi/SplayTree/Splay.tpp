#include <iostream>
#include "Splay.hpp"

using namespace std;

template <class T>
Splay<T>::Splay(){ 
    root = nullptr;
    level = 0;
}

template <class T>
Splay<T>::~Splay(){ 
    freeTree(root);
}

template <class T>
void Splay<T>::addNode(T val){
    int res = add(root,val);
}

template <class T>
void Splay<T>::searchNode(T val){
    int res = search(root,val);
}

template <class T>
void Splay<T>::deleteNode(T val){
    int res = del(root,val);
}

template <class T>
void Splay<T>::print(){ 
    if (root!=nullptr) 
        treePrint(root);
    cout<<"------------------------\n";
}

template <class T> 
int Splay<T>::add(Node<T>* &r, T val){ 
    if(r==nullptr){
        r = new Node(val);
        return 0; //go up the new node
    }else if(val<r->data){
        return climb1(r,add(r->left,val));
    }else if(val>r->data){
        return climb2(r,add(r->right,val));
    }
    //val is already in the tree
    r->counter++;
    return 0; //go up the node already in the tree
}

template <class T> 
int Splay<T>::search(Node<T>* &r, T val){ 
    if(r==nullptr){ 
        cout<<"Number of copies: 0\n";
        return 0; //go up the node's predecessor
    }else if(val<r->data){
        int res = search(r->left,val);
        if (r->left==nullptr)
            return 0;
        return climb1(r,res);
    }else if(val>r->data){
        int res = search(r->right,val);
        if (r->right==nullptr)
            return 0;
        return climb2(r,res);
    }
    cout<<"Number of copies: "<< r->counter<<"\n";
    return 0; //go up the node searched
}

template <class T> //go up the node's predecessor if is a leaf otherwise the node's successor
int Splay<T>::del(Node<T>* &r,T val){
    if(r==nullptr){
        cout<<val<<" not in tree\n";
        return 0; 
    }else if(val<r->data){
        int res = del(r->left,val);
        if (r->left==nullptr)
            return 0;
        return climb1(r,res);
    }else if(val>r->data){
        int res = del(r->right,val);
        if (r->right==nullptr)
            return 0;
        return climb2(r,res);
    }else{
        if(r->right==nullptr){ 
            Node<T>* tmp = r->left;
            delete r;
            r = tmp;
            return 0;
        }else if(r->left==nullptr){
            Node<T>* tmp = r->right;
            delete r;
            r = tmp;
            return 0;
        }else{
            Node<T>* min = findMin(r->right);
            r->data = min->data;
            delMin(r->right);
            return 0;
        }
    }
}

template <class T>
Node<T>* Splay<T>::findMin(Node<T>* r){
    if(r->left==nullptr)
        return r;
    return findMin(r->left);
}

template <class T>
void Splay<T>::delMin(Node<T>* &r){
    if(r->left!=nullptr)
        delMin(r->left);
    Node<T>* tmp = r->right;
    delete r;
    r = tmp;
}

template <class T>
int Splay<T>::climb1(Node<T>* &r, int res){
    res--;
    if (res==-2){ //zig-zig rotation
        rotdx(r);
        rotdx(r);
        return 0;
    }else if (res == 0){ //zag zig rotation
        rotsx(r->left);
        rotdx(r);
        return 0;
    }else if (r == root){ //zig rotation
        rotdx(r);
    }
    return res;
}

template <class T>
int Splay<T>::climb2(Node<T>* &r, int res){
    res++;
    if (res==2){ //zag-zag rotation
        rotsx(r);
        rotsx(r);
        return 0;
    }else if (res == 0){ //zig zag rotation
        rotdx(r->right);
        rotsx(r);
        return 0;
    }else if (r == root){ //zag rotation
        rotsx(r);
    }
    return res;
}

template <class T>
void Splay<T>::rotsx(Node<T>* &r){
    Node<T>* newroot = r->right;
    r->right = newroot->left;
    newroot->left = r;
    r = newroot;
}

template <class T>       
void Splay<T>::rotdx(Node<T>* &r){
    Node<T>* newroot = r->left;
    r->left = newroot->right;
    newroot->right = r;
    r = newroot;
}

template <class T>
void Splay<T>::treePrint(Node<T>* r) {
    if (r==nullptr)
        return;
    this->level++;
    treePrint(r->right);  
    printf(">%*s%5d\n", level*5, "", r->data);      
    treePrint(r->left);
    this->level--;                           
}

template <class T>
void Splay<T>::freeTree(Node<T>* &r){
    if (r->left)
        freeTree(r->left);
    if (r->right)
        freeTree(r->right);
    delete r;
}