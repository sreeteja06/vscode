#include<iostream>
using namespace std;
int prefixsum(int (&Array)[100],int N);
int suffixsum(int (&Array)[100], int N);
int main ()
{
    int Array[100], temp, i, size_of_array;
    cout<<"enter the size of array:";
    cin>>size_of_array;
    for (i=0;i<size_of_array)
    {
        cin>>Array[i];
    }
    temp = prefixsum(Array, size_of_array);
}