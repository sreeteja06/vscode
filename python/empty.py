#!/bin/python3
n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]
positive = 0
negative = 0
zeros = 0
for i in range(n):
    if(arr[i]>0):
        positive+=1
    if(arr[i]<0):
        negative+=1
    if(arr[i]==0):
        zeros+=1
print(float(positive/n))
print(float(negative/n))
print(float(zeros/n))
