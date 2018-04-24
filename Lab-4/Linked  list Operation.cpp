#include <iostream>

using namespace std;

struct list
{
    int info;
    struct list *next;
    struct list *prev;
};

typedef struct list LIST;

LIST *ptr1,*ptr2,*start,*trav,*fin;

class LinkedList
{
public :
    void createNode(int);
    void createList();

    void forwardTraverse();
    void backwardTraverse();

    void insertFirst();
    void insertLast();
    void insertAny();

    void deleteFirst();
    void deleteLast();
    void deleteAny();

};

void LinkedList :: createNode(int a)
{
    ptr1 = new LIST;
    ptr1->info = a;
    ptr1->next = NULL;
    ptr1->prev = NULL;
}

void LinkedList :: createList()
{
    ptr2 = new LIST;
    int a;
     cout<<"\n********Enter negative number to break*********\n";
    cout << "Enter first value : ";
    cin >> a;
    createNode(a);
    ptr2 = ptr1;
    start = ptr2;
    fin = ptr2;
    while(1)
    {
        cout << "Enter Others Value : ";
        cin >> a;
        if(a<0)
            break;
        createNode(a);
        ptr2->next = ptr1;
        ptr1->prev = ptr2;
        ptr2 = ptr1;
        fin = ptr2;

    }
    ptr2->next = start;
    start->prev = fin;

    cout << endl;

}

void LinkedList :: forwardTraverse()
{
    cout << "\nAfter Forward Traversing : ";
    for(trav = start; ; )
    {
        cout << trav->info << " ";
        trav=trav->next;
        if(trav==start)
            break;
    }
    cout << endl<< endl;
}

void LinkedList :: backwardTraverse()
{
    cout << "\nAfter Backward Traversing : ";
    for(trav = fin; ; )
    {
        cout << trav->info << " ";
        trav=trav->prev;
        if(trav==fin)
            break;
    }
    cout << endl << endl;
}


void LinkedList :: insertFirst()
{
    cout << "\nEnter Value to be inserted : ";
    int a;
    cin >> a;
    LIST *tmp;
    tmp = new LIST;
    tmp->info = a;
    tmp->next = start;
    start->prev = tmp;
    tmp->prev = fin;
    start = tmp ;
    fin->next=start;
  //  cout << "\n################# Atfer First Insertion ###############\n";
}

void LinkedList :: insertLast()
{
    cout << "\nEnter Value to be inserted : ";
    int a;
    cin >> a;
    LIST *tmp;
    tmp = new LIST;
    tmp->info = a;
    fin->next = tmp;
    tmp->next = start;
    tmp->prev = fin;
    fin = tmp;
    start->prev = fin;

  //  cout << "\n##################Atfer Last Insertion################";

}

void LinkedList :: insertAny()
{
    int b;
    cout << "\nEnter value after which to be inserted : ";
    cin >> b;
    cout << "\nEnter Value to be inserted : ";
    int a;
    cin >> a;

    LIST *tmp,*p;
    tmp = new LIST;
    p = new LIST;

    for(p = start ; ; p = p->next)
    {
        if(p->info==b)
        {
            createNode(a);
            tmp = p->next;

            p->next = ptr1;
            ptr1->prev = p;
            ptr1->next = tmp;
            tmp->prev = ptr1;

            break;
        }
    }

  //  cout << "\n################# Atfer Any Insertion ###############\n";

}

void LinkedList :: deleteFirst()
{
    LIST *tmp;
    tmp = new LIST;

    tmp = start->next;
    tmp->prev = fin;
    start = tmp;
    fin->next = start;
}

void LinkedList :: deleteLast()
{
    LIST *tmp;
    tmp = new LIST;

    tmp = fin->prev;
    tmp->next = start;
    fin = tmp;
    start->prev =fin;
}

void LinkedList :: deleteAny()
{
    LIST *tmp,*p;
    tmp = new LIST;
    p = new LIST;
    int b;
    cout << "Enter value to be deleted : ";
    cin >> b;

    for(tmp=start;  ; tmp = tmp->next)
    {

        if(tmp->info==b)
        {
            p=tmp->prev;
            p->next = tmp->next;
            (tmp->next)->prev = p;
            break;
        }
    }
}

int main()
{
    int choice;

    while(1)
    {
        cout << "Enter 0 for Exit : \n";
        cout << "Enter 1 for create Linked List : \n";
        cout << "Enter 2 for forward traversing : \n";
       // cout << "Enter 3 for backward traversing : \n";
//        cout << "Enter 4 for First Insert : \n";
//        cout << "Enter 5 for Last Insert : \n";
        cout << "Enter 3 for  Insert : \n";
//        cout << "Enter 7 for First Deletion : \n";
//        cout << "Enter 8 for Last Deletion : \n";
        cout << "Enter 4 for  Deletion : \n\n";

        cin >> choice;

        switch(choice)
        {
        case 1:
            LinkedList L;
            L.createList();
            break;
        case 2:
            L.forwardTraverse();
            break;
//        case 3:
//            L.backwardTraverse();
//            break;
//        case 4:
//             L.insertFirst();
//             break;
//        case 5:
//             L.insertLast();
//             break;
        case 3:
            L.insertAny();
            break;
//        case 7:
//            L.deleteFirst();
//            break;
//        case 8:
//            L.deleteLast();
//            break;
        case 4:
             L.deleteAny();
             break;


        }
        if(!choice)
            break;

    }
    return 0;
}



