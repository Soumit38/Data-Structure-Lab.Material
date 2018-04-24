#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};
Node *newnode, *current, *ptr, *start, *temp;

class LinkedList{
public:
    void nodecreate(int );
    void listcreate();
    void display();
    void insert_first();
    void insert_last();
    void insert_before();
    void insert_after();
    void delete_first();
    void delete_last();
    void delete_specific();
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
void LinkedList :: insert_first(){
    int a;
    cout << "Enter data: ";
    cin >> a;
    nodecreate(a);
    temp=newnode;
    current=start;
    temp->next=current;
    start=temp;
}
void LinkedList :: insert_last(){
    int a;
    cout << "Enter data: ";
    cin >> a;
    nodecreate(a);
    temp=newnode;
    current=start;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=temp;
}
void LinkedList :: insert_before(){
    int a, b;
    cout << "Enter Specific Value: ";
    cin >> a;
    cout << "Enter data: ";
    cin >> b;
    nodecreate(b);
    temp=newnode;
    current=start;
    while(1){
        if(current->data==a){
            temp->next=current;
            ptr->next=temp;
            break;
        }
        ptr=current;
        current=current->next;
    }
}
void LinkedList :: insert_after(){
    int a, b;
    cout << "Enter Specific Value: ";
    cin >> a;
    cout << "Enter data: ";
    cin >> b;
    nodecreate(b);
    temp=newnode;
    current=start;
    while(current->data!=a){
        current=current->next;
    }
    temp->next=current->next;
    current->next=temp;
}
void LinkedList :: delete_first(){
    temp=start->next;
    start=temp;
}
void LinkedList :: delete_last(){
    ptr=start;
    while(1){
        if(ptr->next==NULL){
            current->next = NULL;
            break;
        }
        current = ptr;
        ptr = ptr->next;
    }
}
void LinkedList :: delete_specific(){
    int a;
    cout << "Enter Specific Value: ";
    cin >> a;
    current=start;
    while(1){
        if(start -> data == a){
            start = current ->next;
            break;
        }
        else if(current->data!=a){
            ptr=current;
            current=current->next;
        }
        else{
            ptr->next=current->next;
            break;
        }
    }
}

int main(){
    LinkedList l;
    l.listcreate();
    l.display();
//    l.insert_first();
//    l.display();
//    l.insert_last();
//    l.display();
//    l.insert_before()
//    l.display();
//    l.insert_after();
//    l.display();
//    l.delete_first();
//    l.display();
//    l.delete_last();
//    l.display();
//    l.delete_specific();          ////problem- 1st input delete kora na/////
//    l.display();

    return 0;
}
