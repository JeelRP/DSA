#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void dlt()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[leftIndex] > arr[i])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }

            if (rightIndex <= size && arr[rightIndex] > arr[i])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }

            else
            {
                return;
            }
            i++;
        }
    }
};
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

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(25);
    h.dlt();
    h.print();

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
    return 0;
}