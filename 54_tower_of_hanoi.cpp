// tower of hanoi (IMP)

#include<iostream>
using namespace std;

void towerofHanoi(int n,char src,char dest,char helper)
{

    if (n==0)
    {
        return; //base case
    }
    
    towerofHanoi(n-1,src,helper,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerofHanoi(n-1,helper,dest,src);

}
int main()
{
    int n;
    cout<<"enetr value of n==>";
    cin>>n;
    towerofHanoi(n,'A','B','C');
    
    return 0;
}