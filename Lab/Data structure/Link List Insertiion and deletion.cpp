#include <iostream>
//ONE-WAY LINKED LIST CREATE AND TRAVERSE
using namespace std;
struct list
{
    int info;
    struct list *next;
};

typedef struct list LIST;
LIST *ptr1,*ptr2,*start,*ptr3,*prev;

class LinkedList
{
public:
    void nodecreate(int);
    void listcreate();

    void insert_first();
    void insert_last();
    void insert_any();

    void delete_first();
    void delete_any();
    void delete_last();

    void sorting();
    void traverse();
};

void LinkedList :: nodecreate(int a)
{
    ptr1 = new LIST;
    ptr1->info = a;
    ptr1->next = NULL;
}

void LinkedList :: listcreate()
{
    int a,i;

    cout<<"\n********Enter negative number to break*********\n";
    cout<<"Enter Start value : ";
    cin>>a;

    nodecreate(a);

    start = ptr1;
    ptr2 = start;                       //TO HOLD START AS START CANT BE DIRECTLY ACCESSED
    i=1;

    while(1)
    {
        i++;
        cout<<"Enter "<<i<<" : ";
        cin>>a;

        if(a<0)
            break;

        nodecreate(a);

        ptr2->next = ptr1;
        ptr2 = ptr1;
    }

}
void LinkedList :: traverse()
{
    // cout<<"\n***********After Traversing*********\n\t\t";

    for(ptr3=start; ptr3!=NULL; ptr3=ptr3->next)
        cout<<ptr3->info<<"  ";

    cout<<endl << endl;
}

void LinkedList :: insert_first()
{
    int a;
    cout << "Enter value to be inserted : ";
    cin >> a;
    LIST *tmp;
    tmp = new LIST;
    tmp->info=a;
    tmp->next=start;
    start=tmp;

}

void LinkedList :: insert_any()
{
    LIST *tmp,*t,*p;
    p=new LIST;
    tmp = new LIST;
    t=new LIST;

    int a,b;
    cout << "Enter value after which to be inserted : ";
    cin >> a;
    cout << "Enter value to be inserted : ";
    cin >> b;

    t->info=b;
    t->next=NULL;

    tmp=start;
    while(1)
    {
        if(tmp->info==a&&tmp->next!=NULL)
        {
            p=tmp;
            tmp=tmp->next;
            t->next=tmp;
            p->next=t;
            break;
        }
        else if(tmp->info==a&&tmp->next==NULL)
        {
            tmp->next=t;
            break;
        }
        tmp=tmp->next;
    }

}

void LinkedList :: insert_last()
{
    LIST *tmp,*t;
    tmp =new LIST;
    t=new LIST;

    tmp=start;
    int a;
    cout << "Enter value to be inserted : ";
    cin >> a;
    t->info=a;
    t->next=NULL;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=t;

}

void LinkedList :: delete_first()
{
    LIST *tmp;
    tmp =new LIST;
    tmp=start;
    start = start->next;
}

void LinkedList :: delete_last()
{
    LIST *tmp=start;
    LIST *t=NULL;
    while(tmp->next!=NULL)
    {
        t=tmp;
        tmp=tmp->next;

    }
    t->next=NULL;

}

void LinkedList :: delete_any()
{
    LIST *tmp=start;
    prev=NULL;
    int value ;
    cout << "Enter value to be deleted : ";
    cin >> value;
    while(tmp!=NULL)
    {
        if(tmp->info==value)
        {
            if(prev==NULL)
            {
                start=tmp->next;
            }
            else
            {
                prev->next=tmp->next;
            }
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
}

void LinkedList :: sorting()
{
    int a;
    LIST *tmp,*t;
    tmp=new LIST;
    t=new LIST;
    for(tmp=start;tmp!=NULL;tmp=tmp->next)
    {
        for(t=tmp ; t!=NULL ; t=t->next)
        {
            if(t->info<tmp->info)
            {
                a=tmp->info;
                tmp->info=t->info;
                t->info=a;
            }
        }
        traverse();
    }
}


int main()
{
    LinkedList L;//LIST

    L.listcreate();
    cout << "\nThe Linked List is : ";//LIST
    L.traverse();
    while(1)
    {
        cout << "Enter 1 for first insert : \n";
        cout << "Enter 2 for last insert : \n";
        cout << "Enter 3 for any insert : \n";
        cout << "Enter 4 for first delete : \n";
        cout << "Enter 5 for last delete : \n";
        cout << "Enter 6 for any delete : \n";
        cout << "Enter 7 for sorting list : \n";
        cout << "Enter 8 for Exit\n";
        cout << "\n";
        int n;
        cin >> n;
        cout << endl;
        switch(n)
        {
        case 1:
            L.insert_first();
            cout << "\nAfter first insertion :  ";
            L.traverse();
            break;

        case 2:
            L.insert_last();
            cout << "\nAfter last insertion :  ";
            L.traverse();
            break;

        case 3:
            L.insert_any();
            cout << "\nAfter any insertion :  ";
            L.traverse();
            break;

        case 4:
            L.delete_first();
            cout << "After first deletion :  ";
            L.traverse();
            break;

        case 5:
            L.delete_last();
            cout << "After last deletion :  ";
            L.traverse();
            break;

        case 6:
            L.delete_any();
            cout << "\nAfter any deletion :  ";
            L.traverse();
            break;

        case 7:
            L.sorting();
            cout << "After Sorting the List : ";
            L.traverse();
            break;

        }

   if(n==8)
    break;

    }
    return 0;

}
