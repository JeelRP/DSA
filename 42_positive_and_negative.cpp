#include<iostream>
using namespace std;

void swap(int arr[],int l,int r)
{
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int i=0;
    int j=n-1;

    while (i<=j)
    {
        if (arr[i]<0 && arr[j]>0)
        {
            swap(arr,i,j);
            i++;
            j--;
        }
        if (arr[i]>0 && arr[j]<0)
        {
            i++;
            j--;
        }
        
        if (arr[i]>0)
        {
            i++;
        }
        if(arr[j]<0)
        {
            j--;
        }
    }
    if (i==0 || i==n)
    {
        for(int m=0;m<n;m++)
        {
            cout<<arr[m]<<" ";
        }
    }
    else
    {
        int k=0;
        while (k<n && i<n)
        {
            swap(arr,k,i);
            k=k+2;
            i++;
        }
        for(int m=0;m<n;m++)
        {
            cout<<arr[m]<<" ";
        }
        
    }

    return 0;
}