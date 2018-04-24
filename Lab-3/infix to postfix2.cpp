#include <iostream>
#include <string>
using namespace std;

int precedence(char c)
{
    if(c == '-' || c == '+')
        return 1;
    else if(c=='*' || c == '/' )
        return 2;
    else if( c == '^')
        return 3;
    else if( c == '(')
        return 4;
    else
        return 5;
}

int main()
{
    string str;
    cout << "Input string :";
    cin>>str;
    int len = str.size();
    char s[len+2];

    for(int i = 0; i < len+1; i++)
    {
        if(str[i] == '\0')
            {
                s[i]=')';
                s[i+1]='\0';
            }
            else
            s[i]=str[i];
    }
    cout <<"Inputed String : Q = ";
    for(int i = 0; i < len+1; i++)
    {
        cout <<s[i];
    }

    char ary1[len]  ,ary2[len];
    ary1[0]='(';
    int i =  0;
    int Count_2 = 0;
    int Count_1 = 1;
    while(s[i] != '\0')
    {
        if((s[i]>='0'&&s[i]<='9') || (s[i]>='a'&&s[i]<='z'))
        {
            ary2[Count_2] = s[i];
            Count_2++;
        }
        else
        {
            int p = precedence(s[i]);

            if(p == 4)
            {
                ary1[Count_1] = s[i];
                Count_1++;
            }
            else if(p == 5)
            {
                int j = Count_1-1;
                while( precedence(ary1[j])!= 4)
                {
                    ary2[Count_2] = ary1[j];
                    Count_2++;
                    j--;
                }
                Count_1 = j;
            }
            else
            {

                if(precedence(ary1[Count_1-1]) < precedence(s[i]))
                {

                    ary1[Count_1] = s[i];
                    Count_1++;
                }
                if(precedence(ary1[Count_1-1]) >= precedence(s[i]))
                {
                    if(precedence(ary1[Count_1-1]) == 4)
                    {
                        ary1[Count_1] = s[i];
                        Count_1++;
                    }
                    else
                    {
                        ary2[Count_2] = ary1[Count_1-1];
                        ary1[Count_1-1] = s[i];
                        Count_2++;
                    }
                }
            }
        }
        i++;
    }

    cout <<endl<<"Output string: P = ";

    for(int i = 0; i <  Count_2 ; i++)
    {
        cout << ary2[i];
    }
    return 0;
}
