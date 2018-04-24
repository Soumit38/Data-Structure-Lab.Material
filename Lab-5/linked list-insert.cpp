#include <iostream>
#include <cstdlib>

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
    cout << "Linked-List: " << endl;
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

int main(){
    LinkedList l;
    int choice;

    cout << "Create a linked list- " << endl;
    l.listcreate();
    l.display();

    A:
        cout << "\n1.insert_first\n2.insert_last\n3.insert_before\n4.insert_after\n5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1){
            l.insert_first();
            l.display();
            goto A;
        }
        else if(choice == 2){
            l.insert_last();
            l.display();
            goto A;
        }
        else if(choice == 3){
            l.insert_before();
            l.display();
            goto A;
        }
        else if(choice == 4){
            l.insert_after();
            l.display();
            goto A;
        }
        else if(choice == 5){
            exit(0);
        }
        else{
            cout << "Invalid input." << endl;
            cout << "Enter your choice again." << endl;
            goto A;
        }

    return 0;
}
