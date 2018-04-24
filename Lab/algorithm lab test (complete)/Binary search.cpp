/* Code taken from saif's upload */
#include<iostream>
using namespace std;
int arr[40], n,l,k,beg=0,end,q,o;
void input()
{
    cout<<"Enter array size:\n";
    cin>>n;
    q=n;
    o=n;
    end=n-1;
    cout<<"Input array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void output(int index)
{
   cout<<"The element is in "<<index<<" index"<<endl;
}
int linear_search()
{
    cout<<"Enter the value to search:\n";
    cin>>l;
   for(int i=0;i<n;i++)
   {
       if(arr[i]==l)
       return 1;
   }
}
void bubble_sort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void multiple_value_check()
{
    int m;
    int t=0;
      for(int i=0;i<o;i++)
    {
        m=arr[i];
        for(int j=i+1;j<o;j++)
        {
            if(m==arr[j])
            {
                t++;
                cout<<"The value "<<m<<" is in the "<<i<<" and "<<j<<" index\n\n";
            }
        }
    }
    if(t<=0)
    {
        cout<<"No multiple value\n\n";
    }
}
int insert(int r)
{
    n=q+1;
    arr[n-1]=r;
    bubble_sort();
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int binary_search()
{
    bubble_sort();
    cout<<"Enter the value to search:\n";
    cin>>l;
    int mid=((beg+end)/2);
    if(arr[mid]==l)
    {
        output(mid);
    }
    else
    {
         while(beg<=end&&arr[mid]!=l)
    {
        if(l<mid)
        end=mid-1;
        else
        beg=mid+1;
        mid=((beg+end)/2);
    }
    if(arr[mid]==l)
    output(mid);
    else
    {
          cout<<"The element is not in this array\n";
          cout<<"The new array after inserting this element:\n";
          insert(l);

    }

}
}
int main()
{
    input();
    cout<<"\n\n1.Linear search(Press 1)\n2.Binary search(Press 2)\n3.Multiple value check(Press 3)\n\n";
    cin>>k;
    cout<<"\n\n";
    switch(k)
    {
        case 1:
        {
                if(linear_search()==1)
        cout<<"The element is in the array\n";
       else
         cout<<"The element is not in the array\n";
         break;
        }
        case 2:
        {
            binary_search();
            break;
        }
        case 3:
            {
                multiple_value_check();
                break;
            }

    }
}
