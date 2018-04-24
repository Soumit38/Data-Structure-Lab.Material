#include <bits/stdc++.h>

using namespace std;

struct mylist
{
    int data,row,col;
    mylist *prev_row,*next_row,*prev_col,*next_col;
};

mylist *row[100]= {NULL};
mylist *col[100]= {NULL};
mylist *cur_col[100]= {NULL};

void print_row(mylist *start)
{
    while(start!=NULL)
    {
        if(start->data)
        {
            cout<<start->data<<" "<<"column = "<<start->col<<endl;
        }
        start=start->next_col;
    }
}

void print_col(mylist *start)
{
    while(start!=NULL)
    {
        if(start->data)
        {
            cout<<start->data<<" "<<"row = "<<start->col<<endl;
        }
        start=start->next_row;
    }
}

int main()
{
    mylist *temp,*cur;
    int num;
    int n,m;
    cout << "Enter row and col: ";
    cin>>n>>m;
    cout << "Enter data: " << endl;
    int i,j;
    for(i=0; i<n; i++)
    {
        mylist *cur_row;
        for(j=0; j<m; j++)
        {
            cin>>num;
            temp=new mylist;
            temp->data=num;
            temp->row=i+1;
            temp->col=j+1;
            if(row[i]==NULL)
            {
                row[i]=temp;
                cur_row=temp;
            }
            else
            {
                cur_row->next_col=temp;
                cur_row=temp;
            }
            if(col[j]==NULL)
            {
                col[j]=temp;
                cur_col[j]=temp;
            }
            else
            {
                cur_col[j]->next_row=temp;
                cur_col[j]=temp;
            }
            temp->next_row=NULL;
        }
        cur_row->next_col=NULL;
    }

    for(i=0 ; i<n; i++)
    {
        cout<<"row "<<i+1<<" data: "<<endl;;
        print_row(row[i]);
        cout<<endl;
    }

    for(i=0 ; i<m; i++)
    {
        cout<<"Column "<<i+1<<" data: "<<endl;
        print_col(col[i]);
        cout<<endl;
    }

    return 0;
}

