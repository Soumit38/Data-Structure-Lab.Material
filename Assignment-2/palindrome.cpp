#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char s[20], c[20], i, j, len, temp=0;
    cout << "Enter a word: " << endl;
    cin >> s;
    len=strlen(s);
    j=0;
    for(i=len-1; i>=0; i--){
        c[j]=s[i];
        j++;
    }
    c[j]='\0';
    for(i=0; i<len; i++){
        if(s[i]==c[i])
            temp++;
        else
            temp=0;
    }
    if(temp==len)
        cout << "Palindrome." << endl;
    else
        cout << "Not Palindrome." << endl;

    return 0;
}
