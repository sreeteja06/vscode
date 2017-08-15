x=int(input("enter an integer:"))
y=0
if x>1:
    for i in range(2,(x)):
        if x%i==0:
            print("not a prime number")
            break
    else:
        print("prime number")