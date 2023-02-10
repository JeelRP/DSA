#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int arr[], int n, int k, int mid)
{
    int pos=arr[0], elements=1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - pos >=mid)
        {
            pos =arr[i];
            elements++;

            if(elements==k)
            {
                return true;
            }
        }
        
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr,arr+n);
    int result= -1;
    int left=1, right=arr[n-1];
    while (left < right)
    {
        int mid=(left + right) / 2;
        if (isFeasible(arr,n,k,mid))
        {
            result=max(result,mid);
            left=mid+1;
        }
        else
        {
            right=mid;
        }
        
    }
    return result;
}

int main()
{
    int arr[]={1,2,8,4,9};
    cout<<"Largest min distance is: "<<largestMinDistance(arr,5,3);
    return 0;
}