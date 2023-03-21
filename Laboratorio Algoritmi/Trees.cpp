#include <bits/stdc++.h>
using namespace std;
 
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
 
class BinaryTree {
    public:
        Node* root;
        int level=0;
        int height=-1;

        BinaryTree() {
            root = nullptr;
        }
        
        void addNode(int data) { //BST
            Node* newNode = new Node(data);
        
            if (root == nullptr) {
                root = newNode;
            }else {
                Node* focusNode = root;
                Node* parent;
            
                while (true) {
                    parent = focusNode;
            
                    if (data < focusNode->data) {
                        focusNode = focusNode->left;
                        if (focusNode == nullptr) {
                            parent->left = newNode;
                            return;
                        }
                    } else {
                        focusNode = focusNode->right;
                        if (focusNode == nullptr) {
                            parent->right = newNode;
                            return;
                        }
                    }
                }
            }
        }

    private:
        void preOrderTraversal(Node* focusNode) {
            if (focusNode == nullptr) 
                return;
            cout << focusNode->data << " ";
            preOrderTraversal(focusNode->left);
            preOrderTraversal(focusNode->right);
        }

    public:
        bool isList(){
            return isaList(root);
        }

    private:
        bool isaList(Node *r){
            if (r==nullptr)
                return true;
            if (r->left!=nullptr && r->right!=nullptr)
                return false;
            if(r->left)
                return isaList(r->left);
            else
                return isaList(r->right);
        }

    public:
        Node* mirrorCopy(){
            if(root==nullptr)
                return root;

            Node* newRoot = new Node(root->data);
            queue<Node*> q;
            q.push(root);
            map<Node*,Node*> copy;
            copy[root] = newRoot;
            while(!q.empty()){
                Node* tmp = q.front();
                q.pop();
                if(tmp->right){
                    copy[tmp->right] = new Node(tmp->right->data);
                    copy[tmp]->left =  copy[tmp->right];
                    q.push(tmp->right);
                }if(tmp->left){
                    copy[tmp->left] = new Node(tmp->left->data);
                    copy[tmp]->right =  copy[tmp->left];
                    q.push(tmp->left);
                }
            }     
            return newRoot;
        }

        void switchSubTrees(){
            invertSubTrees(root);
        }

    private:
        void invertSubTrees(Node* &r){
            if(r==nullptr)
                return;
            Node* tmp;
            tmp = r->left;
            r->left = r->right;
            r->right = tmp;
            invertSubTrees(r->left);
            invertSubTrees(r->right);
        }

    public:
        vector<Node*> BFS(){
            queue<Node*> q;
            q.push(root);
            vector<Node*> visited;
            while(!q.empty()){
                height++;
                int len = q.size();
                for(int i=0; i<len;i++){
                    Node* tmp = q.front();
                    q.pop();
                    visited.push_back(tmp);
                    if(tmp->left)
                        q.push(tmp->left);
                    if(tmp->right)
                        q.push(tmp->right);
                }
            }     
            return visited;
        }

        void treePrint(){ 
            if (root!=nullptr) 
                print(root);
            printf("------------------------\n");
        } 

        void print(Node* r) {
            if (r!=nullptr) {
                this->level++;
                print(r->right);         
                printf(">%*s%5d\n", level*5, "", r->data);      
                print(r->left);
                this->level--;
            }                           
        } 
};
 
int main() {
    
    BinaryTree tree;

    tree.addNode(50);
    tree.addNode(25);
    tree.addNode(75);
    tree.addNode(12);
    tree.addNode(37);
    tree.addNode(43);
    tree.addNode(30);
  
    cout<<"Tree: \n";
    tree.treePrint();
    cout<<"Is a list: "<<tree.isList()<<"\n------------------------"<<endl;
    vector<Node*> visited = tree.BFS();
    cout<<"BFS: ";
    for(int i = 0; i<visited.size();i++){
        cout<<visited[i]->data<<" ";
    }
    cout<<"\nHeight: "<<tree.height<<"\n------------------------"<<endl;
    cout<<"Mirror Tree: \n";
    Node *rootMirrorTree = tree.mirrorCopy();
    tree.print(rootMirrorTree);
    cout<<"Switch subTrees: \n";
    tree.switchSubTrees();
    tree.treePrint();

  return 0;
}