import sys
n=int(input())

a=input()
b=input()

l = max(len(a), len(b))

if l>n:
    print("Length of input greater than ", n )
    sys.exit(-1)

a=a.zfill(n)
b=b.zfill(n)

def add(a,b):
    a=a[::-1]
    b=b[::-1]

    result=""
    carry=0
    for i in range(n):
        s=int(a[i])^int(b[i])^carry
        carry=(int(a[i]) & int(b[i])) | ((int(a[i])^int(b[i]))&carry)
        result = str(s) + result
    return (result,str(carry))

def rightShift(carry,a,b):
    newlist=[]
    newlist.append(carry)
    newlist += a[:]
    newlist += b[:]
    templist=newlist[:]
    for i in range(1,len(newlist)):
        templist[i]=newlist[i-1]
    a=templist[1:len(a)+1]
    b=templist[len(a)+1:]
    carry='0'
    return(carry,a,b)

def mul(a,b):
    carry='0'
    acc = ""
    acc = acc.zfill(n)
    for i in range(n-1,-1,-1):
        if( b[n-1]=='0' ):
            carry,acc,b=rightShift(carry,acc,b)
        else:
            acc,carry=add(acc,a)
            carry,acc,b=rightShift(carry,acc,b)
    return (carry,acc,b)

carry,acc,b=mul(a,b)
print(carry+''.join(acc)+''.join(b))

