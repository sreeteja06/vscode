//control statements
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
printf("Mirror Time:\n");
if(h>=1&&h<=12&&m>=1)
{
h=12-h-1;
printf("%d",h);
}
else if(h>=1&&h<=12&&m==0)
{
h=12-h;
printf("%d",h);
}
if(m>=1&&m<=60)
{
m=60-m;
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
Mirror Time:
5:30:17
*/