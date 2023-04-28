#pragma once
#include <tuple>
#include <optional>
#define SIZE 4

template <class K, class V>
struct Node{
    int size;
    V values[SIZE]; //leafs
    std::pair<K, Node<K,V>*> keys[SIZE]; //internal nodes

    Node(int size) : size{size} {}
};

template <class K, class V>
class BTree{
    Node<K, V>* root;
    int height;
    void freeTree(Node<K, V>* &, int);
    Node<K, V>* addEntry(Node<K, V>* &, K, V, int);
    std::optional<V> searchEntry(Node<K, V>*, K, int);
    int binarySearch(Node<K, V>*, K);
    Node<K, V>* split(Node<K, V>* &);

public:
    BTree();
    ~BTree();
    void add(K, V);
    std::optional<V> search(K);
    void print();
};

#include "btree.tpp"