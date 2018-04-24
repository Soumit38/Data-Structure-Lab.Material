#include<iostream>
#include <cstdio>

using namespace std;

struct two_link{

int data;
two_link *forward;
two_link *back;


}*start=NULL,*last=NULL;


void create()
{
    char c;

    for(;;){

        two_link *new_node,*current;

        new_node=new struct two_link;

        cout<<"Enter data:";
        cin>>new_node->data;
        new_node->back=NULL;
        new_node->forward=NULL;

        if(start==NULL&&last==NULL)
        {
                start=new_node;
                last=new_node;
                current=new_node;
        }
        else{
            last=new_node;
            new_node->back=current;
            current->forward=new_node;
            current=new_node;
        }

        cout<<"Do you want to create any more?(y/n):";
        cin>>c;
        if(c=='n')
        {
            break;
        }


    }


}

void insert()
{
    int data1;
    cout<<"\nInserted data: ";
    cin>>data1;

    cout<<"(1).at Begin\n(2).at End\n(3).After a Specific location\n(4).before a Specific location\n(5).Deleted\nEnter Your choice:";
    char chose;
    cin>>chose;

    two_link *New=new struct two_link;
    New->back=NULL;
    New->forward=NULL;
    New->data=data1;
    two_link *temp;


    if(chose == '1')
    {
        //temp=start;

        New->forward=start;
        start->back=New;
        start=New;
    }
    else if(chose == '2')
    {
        //temp=last;

        New->back=last;
        last->forward=New;
        last=New;
    }

    else if(chose == '3')
    {
        cout<<"Enter your specific item:";
        int item;
        cin>>item;
        temp=start;
        for(;temp!=NULL;)
        {
            if(temp->data == item)
            {
                two_link *next;
                next=temp->forward;
                New->forward=next;
                next->back=New;
                temp->forward=New;
                New->back=temp;
                break;
            }
            temp=temp->forward;
        }
    }
    else if(chose == '4')
    {
        cout<<"Enter your specific item:";
        int item;
        cin>>item;
        temp=start;
        for(;temp!=NULL;)
        {
            if(temp->data == item)
            {
                two_link *pre;
                pre=temp->back;
                New->back=pre;
                pre->forward=New;
                temp->back=New;
                New->forward=temp;
                break;
            }
            temp=temp->forward;
        }
    }
    else if(chose == '5')
    {
        cout<<"Enter your deleted item:";
        int item;
        cin>>item;
        temp=start;
        for(;temp!=NULL;)
        {
            if(temp->data == item&&temp==start)
            {
                two_link *next=temp->forward;
                start=temp->forward;
                next->back=NULL;


                break;
            }
            else if(temp->data == item&&temp==last)
            {
              two_link *pre=temp->back;
                last=pre;
                pre->forward=NULL;

                break;
            }
            else if(temp->data == item)
            {
                two_link *pre,*next;
                pre=temp->back;
                next=temp->forward;

                pre->forward=next;
                next->back=pre;


                break;
            }
            temp=temp->forward;
        }
    }

}

void display()
{
    two_link *temp;
    temp=start;

    for(;temp!=NULL;)
    {
        cout<<temp->data<<"-->";
        temp=temp->forward;
    }
}

int main()
{
    create();
    display();
    insert();
    display();

    return 0;
}
