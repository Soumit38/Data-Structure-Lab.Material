#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *nextrow, *nextcol;
};
//Node *newnode, *ptr, *start, *row[5], *col[4], *temp[4];
Node *newnode, *ptr, *start, *row[10], *col[10], *temp[10];

class LinkedList{
private:
    int r, c;
public:
    void nodecreate(int );
    void listcreate();
    void rowdisplay();
    void coldisplay();
};
void LinkedList :: nodecreate(int n){
    newnode=new Node;
    newnode->data=n;
    newnode->nextrow=NULL;
    newnode->nextcol=NULL;
}
void LinkedList :: listcreate(){
    cout << "Enter row: ";
    cin >> r;
    cout << "Enter col: ";
    cin >> c;
    int m;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << "Enter data at position: " << i << " " << j << " : ";
            cin >> m;
            if(i==0 && j==0){
                nodecreate(m);
                start=newnode;
                row[i]=start;
                col[j]=start;
                temp[j]=start;
            }
            else if(i==0 && j!=0){
                nodecreate(m);
                col[j-1]->nextcol=newnode;
                col[j]=newnode;
                temp[j]=newnode;
            }
            else if(i!=0 && j==0){
                nodecreate(m);
                row[i]=newnode;
                temp[j]->nextrow=newnode;
                temp[j]=newnode;
            }
            else{
                nodecreate(m);
                temp[j]->nextrow=newnode;
                temp[j]=newnode;
                temp[j-1]->nextcol=newnode;
            }
        }
    }
}
void LinkedList :: rowdisplay(){
    cout << "Row display :" << endl;
    for(int i=0; i<r; i++){
        ptr=row[i];
        while(ptr!=NULL){
            if(ptr->data==0){
                ptr=ptr->nextcol;
            }
            else{
                cout << ptr->data << " ";
                ptr=ptr->nextcol;
            }
        }
        cout << endl;
    }
}
void LinkedList :: coldisplay(){
    cout << "Column display :" << endl;
    for(int i=0; i<c; i++){
        ptr=col[i];
        while(ptr!=NULL){
            if(ptr->data==0){
                ptr=ptr->nextrow;
            }
            else{
                cout << ptr->data << " ";
                ptr=ptr->nextrow;
            }
        }
        cout << endl;
    }
}

int main(){
    LinkedList l;
    l.listcreate();
    l.rowdisplay();
    l.coldisplay();

    return 0;
}
