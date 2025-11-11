#include<iostream>
using namespace std;

int fibonnaci_non_recursive(int n)
{
    if (n==0) return 0;
    if (n==1) return 1; 

    int prev2=0;
    int prev1=1;
    int curr;

    for(int i=2;i<=n;i++)
    {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}

int fibonnacci_recursive(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonnacci_recursive(n-1) + fibonnacci_recursive(n-2);
}

int main()
{
    int n;
    cout<<"enter the no :";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<fibonnaci_non_recursive(i);
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<fibonnacci_recursive(i);
    }
    return 0;
}