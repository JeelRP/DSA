#include <bits/stdc++.h>
using namespace std;

void heaptify(int arr[], int n, int i)
{
    int smallest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < n && arr[leftchild] < arr[smallest])
    {
        smallest = leftchild;
    }

    if (rightchild < n && arr[rightchild] < arr[smallest])
    {
        smallest = rightchild;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heaptify(arr, n, smallest);
    }
}

int main()
{
    int arr[7] = {-1, 54, 53, 55, 52, 56, 80};
    int n = 6;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heaptify(arr, n, i);
    }
    cout << "printing the array now" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}