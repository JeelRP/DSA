// #include<iostream>

// using namespace std;

// int duplicate(int arr[], int n)
// {   
//     // const int N=1e2+5;
//     int count[100]={-1};
//     for (int i = 0; i < n; i++)
//     {
//         if (count[arr[i]]==-1)
//         {
//             count[arr[i]]=1;
//         }
//         if (count[arr[i]]==1)
//         {
//             return arr[i];
//         }
        
//     }
//     return -1;
// }
// int main()
// {
//     int n;
//     cin>>n;

//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }

//     cout<<duplicate(arr,n);

//     // for(int i=0;i<n;i++)
//     // {
//     //     cout<<arr[i];
//     // }
//     return 0;
// }


#include<bits/stdc++.h>
#include<vector>
using namespace std;

int duplicate(vector<int>& num)
{   
    int n=num.size();
    int count[n];
    for (int i = 0; i < n; i++)
    {
        count[i]=0;
    }
    sort(num.begin(),num.end());

    int c=0;
    for (int i = 0; i < n-1; i++)
    {
        if (num[i]==num[i+1])
        {
            c=num[i];
            break;
        }
        
    }
    return c;
}
int main()
{   
    vector<int>num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(4);
    num.push_back(3);
    num.push_back(5);
    num.push_back(6);

    cout<<duplicate(num);
    return 0;
}