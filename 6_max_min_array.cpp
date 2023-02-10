#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int maxNo=0;
    int minNo;

    for (int i = 0; i < n; i++)
    {
        maxNo=max(maxNo,arr[i]);
        minNo=min(minNo,arr[i]);
    }
    cout<<maxNo<<" "<<minNo;
    
    
    return 0;
}