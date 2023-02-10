// print all number in increasing order till n

#include<iostream>
using namespace std;

void inc(int n)
{
    if (n==1)
    {
        cout<<"1"<<endl;
        return ;
    }
    inc(n-1);
    cout<<n<<endl;
}
int main()
{
    int n;
    cout<<"Enter value of n==>";
    cin>>n;

    inc(n);
    return 0;
}