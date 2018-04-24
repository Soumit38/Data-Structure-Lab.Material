#include <iostream>
#include <queue>
using namespace std;

class golap
{
    typedef struct tree
    {
        char data;
        tree* up;
        tree* left;
        tree* right;
    }*treeptr;



    treeptr root, curr, temp;

    typedef struct que
    {
        treeptr qval;
        que* next;
    }*queptr;

    queptr qstart, qlast;

    queue <treeptr> q;

public:
    golap();
    void input();
    void addtoque(treeptr n);
    void visit();
    void output(treeptr t);
    void preorder(treeptr t);
    void postorder(treeptr t);
}g;

void golap::input()
{
    treeptr n = new tree;
    if(root == NULL)
    {
        cout<<"Enter the root: ";
        char x;
        cin >> x;
        n->data = x;
        n->up = NULL;
        n->left = NULL;
        n->right = NULL;
        root = n;

        addtoque(n);
        //visit();
        q.push(n);
    }
    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        cout << "Insert left of \'" << curr->data << "\'?\n1->yes\n2->no\n" << endl;

        int choice;
        cin >> choice;
        if( choice == 1 )
        {
            char x;
            cout << "Data : " << endl;
            cin >> x;
            treeptr n = new tree;
            n-> data = x;
            n-> left = NULL;
            n-> right = NULL;
            curr -> left = n;
            curr -> left -> up = curr;

            addtoque(curr -> left);
            q.push( curr -> left );
        }
        cout << "Insert right of \'" << curr->data << "\'?\n1->yes\n2->no\n" << endl;
        cin >> choice;
        if( choice == 1 )
        {
            char x;
            cout << "Data : " << endl;
            cin >> x;
            treeptr n = new tree;
            n -> data = x;
            curr -> right = n;
            n -> left = NULL;
            n -> right = NULL;
            curr -> right -> up = curr;

            addtoque(curr -> right);
            q.push( curr -> right );
        }

        visit();
    }

    cout << "In order traversal result: ";
    output(root);
    cout << "\nPre order traversal result: ";
    preorder(root);
    cout << "\nPost order traversal result: ";
    postorder(root);
}

main(){}

void golap::output(treeptr t)
{
    //inorder traversal
    if(t)
    {
        output(t->left);
        cout << t->data << " " ;
        output(t->right);
    }

}

void golap::preorder(treeptr t)
{
    //inorder traversal
    if(t)
    {
        cout << t->data << " " ;
        preorder(t->left);

        preorder(t->right);
    }

}

void golap::postorder(treeptr t)
{
    //inorder traversal
    if(t)
    {
        postorder(t->left);

        postorder(t->right);
        cout << t->data << " " ;
    }

}


void golap::addtoque(treeptr n)
{
    if(qstart == NULL)
    {
        cout << "start   ;d;dld";
        qstart->qval = new tree;
//        qstart->next = NULL;
//
//        qlast = qstart;
    }
    else
    {
        queptr tq = new que;
        tq->qval = n;
        tq->next = NULL;

        qlast->next = tq;
        qlast = tq;

    }


}

void golap::visit()
{

    cout << "queue status: ";

    queptr t = qstart;
    while(t)
    {
        cout << t->qval->data << " ";
        t = t->next;
    }

    cout << endl;
}

golap::golap()
{
    root = curr = temp = new tree;
    root = curr = temp = NULL;

    qstart = qlast = new que;
    qlast = qstart = NULL;

    input();
}
