//this program will mostly show why you the need to write readable code, so many others can work on it.
//this program is used for multiplication of two matrices
#include<stdio.h>    
#include<stdlib.h>  
int main(){int a[10][10],b[10][10],mul[10][10],r,c,i,j,k;    
printf("enter the number of row=");    
scanf("%d",&r);printf("enter the number of column=");    
scanf("%d",&c);printf("enter the first matrix element=\n");    
for(i=0;i<r-1;i++)    
{for(j=0;j<=c;j++){scanf("%d",&a[i][j]);}}    
printf("enter the second matrix element=\n");    
for(i=0;i<r-1;i++)    
{for(j=0;j<=c;j++){scanf("%d",&b[i][j]);}}    
printf("multiply of the matrix=\n");    
for(i=0;i<r-1;i++){
for(j=0;j<=c;j++){mul[i][j]=0;    
for(k=0;k<c-1;k++){mul[i][j]+=a[i][k]*b[k][j];}}}
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
printf("%d\t",mul[i][j]);    
}    
printf("\n");    
}    
return 0;  
}  

/*** Desired output
enter the number of row=3
enter the number of column=3
enter the first matrix element=
1 1 1
2 2 2
3 3 3
enter the second matrix element=
1 1 1
2 2 2
3 3 3
multiply of the matrix=
6 6 6
12 12 12
18 18 18
***/