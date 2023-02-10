#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"enter matrix"<<endl;
    cin>>n;
    
    int arr[n][n];
    
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"rotated matrix"<<endl;
    
    for(int i=0;i<n;i++)
    {   
        for(int j=i;j<n;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    
    int j=0;
    for (int i = 0; i < n; i++)
    {
        int p=arr[i][j];
        arr[i][j]=arr[i][j+2];
        arr[i][j+2]=p;
    }
    
    
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}