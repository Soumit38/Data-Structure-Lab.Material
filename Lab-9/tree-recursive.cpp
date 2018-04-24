#include<bits/stdc++.h>
using namespace std;
int val=0;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root,*root1,*root2;

Node* create()
{
    int x;
    cin>>x;
    Node *p = new Node;
    if(x==-1)
        return NULL;

    if(!val)
    {
        root2=root1=root=p;
        val++;
    }
    p->data=x;
    p->left=create();
    p->right=create();
    return p;
}

void preOrder(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preOrder(p->left);
        preOrder(p->right);
    }
}

void inOrder(Node *p)
{
    if(p!=NULL)
    {
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
}

void postOrder(Node *p)
{
    if(p!=NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<" ";
    }
}


int main()
{
    create();
    preOrder(root);
    inOrder(root1);
    postOrder(root2);
}
