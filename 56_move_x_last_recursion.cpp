// Move all x to the end of the string

#include<iostream>
using namespace std;

string MoveXlast(string s)
{
    if (s.length()==0)
    {
        return "";
    }
    char ch=s[0];

    string ros=MoveXlast(s.substr(1));
    if (s[0]!='x')
    {
        return (ch+ros);
    }
    return (ros+ch);
}
int main()
{
    string s;
    cout<<"Enter the string==>";
    cin>>s;

    cout<<MoveXlast(s);   
    return 0;
}