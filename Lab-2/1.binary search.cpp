#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[20], n, low, middle, high, key, flag;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter array element: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cout << "Enter key: ";
    cin >> key;

    low=0;
    high=n-1;
    while(low <= high){
        middle = (low+high)/2;
        if(key==a[middle]){
            flag=1;
            break;
        }
        else if(key < a[middle])
            high=middle-1;
        else
            low=middle+1;
    }
    if(flag==1)
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

    return 0;
}
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[50], n, key, low, middle, high, flag=0;

    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter array element: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << "Enter key: ";
    cin >> key;
    low=0;
    high=n-1;
    while(low <= high){
        middle=(low+high)/2;

        if(key==a[middle]){
            flag++;
            break;
        }
        else if(key<a[middle])
            high=middle-1;
        else
            low=middle+1;
    }
    if(flag==0){
        cout << "Element not found" << endl;
        cout << "The element is inserted in the array." << endl;
        int i=n+1;
        while(i>=low){
            a[i+1]=a[i];
            i--;
        }
        if(a[low]>key){
            a[low]=key;
        }
        else{
            a[low+1]=key;
        }
        for(int i=0; i<n+1; i++){
            cout << a[i] << " ";
        }
    }
    else
        cout << "Found element " << key << " at index " << middle << endl;

    return 0;
}
*/
