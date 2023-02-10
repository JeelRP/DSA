//Minimum SubArray using Sliding Window

#include<iostream>
using namespace std;

int minSubArraySize(int arr[], int n, int x)
{
    int ans=INT_MAX;
    int sum=0;
    int start=0, end=0;
    
    while (end<n)
    {
        while (sum<=x && end<n)
        {
            sum+=arr[end];
            end++;
        }

        while (sum>x && start<n)
        {
            ans=min(ans,end-start);
            sum-=arr[start];
            start++;
        }
    
    }
    return ans;   
}
int main()
{
    int arr[] = {1,4,45,6,10,19};

    cout << minSubArraySize(arr,6,51) << endl;
    return 0;
}