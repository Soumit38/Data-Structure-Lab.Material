#include <iostream>
#include <cstdio>
//#include <algorithm>

using namespace std;

int counter=0;

struct link
{

    int data;

    struct link *next;


}*start = NULL;


void creat()
{
    char  s;

    for(;;)
    {
        counter++;

        struct link *new_node,*current;
        new_node = new struct link;
        cout <<"enter the data:";
        cin >> new_node -> data;

        if(start == NULL)
        {
            start = new_node;
            new_node->next= start;
            current = new_node;
        }
        else
        {

            current -> next = new_node;

            new_node->next= start;
            current = new_node;
        }
        cout <<"Do you creat another one :(y/n):";
        cin>>s;
        if(s == 'n')
        {
            break;
        }

    }


}


void delet()
{

    int num;

    cout<<"Input interval: ";
    cin>>num;
    link *current,*temp=start;

 for(;counter!=1;)
 {
     for(int i=num;i>1;i--){
        current=temp;
        temp=temp->next;
     }
     current->next=temp->next;

     counter--;

     struct link *temp1;
    temp1 = start;
    cout<<endl;
    for(int i =0;i<counter;i++)
    {
        cout <<temp1->data<<"  ";

        temp1 = temp1->next;
    }
    cout<<endl;

     temp=current->next;

 }


}
void display()
{
    struct link *temp;

    temp = start;

    for(;;)
    {
        cout <<temp->data<<"-- >";

        if(temp->next== start)
            break;

        temp = temp->next;
    }
}
int main()
{

    creat();
    display();
    delet();
//    Insert();
//    display();
//    traverse();
//    display1();

    return 0;
}


