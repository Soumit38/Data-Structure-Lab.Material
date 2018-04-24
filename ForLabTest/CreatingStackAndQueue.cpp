#include<bits/stdc++.h>
using namespace std;

class QUEUE
{
    public:
    int arr[500];
    int Front=1;
    int rear=1;
    void PUSH(int val)
    {
        arr[rear]=val;
        rear++;
    }
    int FRONT()
    {
        return arr[Front];
    }
    void POP()
    {
        Front++;
    }
    bool EMPTY()
    {
        if(Front==rear) return true;
        else return false;
    }
    void PRINT()
    {
        for(int i=Front;i<rear;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};



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

class VECTOR
{
    public:
    int arr[500];
    int top=0;
    void PUSH_BACK(int data)
    {
        arr[top]=data;
        top++;
    }
    int SIZE()
    {
        return top;
    }
    int operator[](int index)
    {
        return arr[index];
    }
};

int main()
{
    QUEUE q;
    STACK s;
    q.PUSH(5);
    q.PUSH(9);
    q.PRINT();
    cout<<endl<<q.FRONT()<<endl;
    s.PUSH(5);
    s.PUSH(9);
    s.PRINT();
    cout<<endl<<s.TOP()<<endl;
    VECTOR v;
    v.PUSH_BACK(8);
    cout<<v[0];
}
