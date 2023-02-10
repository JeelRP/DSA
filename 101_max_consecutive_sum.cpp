#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter vaue of n==>";
    cin >> n;
    int k;
    cout << "Enter value of k==>";
    cin >> k;
    
    vector<int> arr;
    cout << "Enter Elements of array==>";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i=0,zc=0,ans=0;

    for (int j = 0; j < n; j++)
    {
        if (arr[j]==0)
        {
            zc++;
        }
        
        while (zc>k)
        {
            if(arr[i]==0)
            {
                zc--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
    }

    cout<<ans;
    
    return 0;
}