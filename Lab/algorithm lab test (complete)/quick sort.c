/*

How this code works:

Input: [13 81 92 65 43 31 57 26 75 0]
Pivot: 65
Partition:  [13 0 26 43 31 57]  65  [ 92 75 81]
Pivot: 31  81
Partition: [13 0 26]  31  [43 57]  65  [75]  81  [92]
Pivot: 13
Partition: [0]  13  [26]  31  [43 57]  65  [75]  81  [92]
Combine: [0 13 26]  31 [43 57]  65  [75 81 92]
Combine: [0 13 26 31 43 57]  65  [75 81 92]
Combine: [0 13 26 31 43 57 65 75 81 92]


*/



#include <stdio.h>


int partition ( int a[ ], int lower, int upper )
{
    int i, p, q, t ;

    p = lower + 1 ;
    q = upper ;
    i = a[lower] ;

    while ( q >= p )
    {
        while ( a[p] < i )
            p++ ;

        while ( a[q] > i )
            q-- ;

        if ( q > p )
        {
            t = a[p] ;
            a[p] = a[q] ;
            a[q] = t ;
        }
    }

    t = a[lower] ;
    a[lower] = a[q] ;
    a[q] = t ;

    return q ;
}

void quickSort( int a[], int l, int r)
{
   int j;

   if(l<r)
   {
        j = partition(a,l,r); /*Find pivot */
       quickSort(a,l,j-1);
       quickSort(a,j+1,r);
   }

}

void main()
{
	int a[100] = {};
	int n,i;
	printf("Enter number of elements:");
	scanf("%d",&n);

	printf("Enter %d elements: \n",n);
	for(i=0;i<n;i++)
        scanf("%d",&a[i]);

	printf("\n\nUnsorted array:  ");
	for(i=0;i<n;i++)
		printf("%2d ",a[i]);

	quickSort(a,0,n-1);

	printf("\n\n  Sorted array:  ");
	for(i=0;i<n;i++)
		printf("%2d ",a[i]);

printf("\n");
}
