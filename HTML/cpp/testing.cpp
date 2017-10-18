#include<iostream>
#include <cmath>
using namespace std;
int Mul3(int x)
{
    if(x%3==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Mul5(int x)
{
    if(x%5==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int scan_no, sum=0, i;
    cin>>scan_no;
    for(i=0;sum<scan_no;i++)
    {
        if(Mul3(i)==1)
        {
           sum+=i;
           continue;
        }
        if(Mul5(i)==1)
        {
            sum+=i;
        }
    }
    
}