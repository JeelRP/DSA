// Max Sum SubArray Using Sliding Window

#include <iostream>
using namespace std;

int maxSumSubArray(int arr[], int n, int k, int x)
{
    int ans = 0;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    if (sum < x)
    {
        ans = sum;
    }

    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i];
        sum = sum - arr[i - k];
        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }

    return ans;
}
int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};

    cout << maxSumSubArray(arr, 6, 3, 20) << endl;

    return 0;
}