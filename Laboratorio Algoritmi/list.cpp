#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void addNode(Node* &head,int val){ 
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void reverse(Node* &head){
    Node* prev = nullptr;
    Node* curr = head;
    Node *next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void printlist(Node* head){
    while(head!=nullptr){
        printf("%d --> ",head->data);
        head=head->next;
    }
    puts("NULL\n");
}

int main(){
    Node* head=nullptr;
    addNode(head, 0);
    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);
 
    cout<<"List:"<<endl;
    printlist(head);

    reverse(head);
    cout<<"Reverse:"<<endl;
    printlist(head);

    return 0;
}