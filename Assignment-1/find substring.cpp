//#include<iostream>
//#include<string.h>
//
//using namespace std;
//
//int main(){
//    int i, j, temp=0;
//    char str1[100], str2[20];
//
//    cout << "Enter main string : ";
//    cin >> str1;
//    cout << "Enter substring : ";
//    cin >> str2;
//    int len=strlen(str2);//will be used to compare next
//    for(i=0; str1[i]!='\0'; i++){
//        j=0;
//        {
//            while(str1[i]==str2[j] && str2[j]!='\0'){
//                i++;
//                j++;
//                temp++;
//            }
//            if(temp==len){
//                cout << "The substring is present." << endl;
//                break;
//                }
//            else
//                temp=0;
//        }
//    }
//    if(temp==0)
//        cout << "The substring is not present." << endl;
//
//    return 0;
//}
//

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
using namespace std;

bool isSubstring(char *s, char *st)
{
    int i=0, x, k, n;
    int l=strlen(st);
    while(s[i]!='\0') {
        s[i]=tolower(s[i]);
        i++;
    }
    i=0;
    while(st[i]!='\0') {
        st[i]=tolower(st[i]);
        i++;
    }
    i=0;
    while(s[i]!= '\0') {
        k=0, n=0;
        x=i;
        while(s[x]==st[k]) {
            x++;
            k++;
            n++;
            if(l==n)
                return true;
        }
        i++;
    }
    return false;
}

int main()
{
    char String[100], st[40];
    cout << "Enter AN String: " << endl;
    gets(String);
    cout << "Enter a co-string: " << endl;
    gets(st);
    cout << isSubstring(String, st) << endl;
    if(isSubstring(String, st))
        cout << "Substring" << endl;
    else
        cout << "Not substring" << endl;
    return 0;
}


