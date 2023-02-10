#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>v1;
    vector <int> v2(3,50);

    v1.push_back(3);
    v1.push_back(90);

    swap(v1,v2);

    for(auto element:v1)
    {
        cout<<element<<" ";
    }
    cout<<endl;

     for(auto element:v2)
    {
        cout<<element<<" ";
    }
    cout<<endl;
    return 0;
}