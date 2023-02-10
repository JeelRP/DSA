#include<iostream>
using namespace std;

bool check(int arr[], int n)
{
    if (n==1)
    {
        return true;
    }
    
    bool restArray=check(arr+1,n-1);
    
    if (arr[0]<arr[1] && restArray)
    {
        return true;
    }
    return false;
        
}
int main()
{
    int n;
    cout<<"Enter limit==>";
    cin>>n;

    int arr[n];
    cout<<"Enter elements of array==>";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<check(arr,n); 
    
    return 0;
}