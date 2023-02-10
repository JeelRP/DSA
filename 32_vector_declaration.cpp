#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    vector<int>v;
    v.push_back(2);
    v.push_back(4);

    // for (int i = 0; i < v.size(); i++)    //method 1
    // {
    //     cout<<v[i]<<endl;
    // }
    // for (auto element : v)               //method 2
    // {
    //     cout<<element<<endl;
    // }



    // vector<int>::iterator it;

    // for (it = v.begin(); it != v.end(); it++)  //method 3
    // {
    //     cout<<*it<<" "<<endl;
    // }
    for (int i = 0; i < v.size(); i++)    //method 1
    {
        cout<<v[i]<<endl;
    }
    
    sort(v.rbegin(),v.rend());
    for (int i = 0; i < v.size(); i++)    //method 1
    {
        cout<<v[i]<<endl;
    }

    return 0;
}