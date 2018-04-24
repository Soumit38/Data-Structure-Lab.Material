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
