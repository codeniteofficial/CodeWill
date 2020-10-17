#include<iostream>
using namespace std; 
struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * createNode(int data){
    struct node * n=new node;
    n->data=data;
    n->left=n->right=NULL;
    return n;
}
struct node * insert(struct node * node , int data){
    if (node==NULL) return createNode(data);
    if (data < node->data) node->left= insert(node->left, data);
    if(data>node->data) node->right= insert(node->right,data);
    return node;
}
void inorder(struct node* n){
     if(n==NULL) return;
     inorder(n->left);
     cout<<n->data<<" ";
     inorder(n->right);  
}
int main(){
    int t;
    cout<<"enter the number of nodes\n";
    cin>>t;
    cout<<"enter the values\n";
    struct node *n=NULL;
    int x;
    // cin>>x;
    // n=insert(n,x);
    // t--;
    while(t--){
        cin>>x;
        n=insert(n,x);
    }
    inorder(n);
    return 0;
}