/*
sample input:

5                <-item number
1 2 3 4 5        <-input
40 50 70 72 85   <-key

*/


#include<bits/stdc++.h>   /* a header file that has all header file :p */

using namespace std;

 int item_number;
 float a[100][100]={0};
 int input[50];
 int key[50];
 float probability[50];
 float w[100][100]={0};
 int root[100][100];


 float p(int j,int k)
 {
     float min=0;
     float temp_p;
     float ans;
     for(int p=j;p<=k;p++)
     {
         ans=a[j][p-1]+a[p+1][k]+w[j][k];
         if(ans<min)
         {
             min=ans;
             temp_p=p;
         }
     }
     return temp_p;
 }


int main()
{
    float sum=0.0;

    cin>>item_number;

    for(int i=1;i<=item_number;i++)
    {
        cin>>input[i];
    }

    for(int i=1;i<=item_number;i++)
    {
        cin>>key[i];
        sum=sum+key[i];
    }

    for(int i=1;i<=item_number;i++)
    {
        probability[i]=(input[i]*key[i])/sum;
    }

    for(int k=1;k<=item_number;k++)
    {
        a[k][k]=probability[k];
        a[k][k-1]=0;
        root[k][k]=k;
        w[k][k]=probability[k];
    }
    int k;
    int q;

    for(int diagonal=1;diagonal<=item_number-1;diagonal++)
    {

        for(int j=1;j<=item_number-diagonal;j++)
        {


            k=j+diagonal;
            w[j][k]=w[j][k-1]+probability[k];

             float mini=1000.0;
        int ans=0;

        for(int p=j;p<=k;p++)
        {
            if(mini>a[j][p-1]+a[p+1][k])
                mini=a[j][p-1]+a[p+1][k],ans=p;
        }


            root[j][k]=ans;

            for(int p=j;p<=k;p++)
            {
                a[j][k]=a[j][p-1]+a[p+1][k]+w[j][k];
            }


        }
    }

cout<<"Matrix A:\n\n";

    for(int i=1;i<=item_number;i++)
    {
        for(int j=0;j<=item_number-1;j++)
        {
            if(a[i][j])
            printf("%2.3f ",a[i][j]);
            else
                printf("  0  ");
        }
        cout<<"\n";
    }

    cout<<"\n\nMatrix Root:\n\n";
    for(int i=1;i<=item_number;i++)
    {
        for(int j=1;j<=item_number;j++)
        {
            cout<<root[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}
