#include <iostream>
#include <vector>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> v;
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            v.push_back(A[i]);
            i++;
            j++;
            k++;
        }

        if (A[i] < B[j])
        {
            i++;
        }

        if (B[j] < C[k])
        {
            j++;
        }

        else
        {
            k++;
        }
    }

    return v;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int A[n1], B[n2], C[n3];
    
    for (int i = 0; i < n1; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < n3; i++)
    {
        cin >> C[i];
    }

    vector<int> ans;

    ans = commonElements(A, B, C, n1, n2, n3);

    if (ans.size() == 0)
    {
        return -1;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i];
    // }
    return 0;
}