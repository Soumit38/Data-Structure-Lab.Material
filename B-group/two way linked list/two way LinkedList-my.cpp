#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *back;
};
Node *newnode, *current, *ptr, *start, *last, *temp;

class TwoWay_LinkedList{
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
void TwoWay_LinkedList :: nodecreate(int n){
    newnode=new Node;
    newnode->data=n;
    newnode->back=NULL;
    newnode->next=NULL;
}
void TwoWay_LinkedList :: listcreate(){
    char c;
    int m;
    cout << "Enter data: ";
    cin >> m;
    nodecreate(m);
    start=newnode;
    last=newnode;
    current=newnode;
    cout << "Do you want to create another? y/n ";
    cin >> c;
    while(c!='n'){
        cout << "Enter data: ";
        cin >> m;
        nodecreate(m);
        last=newnode;
        last->back=current;
        current->next=newnode;
        current=newnode;
        cout << "Do you want to create another? y/n ";
        cin >> c;
    }
}
void TwoWay_LinkedList :: display(){
    ptr=start;
    while(ptr!=NULL){
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
    cout << "end" << endl;
}
void TwoWay_LinkedList :: insert_first(){
    int a;
    cout << "Enter data: ";
    cin >> a;
    nodecreate(a);
    newnode->next=start;
    start->back=newnode;
    start=newnode;
}
void TwoWay_LinkedList :: insert_last(){
    int a;
    cout << "Enter data: ";
    cin >> a;
    nodecreate(a);
    newnode->back=last;
    last->next=newnode;
    last=newnode;
}
void TwoWay_LinkedList :: insert_before(){
    int a, b;
    cout << "Enter Specific Value: ";
    cin >> a;
    cout << "Enter data: ";
    cin >> b;
    nodecreate(b);
    current=start;
    while(1){
        if(current->data==a){
            ptr=current->back; //ptr=previous
            newnode->back=ptr;
            ptr->next=newnode;
            current->back=newnode;
            newnode->next=current;
            break;
        }
        current=current->next;
    }
}
void TwoWay_LinkedList :: insert_after(){
    int a, b;
    cout << "Enter Specific Value: ";
    cin >> a;
    cout << "Enter data: ";
    cin >> b;
    nodecreate(b);
    current=start;
    while(1){
        if(current->data==a){
            temp=current->next; //temp=Next of current
            newnode->next=temp;
            temp->back=newnode;
            current->next=newnode;
            newnode->back=current;
            break;
        }
        current=current->next;
    }
}
void TwoWay_LinkedList :: delete_first(){
    temp=start->next;
    temp->back=NULL;
    start=temp;
}
void TwoWay_LinkedList :: delete_last(){
    temp=last->back;
    temp->next=NULL;
    last=temp;
}
void TwoWay_LinkedList :: delete_specific(){
    int a;
    cout << "Enter Specific Value: ";
    cin >> a;
    current=start;
    while(1){
        if(current->data==a && current==start){
            temp=start->next;
            temp->back=NULL;
            start=temp;
            break;
        }
        else if(current->data==a && current==last){
            temp=last->back;
            temp->next=NULL;
            last=temp;
            break;
        }
        else if(current->data==a){
            ptr=current->back;
            temp=current->next;
            ptr->next=temp;
            temp->back=ptr;
            break;
        }
        current=current->next;
    }
}

int main(){
    TwoWay_LinkedList l;
    l.listcreate();
    l.display();
//    l.insert_first();
//    l.display();
//    l.insert_last();
//    l.display();
//    l.insert_before();
//    l.display();
//    l.insert_after();
//    l.display();
//    l.delete_first();
//    l.display();
//    l.delete_last();
//    l.display();
//    l.delete_specific();
//    l.display();

    return 0;
}
