#include<iostream>
using namespace std;
class hello{
public:
    int a;
    hello()
    {
        cout << "hello";
        a = 10;
    }
};

class world: public hello{
public:
    int b;
    world()
    {
        b= 10;
    }
    void printab()
    {
        cout << a << b;
    }
};
int main()
{
    world w;
    w.printab();
}