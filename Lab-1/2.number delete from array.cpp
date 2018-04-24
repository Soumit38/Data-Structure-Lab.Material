#include <iostream>

using namespace std;

int main()
{
    int m, n, p;
    cout << "Enter array element number: ";
    cin >> m;
    int array[m];
    cout << "Enter array element : ";
    for(int i=0; i<m; i++){
        cin >> array[i];
    }
    cout << "Enter number: ";
    cin >> n;

    for(int i=0; i<m; i++){
        if(array[i]==n){
            p=i;
            while(p!=m){
                array[p]=array[p+1];
                p++;
            }
            m--;
            //i--;
        }
    }
    cout << endl;
    for(int i=0; i<m; i++){
        cout << array[i] << " ";
    }
    return 0;
}
