#include<bits/stdc++.h>
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

//    const int N=1e6+2;
    int count[100];

    for (int i = 0; i < 100; i++)
    {
        count[i]=-1;
    }
    

    int minidx=INT_MAX;
    for (int i = 0; i < n; i++)
    {   
        if (count[arr[i]]!=-1)
        {
            minidx=min(minidx,count[arr[i]]);
            
        }
        else
        {
        count[arr[i]]=i;
        }
    }

    if (minidx==INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<minidx+1<<endl;
    }
    
    return 0;
}