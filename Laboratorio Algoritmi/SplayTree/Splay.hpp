#pragma once

template <class T>
struct Node {
    T data;
    int counter;
    Node<T>* left;
    Node<T>* right;

    Node(T data) : data{data}, counter{1}, left{nullptr} , right{nullptr} {}
};

template <class T>
class Splay {
    Node<T>* root;
    int level;
    int add(Node<T>* &, T);
    int search(Node<T>* &, T);
    int del(Node<T>* &, T);
    Node<T>* findMin(Node<T>*);
    void delMin(Node<T>* &);
    int climb1(Node<T>* &, int);
    int climb2(Node<T>* &, int);
    void rotsx(Node<T>* &);
    void rotdx(Node<T>* &);
    void treePrint(Node<T>*);
    void freeTree(Node<T>* &);

public:
    Splay();
    ~Splay();
    void addNode(T);
    void searchNode(T);
    void deleteNode(T);
    void print();
};

#include "Splay.tpp"
