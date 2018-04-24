#include <iostream>

using namespace std;

int count=0;

void Tower_of_Hanoi(int n, char a, char b, char c){
    count++;

    if(n==1)
        cout << "Move disc " << n << " from " << a << " to " << c << endl;
    else{
        Tower_of_Hanoi(n-1, a, c, b);
        cout << "Move disc " << n << " from " << a << " to " << c << endl;
        Tower_of_Hanoi(n-1, b, a, c);
    }
}

int main(){
    int discs;
    cout << "Enter number of discs: ";
    cin >> discs;

    Tower_of_Hanoi(discs, 'A', 'B', 'C');
    cout << "It took " << count << " moves." << endl;

    return 0;
}
