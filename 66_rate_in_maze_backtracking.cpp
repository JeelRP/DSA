#include<iostream>
using namespace std;

bool isSafe(int arr[],int x,int y,int n)
{
    if (x<n || y<n || arr[x][y]==1)
    {
        return true;
    }
    return false;
}

bool RatInMaze(int arr[],int x,int y,int n,int solution)
{
    if (x==n-1 && y==n-1)
    {
        solution[x][y]==1;
        return true;
    }
    
    if (isSafe(arr,x,y,n))
    {
        solution[x][y]=1;
        if (RatInMaze(arr,x+1,y,n,solution))
        {
            return true;
        }
        if (RatInMaze(arr,x,y+1,n,solution))
        {
            return true;
        }
        solution[x][y]=0;
        return false;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    
    int arr[n][n];
    int solution[n][n]={0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }   
    }
    if(RatInMaze(arr,0,0,n,solution))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<solution[i][j]<<" ";
            }cout<<endl;
        } 
    }
    
    return 0;
}