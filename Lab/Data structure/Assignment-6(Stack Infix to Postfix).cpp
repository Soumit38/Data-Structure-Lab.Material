#include <iostream>
//ONE-WAY LINKED LIST CREATE AND TRAVERSE
using namespace std;
struct list
{
    char info;
    struct list *next;
    struct list *prev;
};

int m=0,n=0;
char post[100];

typedef struct list LIST;
LIST *ptr1,*ptr2,*start,*ptr3,*prev,*fin;

class LinkedList
{
public:
    void nodecreate(char);
    void listcreate();

    void pushStack(char);

    char popStack();

    void traverse();
};

void LinkedList :: pushStack(char a)
{
    if(a=='+'||a=='-')
       {
           if(fin->info == '+'||fin->info == '-'||fin->info == '*'||fin->info == '/'||fin->info == '%')
           {
               post[n++] = fin->info;
               popStack();
           }
       }

       else if(a=='*'||a=='/'||a=='%')
       {
           if(fin->info == '*'||fin->info == '/'||fin->info == '%')
           {
               post[n++] = fin->info;
               popStack();
           }
       }

       else if(a==')')
       {
           while(1)
           {
               post[n++] = fin->info;
               popStack();
               if(fin->info == '(')
               {
                   popStack();
                   return;
               }
           }
       }

    LIST *tmp;
    tmp = new LIST;
    tmp->info = a;
    fin->next = tmp;
    tmp->next = NULL;
    tmp->prev = fin;
    fin = tmp;
    start->prev = NULL;

}

char LinkedList :: popStack()
{
    char c;
    LIST *tmp;
    tmp = new LIST;

    tmp = fin->prev;
    tmp->next = NULL;
    c = fin->info;
    fin = tmp;
    start->prev = NULL;

    return c;
}

void LinkedList :: nodecreate(char a)
{
    ptr1 = new LIST;
    ptr1->info = a;
    ptr1->prev = NULL;
    ptr1->next = NULL;
}

void LinkedList :: listcreate()
{
    int a,i;
    string exp;
    cout << "Enter the Infix Expression : ";
    cin >> exp;
    nodecreate('\0');
        start = ptr1;
        fin = ptr1;
        ptr2 = start;

    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='%'||exp[i]=='('||exp[i]==')')
        {
            pushStack(exp[i]);
        }

        else
        {
            post[n++] = exp[i];
        }
    }

}
void LinkedList :: traverse()
{
    cout<<"\n\n*********After Traversing*********\n\t\t";

    for(ptr3=start; ptr3!=NULL; ptr3=ptr3->next)
    {
        if(ptr3->info!='\0')
          post[n++] = ptr3->info;
    }
    cout<<endl;
}

int main()
{
    LinkedList L;

    L.listcreate();
   L.traverse();

    for(int i=0;i<n;i++)
    {
        cout << post[i] << " ";
    }
    cout << endl;
}
