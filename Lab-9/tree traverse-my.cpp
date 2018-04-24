#include <bits/stdc++.h>

using namespace std;

class tree_traverse{
    typedef struct tree{
        char data;
        tree* up;
        tree* left;
        tree* right;
    }*treeptr;

    treeptr root, curr, temp;
    queue<treeptr>Q;

public:
    tree_traverse();
    void input();
    void inorder(treeptr t);
    void preorder(treeptr t);
    void postorder(treeptr t);
};
tree_traverse :: tree_traverse(){
    root = curr = temp = new tree;
    root = curr = temp = NULL;
}
void tree_traverse :: input(){
    treeptr n = new tree;
    if(root == NULL){
        cout<<"Enter the root: ";
        char x;
        cin >> x;
        n->data = x;
        n->up = NULL;
        n->left = NULL;
        n->right = NULL;
        root = n;
        Q.push(n);
    }
    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        cout << "Insert left of \'" << curr->data << "\'?\n1->yes\n2->no\n" << endl;

        int choice;
        cin >> choice;
        if( choice == 1 ){
            char x;
            cout << "Data : " << endl;
            cin >> x;
            treeptr n = new tree;
            n-> data = x;
            n-> left = NULL;
            n-> right = NULL;
            curr -> left = n;
            curr -> left -> up = curr;
            Q.push( curr -> left );
        }
        cout << "Insert right of \'" << curr->data << "\'?\n1->yes\n2->no\n" << endl;
        cin >> choice;
        if( choice == 1 ){
            char x;
            cout << "Data : " << endl;
            cin >> x;
            treeptr n = new tree;
            n -> data = x;
            curr -> right = n;
            n -> left = NULL;
            n -> right = NULL;
            curr -> right -> up = curr;
            Q.push( curr -> right );
        }
    }
    cout << "\nIn order traversal result: ";
    inorder(root);
    cout << "\nPre order traversal result: ";
    preorder(root);
    cout << "\nPost order traversal result: ";
    postorder(root);
}
void tree_traverse :: inorder(treeptr t){
    if(t){
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
}
void tree_traverse :: preorder(treeptr t){
    if(t){
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }
}
void tree_traverse :: postorder(treeptr t){
    if(t){
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }
}

int main(){
    tree_traverse T;

    T.input();

    return 0;
}
