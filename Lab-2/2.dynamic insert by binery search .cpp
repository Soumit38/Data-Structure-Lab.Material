#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[100], high, low, n=0, i, key, middle, temp;

    cin >> a[0];
    n++;
    while(1){
        cin >> key;
        if(key==-1)
            break;

        low=0;
        high=n-1;
        while(low <= high){
            middle = (low+high)/2;
            if(key==a[middle]){
                temp=1;
                break;
            }
            else if(key < a[middle])
                high=middle-1;
            else
                low=middle+1;
        }
        if(temp==1)
            cout << "Found " << key << " index " << middle << endl;
        else{
            cout << "Not found." << endl;
            cout << "The element is inserted in the array." << endl;
            if(key < a[middle]){
                a[n]=key;
                n=n+1;
                sort(a, a+n);
                for(int i=0; i<n; i++){
                    cout << a[i] << " ";
                }
            }
            else{
                a[n]=key;
                n=n+1;
                sort(a, a+n);
                for(int i=0; i<n; i++){
                    cout << a[i] << " ";
                }
            }

        }
    }
    return 0;
}
