#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int Stack[50];
int top = -1;

void push(int c);
int pop();
int Operator(char x);
void evaluation(char *s);


void push(int c) {
    top++;
    Stack[top] = c;
}

int pop() {
    int c = Stack[top];
    Stack[top] = 0;
    top--;
    return c;
}

int Operator(char x) {
    switch(x) {
    case '+':
        return -1;
    case '-':
        return -2;
    case '*':
        return -3;
    case '/':
        return -4;
    case '^':
        return -5;
    default:
        return 0;

    }
}

void evaluation(char *s) {
    char ara[50], x1, x2;
    int i, j, len;

    len = strlen(s);
    for(i=0; i<len; i++) {
        int x, sum=0;
        while(isdigit(s[i])) {
            x = s[i]-'0';
            sum = 10*sum+x;
            i++;
        }
        if(sum!=0) push(sum);

        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^') {
            if(Operator(s[i])==-1)
                Stack[top-1] = Stack[top-1] + Stack[top];
            else if(Operator(s[i])==-2)
                Stack[top-1] = Stack[top-1] - Stack[top];
            else if(Operator(s[i])==-3)
                Stack[top-1] = Stack[top-1] * Stack[top];
            else if(Operator(s[i])==-4)
                Stack[top-1] = Stack[top-1] / Stack[top];

            pop();
        }

    }

}

int main()
{
    char s[50];
    gets(s);
    evaluation(s);
    cout << Stack[0];

}
