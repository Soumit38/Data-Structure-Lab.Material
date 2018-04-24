#include<iostream>
#include<stdio.h>

using namespace std;

int LOC,BEG,END,TOP,LOWER[100],UPPER[100];
int LEFT,RIGHT;
int temp;




void quick_sort(int a[],int n)
{
    LEFT=BEG;//1
    RIGHT=END;//4
    LOC=BEG;//1
      cout<<"\n\n";
cout<<LEFT<<endl;
cout<<RIGHT<<endl;
cout<<LOC<<endl;


    A:

    while(a[LOC]<=a[RIGHT] && LOC!=RIGHT)
    {
        RIGHT=RIGHT-1;
    }


    if(LOC==RIGHT)
        return;


    if(a[LOC]>a[RIGHT])
    {
        temp=a[LOC];
        a[LOC]=a[RIGHT];
        a[RIGHT]=temp;
        LOC=RIGHT;
        goto B;
    }


    B:

    while(a[LEFT]<=a[LOC] && LOC!=LEFT)
    {
       LEFT=LEFT+1;
    }


    if(LOC==LEFT)
        return;


    if(a[LEFT]>a[LOC])
    {
        temp=a[LOC];
        a[LOC]=a[LEFT];
        a[LEFT]=temp;

        LOC=LEFT;

        goto A;
    }



}



int main()// 22 33 11 66
{
    int number_of_elements;
    int elements[100];


    cout<<"Enter number of elements to sort:";
    cin>>number_of_elements;


    cout<<"\nEnter elements:\n";
    for(int i=1;i<=number_of_elements;i++)
    {
        cin>>elements[i];
    }


    TOP=NULL;//0

    if(number_of_elements>1)
    {
        TOP=TOP+1;//1
        LOWER[TOP]=1;//1
        UPPER[TOP]=number_of_elements;//4
    }


    while(TOP!=NULL)//1
    {
        BEG=LOWER[TOP];//1
        END=UPPER[TOP];//4
        cout<<"\n\n";

         cout<<BEG<<" ";
          cout<<END<<"\n";

        TOP=TOP-1;//0

        quick_sort(elements,number_of_elements);

     cout<<"\n\n";

    for(int i=1;i<=number_of_elements;i++)
    {
        cout<<elements[i]<<" ";
    }


        if(BEG<LOC-1)
        {
            TOP=TOP+1;
            LOWER[TOP]=BEG;
            UPPER[TOP]=LOC-1;
        }

        if(LOC+1<END)
        {
            TOP=TOP+1;
            LOWER[TOP]=LOC+1;
            UPPER[TOP]=END;
        }

        cout<<"\n\n";


    }

  cout<<"\n\n";
    for(int i=1;i<=number_of_elements;i++)
    {
        cout<<elements[i]<<" ";
    }

    return 0;

}
