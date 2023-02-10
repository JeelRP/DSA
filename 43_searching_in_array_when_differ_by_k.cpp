// Searching in an array where adjacent differ by at most k
// error

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[n];
    }

    // int temp[100]={0};
    sort(arr,arr+n);
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i]!=arr[i+1])
        {
            cout<<i;
        }
    }
    

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}