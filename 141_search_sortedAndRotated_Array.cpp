#include <iostream>
using namespace std;

int searchInRotatedArray(int arr[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[left] <= arr[mid])
    {
        if (arr[left] < key && key < arr[mid])
        {
            return searchInRotatedArray(arr, key, left, mid);
        }
        return searchInRotatedArray(arr, key, mid + 1, right);
    }
    
        if (arr[mid] < key && key < arr[right])
        {
            return searchInRotatedArray(arr, key, mid + 1, right);
        }
        return searchInRotatedArray(arr, key, left, mid);
    
}

int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int n = 8;
    int key = 8;
    cout << "Index Is: " << searchInRotatedArray(arr, key, 0, n - 1) << endl;
    return 0;
}