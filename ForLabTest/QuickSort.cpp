#include<bits/stdc++.h>
using namespace std;

int UPPER[10000];
int LOWER[10000];

int LEFTARRAY(int A[],int LEFT,int RIGHT,int LOC);
int RIGHTARRAY(int A[],int LEFT,int RIGHT,int LOC)
{
    while(A[LOC]<=A[RIGHT]&&RIGHT!=LOC)
    RIGHT--;
    if(LOC==RIGHT) return LOC;
    if(A[LOC]>A[RIGHT])
    {
        swap(A[LOC],A[RIGHT]);
        LOC=RIGHT;
        LOC=LEFTARRAY(A,LEFT,RIGHT,LOC);
    }
}

int LEFTARRAY(int A[],int LEFT,int RIGHT,int LOC)
{
    while(A[LEFT]<=A[LOC]&&LEFT!=LOC)
        LEFT++;
    if(LOC==LEFT) return LOC;
    if(A[LEFT]>A[LOC])
    {
        swap(A[LEFT],A[LOC]);
        LOC=LEFT;
        LOC=RIGHTARRAY(A,LEFT,RIGHT,LOC);
    }
}

int QUICK(int A[],int SIZE,int BEG,int END,int LOC)
{
    int LEFT,RIGHT;
    LEFT=BEG;
    RIGHT=END;
    LOC=BEG;
    LOC=RIGHTARRAY(A,LEFT,RIGHT,LOC);
    return LOC;
}

void QUICKSORT(int A[],int SIZE)
{
    int TOP=0;
    int LOC=0;
    if(SIZE>1)
    {
        TOP++;
        LOWER[1]=0;
        UPPER[1]=SIZE;
    }
    while(TOP!=0)
    {
        int BEG=LOWER[TOP];
        int END=UPPER[TOP];
        TOP--;
        LOC=QUICK(A,SIZE,BEG,END,LOC);
        if(BEG<LOC-1)
        {
            TOP++;
            LOWER[TOP]=BEG;
            UPPER[TOP]=LOC-1;
        }
        if(LOC+1<END)
        {
            TOP++;
            LOWER[TOP]=LOC+1;
            UPPER[TOP]=END;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int Arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>Arr[i];
    }
    QUICKSORT(Arr,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<Arr[i]<<" ";
    }
}

