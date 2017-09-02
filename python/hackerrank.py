import math
import numpy as np
def factorial():
    i = int(input("enter a number:"))
    if i == 0:
        return 1
    else:
        x = 1
        for j in range(1, i+1):
            x = x*j
        return x
def dictionary():
    d = dict()
    i = int(input("enter a number:"))
    for n in range(i+1):
        d[n] = n*n
    print(d)
def tupleandlist():
    l = []
    t = ()
    values = input("enter comma separated values:")
    l = values.split(",")
    t = tuple(l)
    print(l)
    print(t)
class stringclass(object):
    def __init__(self):
        self.string = ""
    def getstring(self):
        self.string = input("enter a string:")
    def putstring(self):
        print(self.string.upper())

"""class dog:
    def __init__(self, ):
        pass
    breed = input("enter the breed of the dog:")
    color = input("enter the color of the dog:")
    weight = input("enter the weight:")
    name="kittu"
object1 = dog()
print("breed="+object1.breed+" \ncolor="+object1.color+" \nweight="+object1.weight+" \n
name="+object1.name)"""
def formula1():
    """Q = Square root of [(2 * C * D)/H] c=50 h=30"""
    values = input("input values separated with ','")
    li = []
    li = (values.split(','))
    for i in li:
        q = math.sqrt((2*50*int(i))/30)
        print(q)
def d2array():
    value1 = input("enter comma seperated number:")
    li = []
    li = value1.split(',')
    li[0] = (int(li[0]))
    li[1] = (int(li[1]))
    x = li[0]*li[1]
    y = np.arange(x).reshape(li[0], li[1])
    for i in range(0, li[0]):
        print(y[0]*i)

def seperate_and_sort():
    string1 = input("enter a sentence:")
    str1 = []
    str1 = string1.split()
    str1.sort()
    print(str1)
def captalize1():
    string1=input("enter a string:")
    string3=string1.upper()
    print(string3)

def sort_and_simplify():
    string1=input("enter a string:")
    string2=string1.split()
    set1=set()
    for x in string2:
        set1.add(x)
    li = list(set1)
    li.sort()
    print(li)

def binary_to_int():
    string1 = input("enter a string:")
    binary=list(string1.split(','))
    p = []
    li = []
    for x in binary:
        p.append(int(x,2))
    for i in p:
        if i%5==0:
            li.append(i)
    print(li)
def length_of_string():
    string1=input("enter a string:")
    count = {"digits":0,"alpha":0}
    for c in string1:
        if c.isdigit():
            count["digits"]+=1
        elif c.isalpha():
            count["alpha"]+=1
        else:
            pass
    print(count)
def a_aa_aaa():
    a=int(input("enter a number:"))
    aa=(a*10)+9
    aaa=(a*100)+(a*10)+9
    aaaa=(a*1000)+(a*100)+(a*10)+9
    x=a+aa+aaa+aaaa
    print(x)

def filter1():
    x=input("enter numbers seperated by commas:")
    a=list(x.split(','))
    a=[int(i) for i in a]
    j=list(filter(lambda item: item%2!=0,a))
    j=[i**2 for i in j]
    print(j)

def cardtrans():
    d={'D':[], 'W':[]}
    x[2]
    y=list()
    for i in range(2):
        x[0]=input("enter D 'amount' or M 'amount'")
        y=[x for x in x[0].split()]

def evenStrings():
    string1=input("enter a string:")
    for i in range(0, len(string1)+1, 2):
           print(string1[i], end='')

evenStrings()
