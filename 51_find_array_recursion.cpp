// Find first and last occurence of a number in an array

#include<iostream>
using namespace std;
int firstocc(int arr[],int n, int i, int key)
{
    if (i==n)
    {
        return -1;
    }
    
    if (arr[i]==key)
    {
        return i;
    }
    return firstocc(arr,n,i+1,key);
    
}

int lastocc(int arr[],int n, int i, int key)
{
    
    if (i==n)
    {
        return -1;
    }
    
    int restArray=lastocc(arr,n,i+1,key);

    if (restArray!=-1)
    {
        return restArray;
    }
    
    if (arr[i]==key)
    {
        return i;
    }
    return -1; 
}
int main()
{
    int n,j=0,key;
    cout<<"Enter limit==>";
    cin>>n;
    cout<<"Enter key==>";
    cin>>key;
    int arr[n];
    cout<<"Enter elements of array==>";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<firstocc(arr,n,j,key)<<endl;
    cout<<lastocc(arr,n,j,key)<<endl;
    
    return 0;
}