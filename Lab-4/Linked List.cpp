#include<iostream>
using namespace std;
class LIST {
public:
    int info;
    LIST *next;
};
LIST *ptr1, *ptr2, *ptr3, *START,*temp;
class LinkedList {
public:
    void nodecreate(int);
    void listcreate();
    void insert_first();
    void insert_last();
    void insert_after_specific();
    void delete_first();
    void delete_last();
    void delete_specific();
    void traverse();
    void display();
};

void LinkedList::nodecreate(int a) {
    ptr1= new LIST;
    ptr1->info =a;
    ptr1->next=NULL;
}

void LinkedList::listcreate() {
    int a,i;
    cout<<"************Enter Negative Number to Break***********"<<endl;
    cout<<"Enter Start Value: ";
    cin>>a;
    nodecreate(a);
    START=ptr1;
    ptr2=START;
    i=1;
    while(a) {
        i++;
        cout<<"Enter "<<i<<": ";
        cin>>a;
        if(a<0) break;
        nodecreate(a);
        ptr2->next = ptr1;
        ptr2=ptr1;
    }
}

void LinkedList::insert_after_specific() {
    int a,b;
    cout<<"Enter Specific Value: ";
    cin>>a;
    cout<<"Enter New Value:";
    cin>>b;
    nodecreate(b);
    temp=ptr1;
    for(ptr2=START; ptr2->info!=a; ptr2=ptr2->next);
    temp->next=ptr2->next;
    ptr2->next=temp;
}
void LinkedList::insert_first() {
    int a;
    cout<<"Enter New Value: ";
    cin>>a;
    nodecreate(a);
    temp=ptr1;
    ptr2=START;
    temp->next=ptr2;
    START=temp;
}

void LinkedList::insert_last() {
    int a;
    cout<<"Enter New Value: ";
    cin>>a;
    nodecreate(a);
    temp=ptr1;
    for(ptr2=START; ptr2->next!=NULL; ptr2=ptr2->next);
    ptr2->next=temp;
}



void LinkedList::traverse() {
    //cout<<"****** After Traversing *******"<<endl;
    for(ptr3=START; ptr3!=NULL; ptr3=ptr3->next);
    //cout<<ptr3->info<<" "; //cout<<endl;
}

void LinkedList::display() {
    cout<<"***************Now Linked List **********************"<<endl<<endl<<endl;
    for(ptr3=START; ptr3!=NULL; ptr3=ptr3->next) {
        cout<<ptr3->info<<" ";
    }
    cout<<endl<<endl;
}

void LinkedList::delete_first() {
    temp=START->next;
    START=temp;
}
void LinkedList::delete_last() {
    for(ptr3=START;;) {
        if(ptr3->next!=NULL) {
            ptr2=ptr3;
            ptr3=ptr3->next;

        } else break;

    }
    ptr2->next=NULL;
    ptr3=ptr2;
}

void LinkedList::delete_specific() {
    cout<<"Enter your specific element for delete: ";
    int a;
    cin>>a;
    for(ptr2=START; ;) {
        if(ptr2->info!=a) {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }

        else break;
    }
    ptr1->next=ptr2->next;
    ptr2=ptr1;
}
int main() {
    LinkedList l;
    l.listcreate();
//l.traverse();
    l.insert_after_specific();
    l.display();


    l.delete_specific();
    l.display();
}
