#include <iostream>
using namespace std;
class List
{
public:
    int pow;
    int co;
    class List *next;
};
//typedef class List List;

class LinkedList
{
public:
    List *ptr1,*ptr2,*start,*ptr3,*prev;;
public:
    void nodecreate(int,int);
    void Listcreate();
    LinkedList operator+(LinkedList&);
    void traverse();
};
void LinkedList :: nodecreate(int a,int b)
{
    ptr1 = new List;
    ptr1->co = a;
    ptr1->pow = b;
    ptr1->next = NULL;
}
void LinkedList :: Listcreate()
{
    int a,i,b;

    cout<<"\n********Enter power = 0 to break*********\n";
    cout<<"Enter co-efficiecnt : ";
    cin>>a;
    cout<<"Enter power : ";
    cin >> b;
    nodecreate(a,b);
    start = ptr1;
    ptr2 = start;
    i=1;
    while(1)
    {
        cout<<"Enter co-efficiecnt : ";
        cin>>a;
        cout<<"Enter power : ";
        cin >> b;
        nodecreate(a,b);
        ptr2->next = ptr1;
        ptr2 = ptr1;
        if(b<=0)
            break;
    }

}
void LinkedList :: traverse()
{
    for(ptr3=start; ptr3!=NULL; ptr3=ptr3->next)
    {
        if(ptr3->next==NULL)
            cout<<ptr3->co;
        else
            cout<<ptr3->co<<" X^" << ptr3->pow << " + ";
    }
}
LinkedList LinkedList :: operator+(LinkedList &poly1)
{
    LinkedList l;
    List *List1 = new List;
    List *List2 = new List;
    List *List3 = new List;
    l.start = start;
    List3 = start;
    List1 = l.start;
   for(List2 = poly1.start ; List2!=NULL ; List2 = List2->next)
    {
        int p=0;
         for( List1=l.start;  List1!=NULL; List1 =  List1->next)
        {
            if(List1->pow==List2->pow)
            {
                List1->co =  List1->co + List2->co;
                p=1;
                List2->pow = -1;
            }
        }
        if(p==0)
        {
             List*t;
             t= new List;
             t->co=List2->co;
             t->pow=List2->pow;
             t->next=l.start;
             l.start=t;
        }
    }
    return l;
}
int main()
{
    LinkedList L,M,SUM;
    cout << "For first polynomial ";
    L.Listcreate();
    cout << "\nThe First Polynomial is : ";
    L.traverse();

    cout << "\n\nFor Second polynomial";
    M.Listcreate();
    cout << "\nThe Second Polynomial is : ";
    M.traverse();

    SUM=L+M;
    cout << "\n\nThe Summation of two Polynomial is : ";
    SUM.traverse();
    cout << endl;
    return 0;

}
