#include<iostream>
using namespace std;

int Sum(int n)
{   
    if(n==0)
    return 0;

    int prevSum=Sum(n-1);
    return n+prevSum;
}
int main()
{
    int n;
    cout<<"Enter value of n==>";
    cin>>n;

    cout<<Sum(n);
    return 0;
} 