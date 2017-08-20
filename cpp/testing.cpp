#include <iostream>
using namespace std;
class students{
    public:
        int marks;
    class stud{
        int physics;
    }
};
int main() 
{
    int x=10;
    int &y = x;
    x=11;
    y=13;
    students s1;
    s1.marks=10;
    s1.physics=11;
    s1.stud stud1;
    cout<<"y="<<y<<" x="<<x<<" s1 marks="<<s1.marks;
}