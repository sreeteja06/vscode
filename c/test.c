#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    int i = rand()%20;
    int guess=0,count = 1;
    printf("Guess the number between 1 to 20:");
    scanf("%d",&guess);
    while((guess!=i)&&(count<5))
    {
        if(guess<i)
        {
            printf("your guess is low.Try again:");
            scanf("%d",&guess);
            count++;
            continue;
        }
        else if(guess>i)
        {
            printf("your guess is high.Try again:");
            scanf("%d",&guess);
            count++;
            continue;
        }
    }
    if(count>=5)
    {
        printf("sorry. the number was %d\nbetter luck next time.",i);
    }
    else if(guess==i)
    {
        printf("Congradulations. you did it.");
    }
}