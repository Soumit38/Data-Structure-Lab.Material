#include<bits/stdc++.h>
using namespace std;

class STACK
{
    public:
    int data[500];
    int top=0;
    void PUSH(int dat)
    {
        data[top]=dat;
        top++;
    }
    void POP()
    {
        top--;
    }
    int SIZE()
    {
        return top;
    }
    bool ISEMPTY()
    {
        if(top==0) return true;
        else return false;
    }
};


class QUEUE
{
    public:
    int Data[500];
    int FRONT=0;
    int Rear=0;
    void PUSH(int dat)
    {
        Data[Rear]=dat;
        Rear++;
    }
    void POP()
    {
        FRONT--;
    }
    int SIZE()
    {
        return (Rear-FRONT);
    }
    bool ISEMPTY()
    {
        if(Rear==FRONT) return true;
        return false;
    }
};

int main()
{
    STACK S;
    QUEUE Q;

}
