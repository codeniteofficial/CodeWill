#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node * newnode(int data){
    struct node * n=new node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n; 
}

int height(struct node * node){
    if(node==NULL) return 0;
    return(1+max(height(node->left),height(node->right)));
}
bool check(struct node * node){
    if(node==NULL) return true;
    int l=height(node->left);
    int r=height(node->right);
    return(abs(l-r)<2 && check(node->left) && check(node->right));
}

int main(){
    struct node * n=newnode(1);
    n->left=newnode(2);
    n->right=newnode(4);
    n->left->left=newnode(10);
    n->left->right=newnode(12);
    cout<<check(n);

    return 0;
}