#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int min)
{
    int requiredStudent=1, sum=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>min)
        {
            return false;
        }
        if(arr[i]+sum>min)
        {
            requiredStudent++;
            sum=arr[i];

            if(requiredStudent>m)
            {
                return false;
            }
        }
        else{
            sum+=arr[i];
        }
    }

    return true;
      
}

int allocateMinimumPage(int arr[], int n, int m)
{
    if(n<m)
    {
        return -1;
    }
    int sum=0;
    int ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }

    int start=0, end=sum;
    while (start<=end)
    {
        int mid=(start+end)/2;
        if(isPossible(arr,n,m,mid))
        {
            ans=min(ans,mid);
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
    
}

int main()
{
    int arr[]={12,34,67,90};
    cout<<allocateMinimumPage(arr,4,2);
    return 0;
} 