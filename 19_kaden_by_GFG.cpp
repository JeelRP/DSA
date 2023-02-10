//OUTPUT DOES NOT MATCH WITH GFG

#include<iostream>
using namespace std;

int maxSubarraySum(int arr[], int n){
        
    int maxsum = arr[0];
    int currsum = arr[0];
    
    for (int i = 1; i < n; i++)
    {
        currsum = max(arr[i], currsum+arr[i]);
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
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

    cout<<maxSubarraySum<<endl;

    return 0;
}