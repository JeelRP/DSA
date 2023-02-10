#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter limit==> ";
    cin >> n;

    int arr[n];
    cout << "Enter elements==> ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = 0;
    int k;
    cout << "Enter the value of k==> ";
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << max << endl;
    return 0;
}