#include <iostream>
using namespace std;
inline int add(int x,int y);
class students{
    public:
        int marks;
};
int main() 
{
    int x=10;
    int y=13;
    int r=add(x,y);
    cout<<r<<endl;
    students s1;
    s1.marks=10;
    cout<<"y="<<y<<" x="<<x<<" s1 marks="<<s1.marks;
}
inline int add(int x,int y)
{
    return x+y;
}