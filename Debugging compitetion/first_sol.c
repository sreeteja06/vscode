#include<stdio.h>
 int main()
{
    int n,i,fact,j;
    printf("Enter the Number\n");
    scanf("%d",&n);
    printf("Prime Numbers are: \n");
    for(i=1; i<=n; i++)
    {
        fact=0;
        for(j=1; j<=n; j++)
        {
            if(i%j==0)
                fact++;
        }
        if(fact==2)
            printf("%d\n" ,i);
    }
return 0;
}