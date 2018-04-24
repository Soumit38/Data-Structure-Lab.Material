    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int m, n;
        cout<< "Enter no of elements in first array: ";
        cin>>m;
        int arrOne[m];
        for(int i=0; i<m; i++){
            cin>>arrOne[i];
        }

        cout<< "Enter no of elements in second array : " ;
        cin>>n;
        int arrTwo[n];
        for(int i=0; i<n; i++){
            cin>>arrTwo[i];
        }

        int o = m+n;
        int arrThree[0];
        int i;
        for( i=0;i<m; i++){
            arrThree[i] = arrOne[i];
        }

        int j,k=0;
        for(j=i; j<o; j++){
            arrThree[j] = arrTwo[k];
            k++;
        }



        for(int i=0; i<o; i++){
            cout<< arrThree[i];
        }

    }






















