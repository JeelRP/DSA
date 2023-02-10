#include<bits/stdc++.h>
using namespace std;

int feasible(int boards[], int n, int limits)
{
    int sum=0, painters=1;
    for (int i = 0; i < n; i++)
    {
        sum+=boards[i];
        if(sum > limits)
        {
            sum=boards[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartiton(int boards[], int n, int m)
{
    int k=0, totalLegth=0;
    for (int i = 0; i < n; i++)
    {
        k=max(k, boards[i]);
        totalLegth+=boards[i];
    }   
    int low=k, high=totalLegth;
    while (low<high)
    {
        int mid=(low+high)/2;
        int painters=feasible(boards,n,mid);
        if(painters<=m)
        {
            high=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}

int main()
{
    int boards[]={10,20,30,40};
    int n=4;
    int m=2;
    cout<<paintersPartiton(boards,n,m)<<endl;
    return 0;
}