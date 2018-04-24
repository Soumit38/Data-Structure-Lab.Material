#include <bits/stdc++.h>

using namespace std;

int find_portion(int a[], int left, int right){
    int pivot=a[left], i=left, j=right;

    while(i<j){
        while(a[i]<pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(a[i]==a[j])
            i++;
        else //if(i<j)
            swap(a[i], a[j]);
    }
    return j;
}

void quicksort(int a[], int left, int right){
    if(left<right){
        int p;
        p=find_portion(a, left, right);
        quicksort(a, left, p-1);
        quicksort(a, p+1, right);
    }
}

int main(){
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int a[10], Beg=0, End=n-1;

    cout << "Input array element: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    quicksort(a, Beg, End);

    cout << "Sorted array : ";

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
/*
#include<bits/stdc++.h>

using namespace std;

void quicksort(int a[],int left,int right){
    int pivot, i, j, temp;

     if(left<right){
         pivot=left;
         i=left;
         j=right;

         while(i<j){
             while(a[i]<=a[pivot] && i<right)
                 i++;
             while(a[j]>a[pivot])
                 j--;
             if(i<j)
                 swap(a[i], a[j]);
         }

         swap(a[pivot], a[j]);

         quicksort(a,left,j-1);
         quicksort(a,j+1,right);
    }
}

int main(){
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int a[n], Beg=0, End=n-1;

    cout << "Input array element: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    quicksort(a, Beg, End);

    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
*/
/*
#include <bits/stdc++.h>

using namespace std;

int find_pivot(int a[], int left, int right){
    int pivot=a[left], i=left, j=right;

    while(1){
        while(a[i]<pivot && a[i]!=pivot)
            i++;
        while(a[j]>pivot && a[j]!=pivot)
            j--;
        if(i<j){
            swap(a[i], a[j]);
        }
        else
            return j;
    }
}

void quicksort(int a[], int left, int right){
    if(left<right){
        int p;
        p=find_pivot(a, left, right);
        quicksort(a, left, p);
        quicksort(a, p+1, right);
    }
}

int main(){
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int a[n], Beg=0, End=n-1;

    cout << "Input array element: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    quicksort(a, Beg, End);

    cout << "Sorted array : ";

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int quick(int *p,int beg,int end)
{
    int left=beg,right=end,loc=beg,temp;
    while(1)
    {
        while(*(p+loc)<=*(p+right)&&loc!=right)
            right=right-1;
        if(loc==right)
            return(loc);
        if(*(p+loc)>*(p+right))
        {
            temp=*(p+loc);
            *(p+loc)=*(p+right);
            *(p+right)=temp;
        }
        loc=right;
        while(*(p+loc)>=*(p+left)&&loc!=left)
            left=left+1;
        if(loc==left)
            return(loc);
        if(*(p+loc)<*(p+left))
        {
            temp=*(p+left);
            *(p+left)=*(p+loc);
            *(p+loc)=temp;
        }
        loc=left;
    }
}

int main()
{
    int A[20],*p,i,upper[5],lower[5],top=-1,n,beg,end,loc;
    printf("\nEnter Number Of Elements: ");
    scanf("%d",&n);
    printf("\nEnter Values: \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }
    p=&A[0];
    if(n>1)
    {
        top=top+1;
        upper[0]=n-1;
        lower[0]=0;
    }
    while(top!=-1)
    {
        beg=lower[top];
        end=upper[top];
        top=top-1;
        loc=quick(p,beg,end);
        if(beg<(loc-1))
        {
            top=top+1;
            lower[top]=beg;
            upper[top]=loc-1;
        }
        if(loc+1<end)
        {
            top=top+1;
            lower[top]=loc+1;
            upper[top]=end;
        }
    }
    printf("\nSorted Values Are:");
    for(i=0; i<n; i++)
        printf(" %d ",A[i]);


}
*/

/*
#include<iostream>

using namespace std;

int partition( int a[] ,int p ,int r )
{
    int i,j,pivot,temp ;
    pivot=a[p] ;
    i=p ;
    j=r ;
    while ( 1 )
    {
        while(a[i]<pivot &&   a[i]   !=   pivot )
        i++;
        while( a[j]   >   pivot   &&   a[j]   !=   pivot )
        j--;
        if (i  <  j )
        {
            temp   =   a[i] ;
            a[i]   =   a[j] ;
            a[j]   =   temp ;
        }
        else
        {
            return   j ;
        }
    }
}




void quicksort( int a[], int p, int r )
{
    if(p<r)
    {
        int q ;
        q   =   partition ( a ,   p ,   r ) ;
        quicksort ( a ,   p ,   q ) ;
        quicksort ( a ,   q + 1 ,   r ) ;
    }
}



int  main()
{
    int n,i,j,k;
    cout << "Enter array size : ";
    cin >> n;
    cout << "Enter the array elements : ";
    int arr[n];

    for(i=0; i<n; i++)
        cin >> arr[i];
    quicksort(arr,0,n-1);

    cout << "The sorted array is : ";
    for(i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;

}
*/

/*
//Program in C++ --- Quick Sort
#include <iostream>
#include<conio.h>
using namespace std;

int Partition(int a[], int beg, int end)          //Function to Find Pivot Point
{
int p=beg, pivot=a[beg], loc;

for(loc=beg+1;loc<=end;loc++)
{
if(pivot>a[loc])
{
a[p]=a[loc];
a[loc]=a[p+1];
a[p+1]=pivot;

p=p+1;
}
}
return p;
}


void QuickSort(int a[], int beg, int end)
{
if(beg<end)
{
int p=Partition(a,beg,end);                       //Calling Procedure to Find Pivot

QuickSort(a,beg,p-1);                             //Calls Itself (Recursion)
QuickSort(a,p+1,end);			              //Calls Itself (Recursion)
}
}


int main()
{
//clrscr();
int a[100],i,n,beg,end;

cout<<"\n------- QUICK SORT -------\n\n";
cout<<"Enter the No. of Elements : ";
cin>>n;

for(i=1;i<=n;i++)
{
cin>>a[i];
}
beg=1;
end=n;

QuickSort(a,beg,end);                        	  //Calling of QuickSort Function

cout<<"\nAfter Sorting : \n";
for(i=1;i<=n;i++)
{
cout<<a[i]<<endl;
}
getch();
return 0;
}
*/
