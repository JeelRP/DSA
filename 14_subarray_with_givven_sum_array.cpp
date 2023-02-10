/* DOUBT WHILE TRACING AND CODE DOES NOT WORK*/

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

    int i=0,j=0,st=-1,et=-1,sum=0;
    int s;
    cin>>s;

    while (j<n && sum + arr[j]<=s)
    {
        sum+=arr[j];
        j++;
    }
    
    if (sum==s)
    {
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    
    while (j<n)
    {
        sum+=arr[j];
        while (sum>s)
        {
            i++;
        }
        if (sum==s)
        {
            st=i+1;
            et=j+1;
            break;
        }
        j++;

    }
    

    cout<<st<<" "<<et<<endl;
    return 0;
}