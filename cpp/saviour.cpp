#include<iostream>
using namespace std;
class sample
{
public: 
    void sam()
    {
        cout<<"hello";
    }
    friend main();
};
class base1:public sample
{

};
class base2:public sample
{

};
class base3:public base1, public base2
{

};
void help(int x, int y, ...)
{
    cout << "...";
}
int main()
{
    float x = 3.3f;
    x = int(x);
    cout << x;
    base3 object;
    object.base2::sam();
    help(10,20,"hello");
}