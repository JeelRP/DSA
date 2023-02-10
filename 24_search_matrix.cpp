#include<iostream>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    int arr[n][m];
    for (int j = 0; j < n; j++)
    {
        for(int i=0;i<m;i++)
        {
            cin>>arr[j][i];
        }
    }
    
    int r=0,c=m-1;
    bool found=false;
    while (r<n && c>=0)
    {
        if (arr[r][c]==k)
        {
            found=true;
        }
        if (arr[r][c]>k)
        {
            c--;
        }
        else
            r++;
    }
    

   if (found)
   {
       cout<<"Element found";
   }
   else
    cout<<"Element not found";
    
    return 0;
}