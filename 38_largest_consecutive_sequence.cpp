#include<bits/stdc++.h>
// #include<vector>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
    {
      sort(arr,arr+N);
      int count=0;
      int mx=0;
      vector<int>v;
      v.push_back(arr[0]);
      for(int i=1;i<N;i++)
      {
          if(arr[i]!=arr[i-1])
          {
              v.push_back(arr[i]);
          }
      }
      
      for(int i=0;i<v.size();i++)
      {
          if(i>0 && v[i]==v[i-1]+1)
          {
              count++;
          }
          
          else
          {
              count=1;
          }
          
          mx=max(mx,count);
      }
      
      return mx;
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

    cout<<findLongestConseqSubseq( arr, n)<<endl;

    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i];
    // }
    return 0;
}