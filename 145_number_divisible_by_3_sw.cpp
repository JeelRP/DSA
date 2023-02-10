// Number is divisible by 3 using sliding window

//solution 1(My Self)
#include<iostream>
using namespace std;

void divisibleBy3(int arr[], int n, int k)
{
    
    int sum = 0, start=0,end=0;
    bool found=false;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
        end=i;
    }
    
    if (sum%3==0)
    {
        found=true;
    }
    
    

    for (int i = k; i < n; i++)
    {
        if (found)
        {
            break;
        }
        start++;
        end=i;
        sum = sum + arr[i];
        sum = sum - arr[i - k];
        if (sum%3==0)
        {
            found=true;
        }
    }

    if (found)
    {
        for (int i = start; i <= end; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    }
    else{
        cout<<"Sub Array not found"<<endl;
    }
    
    
}
int main()
{
    int arr[] = {84,23,45,12,56,82};

    divisibleBy3(arr,6,3);
    return 0;
}

//solution 2(Watch Video)