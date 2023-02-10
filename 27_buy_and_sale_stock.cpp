#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int minarr=INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minarr=min(minarr,arr[i]);
    }
    int k;
    arr[k]=minarr;
    if (minarr=arr[n-1])
    {
        return -1;
    }
    
    int maxarr=INT_MIN;
    for (int i = k; i < n; i++)
    {
        maxarr=max(maxarr,arr[i]);
    }

    int ans;
    ans=maxarr-arr[k];

    cout<<ans<<endl;
    return 0;
}