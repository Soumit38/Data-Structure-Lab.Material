/*
Sample input:

6                       <-number of vertices

                        <-cost matrix
0   5   100 -2  100 100
100 0   1   100 100 100
100 100 0   2   7   3
100 2   100 0   3   100
100 100 100 100 0   10
100 100 100 100 100 0

*/

#include<iostream>

using namespace std;

int main()
{
    int ver,i,j,k;
    cout << "Enter Number of vertices : ";
    cin >> ver;

    int d[ver];
    for(i=0;i<ver;i++)
    {
        if(i==0)
            d[i]=0;
        else
            d[i]=1000;
    }
    int w[ver][ver];
    int p[ver];
    for(i=0;i<ver;i++)
        p[i]=-1;

    cout << "Enter the cost matrix of the vertices : \n";

    for(i=0;i<ver;i++)
    {
        for(j=0;j<ver;j++)
        {
            cin >> w[i][j];
        }
    }
    for(int k=0;k<ver-1;k++)
    for(i=0;i<ver;i++)
    {
        for(j=0;j<ver;j++)
        {
            if(w[i][j]!=1000)
            {
                if(d[i]+w[i][j]<d[j])
                    d[j] = d[i]+w[i][j];
            }
        }
    }
   // cout << "\n\n";
    cout << "\n\nThe shortest path between the vertices of single source is : \n\n";
    for(i=0;i<ver;i++)
    {
        cout << "0 --> " << i << "  =  "  << d[i] << "\n";
    }



}
