#include<iostream>
#include<climits>
using namespace std;

long long maxProduct(int *arr, int n) {
    int maxval=arr[0];
    int minval=arr[0];
    
    int ans=arr[0];
    
    for(int i=1;i<n;i++)
    {   
        if(arr[i]<0)
        swap(maxval,minval);
        
        minval=min(arr[i],minval*arr[i]);
        maxval=max(arr[i],maxval*arr[i]);
        
        ans=max(ans,maxval);
    }
    return ans;
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

    cout<<maxProduct(arr, n)<<endl;
    return 0;
}