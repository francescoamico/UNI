#include <iostream>
#include "btree.hpp"
#include <queue>
using namespace std;

template <class K, class V>
BTree<K,V>::BTree(){ 
    root = nullptr;
    height = 0;
}

template <class K, class V>
void BTree<K,V>::print(){
    queue<pair<Node<K,V>*, int>> q;
    q.push({root,height});
    while(!q.empty()){
        pair<Node<K,V>*, int> t = q.front();
        q.pop();
        if(t.second==height)
            cout<<"Root: ";
        else if(t.second==0)
            cout<<"Leaf: ";
        else
            cout<<"Node: ";
        for(int i = 0; i < t.first->size; i++){
            if(t.second==0)
                cout<<"["<<(t.first->keys[i]).first<<", "<<t.first->values[i]<<"]  ";
            else{
                cout<<(t.first->keys[i]).first<<", ";
                q.push({(t.first->keys[i]).second, t.second-1});
            }
        }
        cout<<"\n";
    }
}

template <class K, class V>
BTree<K,V>::~BTree(){
    freeTree(root, height);
}

template <class K, class V>
void BTree<K,V>::freeTree(Node<K, V>* &r, int ht){
    if(ht==0){
        delete r;
        return;
    }
    for(int i = 0; i < r->size; i++)
        freeTree(r->keys[i].second, ht-1);
}

template <class K, class V>
void BTree<K,V>::add(K key, V value){
    if(root==nullptr){
        root = new Node<K,V>(1);
        root->values[0] = value;
        root->keys[0] = {key, nullptr};
        return;
    }
    Node<K, V>* node = addEntry(root, key, value, height);
    if(node == nullptr) return;
    Node<K, V>* new_root = new Node<K,V>(2);
    new_root->keys[0] = {(root->keys[0]).first,root};
    new_root->keys[1] = {(node->keys[0]).first, node};
    root = new_root;
    height++;
}

template <class K, class V>
Node<K, V>* BTree<K,V>::addEntry(Node<K, V>* &r, K key, V value, int ht){
    int index = binarySearch(r, key);
    if(ht==0){
        if((r->keys[index]).first==key){ //key already exists
            r->values[index] = value;
            return nullptr;
        }           
        for(int i = r->size; i >= index; i--){
            r->keys[i] = r->keys[i-1];
            r->values[i] = r->values[i-1];
        }
        r->keys[index] = {key,nullptr};
        r->values[index] = value;
        if(++r->size<SIZE) return nullptr;
        return split(r);
    }
    if(index==0) 
        (r->keys[index]).first = key; //new node's minimum key(useless if (r->keys[index]).first=key)
    else
        index = (r->keys[index]).first!=key ? index-1:index; //index1-1 = insertion point-1
    Node<K, V>* node = addEntry((r->keys[index]).second, key, value,ht-1);
    if(node == nullptr) return nullptr;
    for(int i = r->size; i >= index+1; r->keys[i]=r->keys[i-1], i--); 
    r->keys[index+1]= {(node->keys[0]).first,node};
    if(++r->size<SIZE) return nullptr;
    return split(r);
}

template <class K, class V>
Node<K, V>* BTree<K,V>::split(Node<K, V>* &r){
    Node<K, V>* node = new Node<K,V>(SIZE/2);
    for(int i = 0; i < SIZE/2; i++){
        node->keys[i] = r->keys[SIZE/2+i];
        node->values[i] = r->values[SIZE/2+i]; //usefull for leafs
    }
    r->size = SIZE/2;
    return node;
}

template <class K, class V>
std::optional<V> BTree<K,V>::search(K key){
    return searchEntry(root, key, height);
}

template <class K, class V>
std::optional<V> BTree<K,V>::searchEntry(Node<K, V>* r, K key, int ht){
    int index = binarySearch(r, key);
    if(ht==0){
        if((r->keys[index]).first==key)
            return r->values[index];
        return std::nullopt;
    }
    if(index==0 && (r->keys[index]).first!=key) //the searched key is smaller than the keys stored in the node
        return std::nullopt;
    index = (r->keys[index]).first!=key && index>0 ? index-1:index; //index1-1 = insertion point-1
    return searchEntry((r->keys[index]).second, key, ht-1); 
}

template <class K, class V>
int BTree<K,V>::binarySearch(Node<K, V>* r, K target){
    int left = 0;
    int right = r->size-1;
    while (left<=right){
        int mid = left + (right-left)/2;
        if((r->keys[mid]).first==target)
            return mid;
        if(target<(r->keys[mid]).first)
            right = mid-1;
        else
            left = mid+1;
    }
    return left;  //target is not in array, but left is at the insertion point 
}