#pragma once

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int data) : data{data}, height{0}, left{nullptr} , right{nullptr} {}
};

class AVL{
    Node* root;
    int level;
    void add(Node* &, int val);
    void fixAVL(Node* &r);
    int balanceFactor(Node* r);
    void rotsx(Node* &r);
    void rotdx(Node* &r);
    void del(Node* &r,int val);
    Node* findMin(Node*r);
    void treePrint(Node* r,bool val);

public:
    AVL();
    void addNode(int val);
    void deleteNode(int val);
    void print();
    void printHeights();
};