//The below code shows how to calculate how many times same number is present in an array
#include<stdio.h>
int main(){
int i,j,count=0;
int array[10];
printf("****enter 10 elements 1-10 repetive or non repetive****\n");
for(int i=0;i<10;i++)
scanf("%d",&array[i]);
printf("****Enter a element to check how many it is repeted****\n");
int op;
scanf("%d",&op);
for(j=0;j<10;j++){
if(op==array[j]){count++;}
}printf("\nEntered number %d is repeted %d",op,count);
}
