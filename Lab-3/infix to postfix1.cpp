#include <bits/stdc++.h>

using namespace std;

class stk
{
    char ara[100];
    int cnt;
public:
    stk()
    {
        for(int i=0;i<100;i++)
            ara[i]='\0';
        cnt=0;
    }

    void push(char n)
    {
        if(cnt>=100)
            cout<<"Stack is full\n";
        else
        {
            ara[cnt]=n;
            cnt++;
        }
    }

    void pop()
    {
        if(cnt<0)
            cout<<"Stack is empty\n";
        else
        {
            ara[cnt-1]='\0';
            cnt--;
        }
    }

    char top()
    {
        if(cnt<0)
            cout<<"Stack is empty\n";
        return ara[cnt-1];
    }
};

int precid[100];
//char preci[]={'*','/','+','-'}

int main()
{
    precid[42]=1;precid[47]=1;precid[43]=2;precid[45]=2;precid[94]=0;
    stk st;
    string str,ans;
    cin>>str;
    cout <<"Inputed String : Q = ";
    cout << str << endl;
    str+=')';
    st.push('(');
    for(int i=0;i<str.size();i++)
    {
        if((str[i]>'a' && str[i]<='z') || (str[i]>'0' && str[i]<='9'))
        ans+=str[i];
        else if(str[i]=='(')
            st.push(str[i]);
        else if(str[i]==')')
        {
            while(st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            int indx=str[i];
            int indx2=st.top();
            while((precid[indx2]<=precid[indx]) && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
                int indx2=st.top();
            }
            st.push(str[i]);
        }
    }
    cout <<endl<<"Output string: P = ";
    cout<<ans<<endl;
    return 0;
}
