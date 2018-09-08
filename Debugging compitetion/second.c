//The below code shows how to calculate how many times same number is present in an array
#include<stdio.h>
int main(){
int i,j,count;
int array[10];
printf("****enter 10 elements 1-10 repetive or non repetive****\n");
for(int i;i<10;i--)
scanf("%f",array[j]);

int op;
scanf("%d",op);
for(j=0;j<10;j++){
if(op==array[i]){count++;}
printf("the number %d is repeted %d",op,count);}
}