#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};
Node *newnode, *current, *ptr, *start, *temp;

class N_Node{
public:
    int N_data;
    N_Node *N_next;
};
N_Node *N_pre, *N_newnode, *N_start;

class LinkedList{
public:
    void nodecreate(int );
    void listcreate();
    void reverse();
    void display();
    void reverse_display();
};
void LinkedList :: nodecreate(int n){
    newnode=new Node;
    newnode->data=n;
    newnode->next=NULL;
}
void LinkedList :: listcreate(){
    char c;
    int m;
    cout << "Enter data: ";
    cin >> m;
    nodecreate(m);
    start=newnode;
    current=start;
    cout << "Do you want to create another? y/n ";
    cin >> c;
    while(c!='n'){
        cout << "Enter data: ";
        cin >> m;
        nodecreate(m);
        current->next=newnode;
        current=newnode;
        cout << "Do you want to create another? y/n ";
        cin >> c;
    }
}
void LinkedList :: display(){
    ptr=start;
    while(ptr!=NULL){
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
    cout << "end" << endl;
}
void LinkedList :: reverse(){
    current=start;

    while(current!=NULL){
        N_newnode = new N_Node;
        N_newnode->N_data=current->data;

        if(current==start){
            N_newnode->N_next=NULL;
            N_start=N_newnode;
        }
        else{
            N_newnode->N_next=N_pre;
            N_start=N_newnode;
        }
        N_pre=N_newnode;
        current=current->next;
    }

}
void LinkedList :: reverse_display(){
    N_pre=N_start;
    while(N_pre!=NULL){
        cout << N_pre->N_data << " ";
        N_pre=N_pre->N_next;
    }
    cout << "end" << endl;
}

/*
void LinkedList :: reverse(){
//    if(start==NULL)
//        return;
//    current=start;
//    while(current!=NULL){
//        temp=current->next;   // temp=next node
//        current->next=ptr;   // ptr=previous node
//        ptr=current;
//        current=temp;
//    }
//     // now let the start point at the last node (prev)
//    start=ptr;
    current=start;  //current=next node
    ptr=NULL;   //ptr=previous node
    while(current!=NULL){
        temp=current->next;
        current->next=ptr;
        start=current;
        ptr=current;
        current=temp;
    }
}
*/

int main(){
    LinkedList l;
    cout << "Linked list-" << endl;
    l.listcreate();
    l.display();
    l.reverse();
    l.reverse_display();

    return 0;
}
