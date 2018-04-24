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
    char Q[500];
    char P[500];
    cin>>Q;
    int x=strlen(Q);
    Q[x]=')';
    x++;
    Q[x]='\0';
    STACK s;
    s.PUSH('(');
    int j=0;
    for(int i=0;i<x;i++)
    {
        if(Q[i]=='(') s.PUSH('(');
        else if(Q[i]=='^') s.PUSH('^');
        else if(Q[i]=='/')
        {
            while(s.TOP()=='^'||s.TOP()=='*')
            {
                P[j]=s.TOP();
                j++;
                s.POP();
            }
            s.PUSH('/');
        }
        else if(Q[i]=='*')
        {
            while(s.TOP()=='^'||s.TOP()=='/')
            {
                P[j]=s.TOP();
                j++;
                s.POP();
            }
            s.PUSH('*');
        }
        else if(Q[i]=='+')
        {
            while(s.TOP()=='^'||s.TOP()=='*'||s.TOP()=='/'||s.TOP()=='-')
            {
                P[j]=s.TOP();
                j++;
                s.POP();
            }
            s.PUSH('+');
        }
        else if(Q[i]=='-')
        {
            while(s.TOP()=='^'||s.TOP()=='*'||s.TOP()=='/'||s.TOP()=='+')
            {
                P[j]=s.TOP();
                j++;
                s.POP();
            }
            s.PUSH('-');
        }
        else if(Q[i]==')')
        {
            while(s.TOP()!='(')
            {
                P[j]=s.TOP();
                j++;
                s.POP();
            }
            s.POP();
        }
        else
        {
            P[j]=Q[i];
            j++;
        }
    }
    P[j]='\0';
    cout<<P;
    return 0;
}
