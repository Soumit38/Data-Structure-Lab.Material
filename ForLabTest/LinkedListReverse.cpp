#include<bits/stdc++.h>
using namespace std;

class NODE
{
    public:
    int info;
    NODE *next;
};

NODE *START=NULL, *START2;

void nodeCreate()
{
    char ch;
    do
    {
        NODE *newNode, *currentNode;
        newNode= new NODE;
        cout<<"Enter the data: ";
        scanf("%d",&newNode->info);
        newNode->next=NULL;
        if(START==NULL)
        {
            START=newNode;
            currentNode=newNode;
        }
        else
        {
            currentNode->next=newNode;
            currentNode=newNode;
        }

        cout<<"Do you want to create another: ";
        cin>>ch;
    }while(ch!='n');
}

void insertFirst(int val)
{
    NODE *ptr1, *ptr2,*temp;
    ptr1= new NODE;
    ptr1->info =val;
    ptr1->next=NULL;
    temp=ptr1;
    ptr2=START2;
    temp->next=ptr2;
    START2=temp;
}

void REVERSELIST()
{
    NODE *newNode;
    newNode=START;
    while(newNode!=NULL)
    {
        insertFirst(newNode->info);
        newNode=newNode->next;
    }
}

void DISPLAY()
{
    NODE *newNode;
    cout<<"The linked list:"<<endl;
    newNode=START2;
    while(newNode!=NULL)
    {
        cout<<newNode->info<<"-->";
        newNode=newNode->next;
    }
    cout<<"NULL";
}

int main()
{
    nodeCreate();
    REVERSELIST();
    DISPLAY();
}



