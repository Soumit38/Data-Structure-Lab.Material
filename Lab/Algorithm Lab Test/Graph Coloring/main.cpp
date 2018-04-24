#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	int n,m[10][10]={0,0},i,j,t,aj,col[10]={0},cnt=0;
	cout<<"Enter the numer of ver";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Enter the total no of adjacent node of  "<<i<<" node  :";
		cin>>t;
		for(j=1;j<=t;j++)
		{
			cout<<"Enter "<<j<<"adj node :";
			cin>>aj;
			m[i][aj]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<" "<<m[i][j];
		}
		cout<<"\n";
	}
	col[1]=10;
	cnt++;
	for(i=2;i<=n;i++)
	{
		for(j=cnt;j>0;j--)
		{
			if(m[i][j]==1)
				continue;
			else
			{
				cnt++;
				col[cnt]=col[j];
				break;
			}
		}
		if(j==0)
		{
			cnt++;
			col[cnt]=col[cnt-1]+1;
		}
	}
	for(i=1;i<=n;i++)
		cout<<"  "<<col[i];
	getch();
}
