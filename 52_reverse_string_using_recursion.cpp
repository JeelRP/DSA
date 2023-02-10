// reverse string using string

#include<iostream>
using namespace std;

void reverse(string s)
{
    if (s.length()==0)
    {
        return ;
    }

    string ros=s.substr(1);

    reverse(ros);
    cout<<s[0];
    
}
int main()
{
    string s;
    cout<<"Enter the string==>";
    cin>>s;

    reverse(s);
    return 0;
}