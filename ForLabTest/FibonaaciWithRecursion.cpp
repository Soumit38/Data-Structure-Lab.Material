#include<bits/stdc++.h>
using namespace std;
int FIBONACCI(int FIB,int N)
{
    if(N==0||N==1)
    {
        return FIB=N;
    }
    FIB=FIBONACCI(FIB,N-2)+FIBONACCI(FIB,N-1);
    return FIB;
}

int main()
{
    int num;
    cout<<"Enter a number:";
    cin>>num;
    cout<<FIBONACCI(0,num);
}
