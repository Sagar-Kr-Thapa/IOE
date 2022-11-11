from math import fabs
import sys

n=int(input())
fn=input()
sn=input()

l = max(len(fn), len(sn))

if l>n:
    print("Length of input greater than ", n )
    sys.exit(-1)

fn=fn.zfill(n)
sn=sn.zfill(n)

def flip(lst):
    l=len(lst)
    for i in range(l):
        if lst[i]=='0': lst[i]='1'
        else: lst[i]='0'

def add(a,b):
    a=a[::-1]
    b=b[::-1]

    result=""
    carry=0
    for i in range(n):
        s=int(a[i])^int(b[i])^carry
        carry=(int(a[i]) & int(b[i])) | ((int(a[i])^int(b[i]))&carry)
        result = str(s) + result
    return result

def two_scomplement(a):
    a = list(a)
    flip(a)
    a = ''.join(a)
    one="1"
    one=one.zfill(n)
    a=add(a, one)
    return a

def sub( a, b ):
    b = two_scomplement(b)
    return add(a,b)

diff = sub(fn,sn)

print("Difference: ", diff )


