#include <iostream>

using namespace std;

class Node{
public:
    int data, row, col;
    Node *rowptr, *colptr;
};
Node *newnode, *current, *ptr, *temp[5][4];
Node *row1, *row2, *row3, *row4, *row5;
Node *col1, *col2, *col3, *col4, *colp[5][4];

class LinkedList{
public:
    void nodecreate(int );
    void listcreate();
    void rowdisplay();
    void coldisplay();
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
    colp[1][1]=newnode;
    temp[1][1]=colp[1][1];
    for(int i=2; i<=4; i++){
        cin >> m;
        nodecreate(m);
        newnode->row=1;
        newnode->col=i;
        colp[1][i]=newnode;
        temp[1][i]=colp[1][i];
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
    colp[2][1]=newnode;
    temp[1][1]->colptr=colp[2][1];
    temp[2][1]=colp[2][1];
    for(int i=2; i<=4; i++){
        cin >> m;
        nodecreate(m);
        newnode->row=2;
        newnode->col=i;
        colp[2][i]=newnode;
        temp[1][i]->colptr=colp[2][i];
        temp[2][i]=colp[2][i];
        current->rowptr=newnode;
        current=newnode;
    }
//
//    cout << "\nEnter row3 value : ";
//    cin >> m;
//    nodecreate(m);
//    newnode->row=3;
//    newnode->col=1;
//    row3=newnode;
//    current=row3;
//    col[3]=newnode;
//    temp[3]->colptr=col[3];
//    for(int i=2; i<5; i++){
//        cin >> m;
//        nodecreate(m);
//        newnode->row=3;
//        newnode->col=i;
//        col[i]=newnode;
//        temp[i]->colptr=col[i];
//        current->rowptr=newnode;
//        current=newnode;
//    }
//
//    cout << "\nEnter row4 value : ";
//    cin >> m;
//    nodecreate(m);
//    newnode->row=4;
//    newnode->col=1;
//    row4=newnode;
//    current=row4;
//    col[4]=newnode;
//    temp[4]->colptr=col[4];
//    for(int i=2; i<5; i++){
//        cin >> m;
//        nodecreate(m);
//        newnode->row=4;
//        newnode->col=i;
//        col[i]=newnode;
//        temp[i]->colptr=col[i];
//        current->rowptr=newnode;
//        current=newnode;
//    }
//
//    cout << "\nEnter row5 value : ";
//    cin >> m;
//    nodecreate(m);
//    newnode->row=5;
//    newnode->col=1;
//    row5=newnode;
//    current=row5;
//    col[5]=newnode;
//    temp[5]->colptr=col[5];
//    for(int i=2; i<5; i++){
//        cin >> m;
//        nodecreate(m);
//        newnode->row=5;
//        newnode->col=i;
//        col[i]=newnode;
//        temp[i]->colptr=col[i];
//        current->rowptr=newnode;
//        current=newnode;
//    }
}
void LinkedList :: rowdisplay(){
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

//    ptr=row2;
//    for(int i=1; i<5; i++){
//        if(ptr->data==0){
//            ptr=ptr->rowptr;
//        }
//        else{
//            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
//            ptr=ptr->rowptr;
//        }
//    }
//    cout << endl;
//
//    ptr=row3;
//    for(int i=1; i<5; i++){
//        if(ptr->data==0){
//            ptr=ptr->rowptr;
//        }
//        else{
//            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
//            ptr=ptr->rowptr;
//        }
//    }
//    cout << endl;
//
//    ptr=row4;
//    for(int i=1; i<5; i++){
//        if(ptr->data==0){
//            ptr=ptr->rowptr;
//        }
//        else{
//            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
//            ptr=ptr->rowptr;
//        }
//    }
//    cout << endl;
//
//    ptr=row5;
//    for(int i=1; i<5; i++){
//        if(ptr->data==0){
//            ptr=ptr->rowptr;
//        }
//        else{
//            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
//            ptr=ptr->rowptr;
//        }
//    }
//    cout << endl;
}
void LinkedList :: coldisplay(){
    cout << "\nSparse Matrix-" << endl;
    cout << "Col-1" << endl;
    ptr=colp[1][1];
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->colptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->colptr;
        }
    }
    cout << endl;

    cout << "Col-2" << endl;
    ptr=colp[2][1];
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->colptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->colptr;
        }
    }
    cout << endl;

    cout << "Col-3" << endl;
    ptr=colp[3][1];
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->colptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->colptr;
        }
    }
    cout << endl;

    cout << "Col-4" << endl;
    ptr=colp[4][1];
    for(int i=1; i<5; i++){
        if(ptr->data==0){
            ptr=ptr->colptr;
        }
        else{
            cout << ptr->data << "(" << ptr->row << "," << ptr->col << ")" <<" ";
            ptr=ptr->colptr;
        }
    }
    cout << endl;
}

int main(){
    LinkedList l;
    l.listcreate();
    l.coldisplay();

    return 0;
}
