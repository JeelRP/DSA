#include <iostream>
using namespace std;

void heaptify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = 2 * i;
    int rightchild = 2 * i + 1;

    if (leftchild <= n && arr[leftchild] > arr[largest])
    {
        largest = leftchild;
    }

    if (rightchild <= n && arr[rightchild] > arr[largest])
    {
        largest = rightchild;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heaptify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int t = n;

    while (t > 1)
    {
        swap(arr[t], arr[1]);
        t--;
        heaptify(arr, t, 1);
    }
} 
int main()
{

    int arr[7] = {-1, 54, 53, 55, 52, 56, 80};
    int n = 6;
    for (int i = n / 2; i > 0; i--)
    {
        heaptify(arr, n, i);
    }
    cout << "printing the array now" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "After sorting" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}