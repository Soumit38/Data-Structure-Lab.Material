#include <iostream>

using namespace std;

class Node{
public:
    int data, row, col;
    Node *rowptr, *colptr;
};
Node *newnode, *current, *ptr;
Node *row1, *row2, *row3, *row4, *row5;
Node *col1, col2, col3, col4;

class LinkedList{
public:
    void nodecreate(int );
    void listcreate();
    void display();
};
void LinkedList :: nodecreate(int n){
    newnode=new Node;
    newnode->data=n;
    newnode->rowptr=NULL;
    newnode->colptr=NULL;
}
void LinkedList :: listcreate(){
    cout << "\nEnter row1 value : ";
    int m;
    cin >> m;
    nodecreate(m);
    newnode->row=1;
    newnode->col=1;
    row1=newnode;
    current=row1;
    for(int i=2; i<5; i++){
        cin >> m;
        nodecreate(m);
        newnode->row=1;
        newnode->col=i;
        current->rowptr=newnode;
        current=newnode;
    }

    cout << "\nEnter row2 value : ";
    cin >> m;
    nodecreate(m);
    newnode->row=2;
    newnode->col=1;
    row2=newnode;
    current=row2;
    for(int i=2; i<5; i++){
        cin >> m;
        nodecreate(m);
        newnode->row=2;
        newnode->col=i;
        current->rowptr=newnode;
        current=newnode;
    }

    cout << "\nEnter row3 value : ";
    cin >> m;
    nodecreate(m);
    newnode->row=3;
    newnode->col=1;
    row3=newnode;
    current=row3;
    for(int i=2; i<5; i++){
        cin >> m;
        nodecreate(m);
        newnode->row=3;
        newnode->col=i;
        current->rowptr=newnode;
        current=newnode;
    }

    cout << "\nEnter row4 value : ";
    cin >> m;
    nodecreate(m);
    newnode->row=4;
    newnode->col=1;
    row4=newnode;
    current=row4;
    for(int i=2; i<5; i++){
        cin >> m;
        nodecreate(m);
        newnode->row=4;
        newnode->col=i;
        current->rowptr=newnode;
        current=newnode;
    }

    cout << "\nEnter row5 value : ";
    cin >> m;
    nodecreate(m);
    newnode->row=5;
    newnode->col=1;
    row5=newnode;
    current=row5;
    for(int i=2; i<5; i++){
        cin >> m;
        nodecreate(m);
        newnode->row=5;
        newnode->col=i;
        current->rowptr=newnode;
        current=newnode;
    }
}

void LinkedList :: display(){
    cout << "\nSparse Matrix-" << endl;
    ptr=row1;
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->rowptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->rowptr;
        }
    }
    cout << endl;

    ptr=row2;
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->rowptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->rowptr;
        }
    }
    cout << endl;

    ptr=row3;
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->rowptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->rowptr;
        }
    }
    cout << endl;

    ptr=row4;
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->rowptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->rowptr;
        }
    }
    cout << endl;

    ptr=row5;
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->rowptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->rowptr;
        }
    }
    cout << endl;
}
int main(){
    LinkedList l;
    l.listcreate();
    l.display();

    return 0;
}
