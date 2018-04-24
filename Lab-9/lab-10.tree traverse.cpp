#include <bits/stdc++.h>

using namespace std;

class node_traverse{
    typedef struct node{
        int data;
        node* up;
        node* left;
        node* right;
    }*nodeptr;

    nodeptr root, curr, temp;
    queue<nodeptr>Q;
public:
    node_traverse();
    void construct();
    void inorder(nodeptr t);
    void preorder(nodeptr t);
    void postorder(nodeptr t);
};
node_traverse :: node_traverse(){
    //root=curr=temp=new node;
    root=curr=temp=NULL;
}
void node_traverse :: construct(){
    nodeptr n=new node;
    if(root==NULL){
        cout<<"Enter the root: ";
        int x;
        cin >> x;
        n->data=x;
        n->up=NULL;
        n->left=NULL;
        n->right=NULL;
        root=n;
        Q.push(n);
    }
    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        cout << "Enter index for Insert left of ->" << curr->data << ": ";
        int index;
        cin >> index;
        if(index==1){
            int x;
            cout << "Data : ";
            cin >> x;
            nodeptr n=new node;
            n->data=x;
            n->left=NULL;
            n->right=NULL;
            curr->left=n;
            curr->left->up=curr;
            Q.push(curr->left);
        }
        cout << "Enter index for Insert right of ->" << curr->data << ": ";
        cin >> index;
        if(index==1){
            int x;
            cout << "Data : ";
            cin >> x;
            nodeptr n=new node;
            n->data=x;
            curr->right=n;
            n->left=NULL;
            n->right=NULL;
            curr->right->up=curr;
            Q.push(curr->right);
        }
    }
    cout << "\nInorder traversal result: ";
    inorder(root);
    cout << "\nPreorder traversal result: ";
    preorder(root);
    cout << "\nPostorder traversal result: ";
    postorder(root);

}
void node_traverse :: inorder(nodeptr t){
    if(t){
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
}
void node_traverse :: preorder(nodeptr t){
    if(t){
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }
}
void node_traverse :: postorder(nodeptr t){
    if(t){
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }
}

int main(){
    node_traverse T;

    T.construct();

    return 0;
}
