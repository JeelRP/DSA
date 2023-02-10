#include<iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int low=0,high=n-1;
    while (low<high)
    {
        if(arr[low]+arr[high]<k)
        {
            low++;
        }
        if (arr[low]+arr[high]>k)
        {
            high--;
        }
        if (arr[low]+arr[high]==k)
        {
            cout<<low<<" "<<high<<endl;
            return 0;
        }
        
    }
    
    return 0;
}