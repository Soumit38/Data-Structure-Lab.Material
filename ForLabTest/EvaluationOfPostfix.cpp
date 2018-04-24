#include<bits/stdc++.h>
using namespace std;
class STACK
{
public:
    int arr[500];
    int top=0;
    void PUSH(int val)
    {
        top++;
        arr[top]=val;
    }
    void POP()
    {
        top--;
    }
    int TOP()
    {
        return arr[top];
    }
    bool EMPTY()
    {
        if(top==0) return true;
        else return false;
    }
    void PRINT()
    {
        for(int i=1;i<=top;i++)
            cout<<arr[i]<<" ";
    }
};

int main()
{
    char P[500];
    cin>>P;
    int SIZE=strlen(P);
    STACK s;
    for(int i=0;i<SIZE;i++)
    {
        if(P[i]=='*')
        {
            int a=s.TOP()-'0';
            s.POP();
            int b=s.TOP()-'0';
            s.POP();
            s.PUSH((b*a)+'0');
        }
        else if(P[i]=='+')
        {
            int a=s.TOP()-'0';
            s.POP();
            int b=s.TOP()-'0';
            s.POP();
            s.PUSH((b+a)+'0');
        }
        else if(P[i]=='/')
        {
            int a=s.TOP()-'0';
            s.POP();
            int b=s.TOP()-'0';
            s.POP();
            s.PUSH((b/a)+'0');
        }
        else if(P[i]=='-')
        {
            int a=s.TOP()-'0';
            s.POP();
            int b=s.TOP()-'0';
            s.POP();
            s.PUSH((b-a)+'0');
        }
        else
        {
            s.PUSH(P[i]);
        }
    }
    int val=s.TOP()-'0';
    cout<<val;
    return 0;
}
