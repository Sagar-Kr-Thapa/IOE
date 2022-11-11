import sys
multiplicand=input()
multiplier=input()

n=len(multiplicand)

def twos_complement(a):
    temp=""
    for i in range(n):
        if a[i]=='0': t='1'
        else : t='0'
        temp += t
    a=temp
    one="1"
    one=one.zfill(n)
    a=add(a, one)
    return a

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

def sub(a,b):
    b=twos_complement(b)
    result=add(a,b)
    return result

def right_shift(A,Q):
    new=A+Q
    res=new[0]
    for i in range(1,len(new)):
        res+=new[i-1]
    return (res[:n],res[n:len(new)],new[len(new)-1])

def booth_algorithm(m1,m2):
    #initially
    A=""
    A=A.zfill(n)
    M=m1[:]
    Q=m2[:]
    Q1='0'

    #repeat
    for i in range(n):
        if( Q[n-1]=='0' and Q1=='1'):
            N=M[:] #copying M to N
            A=add(A,N)
        elif( Q[n-1]=='1' and Q1=='0'):
            N=twos_complement(M)
            A=add(A,N)
        A,Q,Q1=right_shift(A,Q)
    return (A,Q)

product=booth_algorithm(multiplicand,multiplier)
print(product)

