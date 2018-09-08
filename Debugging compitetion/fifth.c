/*
Description
The above code gives the mirror time of a given time.
for example if the time given is 07:40:20
Then the mirror time is calculated by subtracting the given time fro  11:60:60

that is 11:60:60
      - 07:40:20
       ----------
            04 : 20 : 40*/
#include<stdio.h>
void main()
{
int h,m,s;
printf("Enter Hour: ");
scanf("%d",&h);
printf("Enter Min:");
scanf("%d",&m);
printf("Enter Second:");
scanf("%d",&s);
if(h>12||m>60||m>60)
{
printf("\nEnter correct time:\n");
}
printf("correct Time:\n");
if(h>1&&h<12&&m>1)
{
h=12-h-1;
printf("%d",h);
}
else if(h>1)
{
h=12-h;
printf("%d",h);
}
if(m>=1&&m<=60)
{
m=m-60;
printf(":%d",m);
}
else if(m==0)
printf(":%d",m) ;
if(s>=1&&s<=60)
{
s=60-s;
printf(":%d",s);
}
else if(s==0)
printf(":%d",s) ;
}
/* 
:::input:::
Enter Hour: 6
Enter Min:30
Enter Second:43
:::output:::
correct Time:
5:30:17
*/