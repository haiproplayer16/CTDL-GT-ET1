#include <iostream>
#include <stdlib.h>
#include<vector>
using namespace std;
struct Node{
    int val;
    Node* left{ 0 };
    Node* right{ 0 };
    Node(int val = 0){
        this->val = val;
        left = right = nullptr;
    }
};
class BTree{
    class Iterator {
    public:
        Node* last;
        Node* current;
        int comp;

    public:
        Iterator& Find(Node* root, int x)
        {
            current = root;
            last = 0;
            while (current != 0)
            {
                comp = x - current->val;
                if (comp == 0) break;

                last = current;
                current = comp < 0 ? last->left : last->right;
            }
            return *this;
        }
    } iter;

public:
    void Maketree(Node* &t){
        t = NULL;
    }
    void AddNode(Node* &t,vector<int> p,size_t &i){
        if(i >= p.size()) return;
        t=new Node();
        t->val=p[i++];
        AddNode(t->left,p,i);
        AddNode(t->right,p,i);
    }
    void AddNodesearch(Node* &t, int x){
        iter.Find(t, x);
        if (t == NULL){
            t = new Node(x);
            return;
        }
        else{
            if (t->val > x) {
                AddNodesearch(t->left,x);
            }
            else if (t->val < x) {
                AddNodesearch(t->right,x);
            }
        }
    }
    void Inorder(Node* t) {
        if(t!=nullptr){
            Inorder(t->left);
            cout<<t->val<<" ";
            Inorder(t->right);
        }
    }
    void Preorder(Node* t){
        if(t!=nullptr){
            cout<<t->val<<" ";
            Preorder(t->left);
            Preorder(t->right);
        }
    }
    void Postorder(Node* t){
        if(t!=nullptr){
            Postorder(t->left);
            Postorder(t->right);
            cout<<t->val<<" ";
        }
    }
    void Dispose(Node* &t){
        if(t!=nullptr){
            Dispose(t->left);
            Dispose(t->right);
            delete t;
            t=nullptr;
        }
    }
    bool Isempty(Node* t){
        return t==nullptr;
    }
    bool Checkexist(Node* t,int input){
        if(t==nullptr){return false;}
        if(t->val==input) return true;
        if(input<t->val) return Checkexist(t->left,input);
        return Checkexist(t->right,input);
    }
    Node* FindMin(Node* t){
        while (t->left!=nullptr){
            t=t->left;
        }
        return t;
    }
    Node* FindMax(Node* t){
        while (t->right!=nullptr){
            t=t->right;
        }
        return t;
    }
    void Deletenode(Node*& t, int x) {
    if (t == nullptr) return;
    if (x < t->val)
        Deletenode(t->left, x);
    else if (x > t->val)
        Deletenode(t->right, x);
    else {
        if (t->left == nullptr && t->right == nullptr) {
            delete t;
            t = nullptr;
        } else if (t->left == nullptr) {
            Node* temp = t;
            t = t->right;
            delete temp;
        } else if (t->right == nullptr) {
            Node* temp = t;
            t = t->left;
            delete temp;
        } else {
            Node* minNode = FindMin(t->right);
            t->val = minNode->val;
            Deletenode(t->right, minNode->val);
        }
    }
    }
    int minDepth(Node* root){
        if(root==nullptr){
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(left==0){
            return 1+right;
        }
        if(right==0){
            return 1+left;
        }
        return 1+min(left,right);
    }
    int maxDepth(Node* root){
        if(root==nullptr){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right);
    }

private:
    Node* root;

};


int main(){
    Node* tree;
    BTree tree1;
    tree1.Maketree(tree);
    int p[] = { 4, 2, 11, 5, 6, 9, 3 };
    for (int i = 0; i < 7; i++) {
        tree1.AddNodesearch(tree, p[i]);
    }
    vector<int> v = { 19, 30, 35, 15, 25, 17};
    Node* tree2 = nullptr;
    BTree tree3;
    size_t i = 0;
    tree3.AddNode(tree2, v, i);
    tree3.Postorder(tree2);
    return 0;
}
