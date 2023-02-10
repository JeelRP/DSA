#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter vaue of n==>";
    cin >> n;
    int target;
    cout << "Enter value of target==>";
    cin >> target;
    
    vector<int> arr;
    cout << "Enter Elements of array==>";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool found = false;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int low = i + 1;
        int high = n - 1;

        while (low < high)
        {
            if (arr[low] + arr[high] + arr[i] == target)
            {
                found = true;
                
            }

            if (arr[low] + arr[high] + arr[i] > target)
            {
                high--;
            }

            if (arr[low] + arr[high] + arr[i] < target)
            {
                low++;
            }
        }
    }

    if (found)
    {
        cout << "true";
    }
    else
    {
        cout<<false;
    }
    return 0;
}