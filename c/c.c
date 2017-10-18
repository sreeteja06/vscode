#include <stdlib.h>
#include <windows.h>
int x=0, y=0;
void gotoXY(int argX, int argY);
int main()
{
    while(1)
    {
        if(getAsyncKeyState(VK_UP))
            gotoXY(x, y+1);
        if(getAsyncKeyState(VK_DOWN))
            gotoXY(x, y-1);
        if(getAsyncKeyState(VK_LEFT))
            gotoXY(x-1, y);
        if(getAsyncKetState(VK_RIGHT))
            gotoXY(x+1, y);
    }
}

void gotoXY(int argX, int argY){
    x=argX;
    y=argY;
}