// CODE DOEST OT WORK

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

   
    bool idx[100];
    for (int i = 0; i < 100; i++)
    {
        idx[i]=0;
    }
    

    for (int i = 0; i < 100; i++)
    {
        if (arr[i]>=0)
        {
            idx[arr[i]]=1;
        }      
            
    }

    int ans=-1;

    for (int i = 0; i < 100; i++)
    {
        if (idx[i]==0)
        {
            ans=i;
            break;
        }   
    }

    cout<<ans<<endl;
    return 0;
}