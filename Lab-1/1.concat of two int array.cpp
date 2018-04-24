    #include <iostream>
    #include <cstring>
    using namespace std;

    int main() {
        int m, n;
        cout << "Enter 1st array element number: ";
        cin >> m;
        int arr1[m];
        cout << "Enter 1st array element: ";

        for(int i=0; i<m; i++) {
            cin >> arr1[i];
        }

        cout << endl;
        cout << "Enter 2nd array element number: ";
        cin >> n;
        int arr2[n];
        cout << "Enter 2nd array element: ";

        for(int i=0; i<n; i++) {
            cin >> arr2[i];
        }

        int o=m+n;
        int arr3[o];

        int i, j, k=0;

        for(i=0; i<m; i++) {
            arr3[i]=arr1[i];
        }

//        for(j=i; j<o; j++) {
//            arr3[j]=arr2[k];
//            k++;
//        }

        cout << "arr1 + arr2 = ";

        for(int i=0; i<o; i++) {
            cout << arr3[i] << " ";
        }

        return 0;
    }
