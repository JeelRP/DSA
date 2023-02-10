#include<iostream>
using namespace std;

int Factorial(int n)
{
    if (n==1)
    {
        return 1;
    }

    int prevFact=Factorial(n-1);
    return n*prevFact;
    
}
int main()
{
    int n;
    cout<<"Enter the value of n==>";
    cin>>n;

    cout<<Factorial(n);
    return 0;
}