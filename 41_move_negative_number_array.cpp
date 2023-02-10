#include <iostream>
using namespace std;
  
void swap(int arr[], int l, int r)
{
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

void negative(int arr[], int n)
{
    int i = -1;
    int j = 0;

    int pivot = 0;

    while (j < n)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
        j++;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    negative(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}