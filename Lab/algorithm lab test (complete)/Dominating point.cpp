#include<iostream>

using namespace std;
double coOrdinate[1000][2];

void superior(int freq[],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(coOrdinate[i][0]>coOrdinate[j][0]  &&  coOrdinate[i][1]>coOrdinate[j][1])
                freq[i]++;
        }
    }
}

int main()
{
    int n,k;
    cout << "Enter number of co-ordinates : ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin >> coOrdinate[i][j];
        }
    }
    int superiorIndex[1000]= {0};
    superior(superiorIndex,n);


    cout << "+++ The Original points:\n";
    for(int i=0; i<n; i++)
    {
        cout << "(";
        for(int j=0; j<2; j++)
        {
            if(j==0)
                cout << coOrdinate[i][j] <<  ",";
            else
                cout << coOrdinate[i][j];
        }
        cout << ") ";
    }
    cout << "\n\n+++ Superiority indices (quadratic-time) :\n\n";
    for(int i=0; i<n; i++)
    {
        cout << superiorIndex[i] << " " ;
    }

    cout <<  "\n";

}
