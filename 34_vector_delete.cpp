#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>v1;

    v1.push_back(3);
    v1.push_back(90);
    v1.push_back(40);
    v1.push_back(56);
    v1.push_back(76);
    v1.push_back(2);

   for(auto element:v1)
    {
        cout<<element<<" ";
    }
    cout<<endl;

    v1.pop_back();
    v1.pop_back();
    

    for(auto element:v1)
    {
        cout<<element<<" ";
    }
    cout<<endl;
    return 0;
}