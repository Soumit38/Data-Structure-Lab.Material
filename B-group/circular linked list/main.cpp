#include<iostream>

using namespace std;

struct lList
{
    int info;
    struct lList *next;
}*start=NULL;

int delList(int n);
void showList(int n);

int main()
{
    int nNum=0;
    char choice;
    struct lList *p,*current;

    cout<<"Do you want to add a node? y/n\n";
    while(cin>>choice && choice=='y')
    {
        p=new lList;
        nNum++;

        if(start==NULL)
            start=p;
        else
            current->next=p;

        current=p;

        cout<<"\nWhich interval do you want?:";
        cin>>current->info;

        cout<<"\nDo you want to add another node?y/n\n";
    }
    current->next=start;

    showList(nNum);

    nNum=delList(nNum);

    cout<<"\nFinal List:\n";
    showList(nNum);

    return 0;
}

void showList(int n)
{
    struct lList *p=start;

    for(int i=1;i<=n;p=p->next,i++)
        cout<<"\nNode "<<i<<":"<<p->info;
    cout<<endl;
}

int delList(int n)
{
    int i,choice;
    struct lList *p,*current;
    cout<<"\nInput Number:";
    cin>>choice;

    for(i=1,p=start;;p=p->next)
    {
        if(i==n)
            break;
        i++;
    }
    current=p;

    for(i=1,p=start;n>1;i++)
    {
        if(i==choice)
        {
            i=0;
            n=n-1;
            current->next=p->next;
            if(p==start)
                start=p->next;
            p=p->next;
            cout<<"\nModified List:\n";
            showList(n);
        }
        else
        {
            current=p;
            p=p->next;
        }
    }
    return n;
}
