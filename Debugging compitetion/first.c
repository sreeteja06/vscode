#include<stdio.h>
void int main()
{
    int n,i,fact,j;
    printf("Enter the Number\n");
    scanf("%d",n); 
    printf("Prime Numbers are: \n");
    for(i=1; i<=n; i++)
    {
        
        for(j=1; j<=n;)        {
            if(i%j==0)
                {fact++;}
                 j++;
        }
        if(fact==1)
            printf("%d\n" ,i);
   fact=0;
    }
   return 0;
}