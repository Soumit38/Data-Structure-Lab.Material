#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char Stack[50]= {'('};
int Stack_top=0;

char Postfix[50];
int P_top=-1;

void pushStack(char c);
char popStack();
void pushPostfix(char c);
int prcd(char symbol);
void infixToPostfix(char *s);

void pushStack(char c)
{
    Stack_top++;
    Stack[Stack_top] = c;
    Stack[Stack_top+1] = '\0';
}

char popStack()
{
    char c = Stack[Stack_top];
    Stack[Stack_top] = '\0';
    Stack_top--;
    return c;
}

void pushPostfix(char c)
{
    P_top++;
    Postfix[P_top] = c;
}

int prcd(char symbol)
{
    switch(symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 6;
    }
}


void infixToPostfix(char *s)
{
    char ara[50], c;
    int i, j, len;

    len = strlen(s);
    for(i=0; i<len; i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='(' || s[i]==')' || s[i]=='^')
        {
            pushStack(s[i]);
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                while((Stack[Stack_top-1]!='(') && prcd(Stack[Stack_top])<=prcd(Stack[Stack_top-1]))
                {
                    char x1 = popStack();
                    char x2 = popStack();
                    pushPostfix(x2);
                    pushStack(x1);
                }
            }

            else if(s[i]==')')
            {
                popStack();
                while(Stack[Stack_top]!='(')
                {
                    char x3 = popStack();
                    pushPostfix(x3);
                }
                popStack();
            }

        }

        else if(s[i]>=48 || s[i]<=57)
            pushPostfix(s[i]);
        else if(s[i]==' ')
            pushPostfix(s[i]);

    }

}


int main()
{
    char s[50];
    gets(s);
    infixToPostfix(s);
    puts(Stack);
    puts(Postfix);

    return 0;
}
