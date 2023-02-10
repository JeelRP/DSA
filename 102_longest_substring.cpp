#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter string==>";
    cin>>s;
    vector<int>dict(256,-1);
    int maxLen=0;
    int start=-1;
    for (int i = 0; i < s.size(); i++)
    {
        if (dict[s[i]]>start)
        {
            start=dict[s[i]];
        }
        dict[s[i]]=i;
        maxLen=max(maxLen,i-start);   
    }
    cout<<maxLen;
    
    return 0;
}