import sys
n=int(input("Enter no. of bits: "))
dividend=input()
divisor=input()

l = max(len(dividend), len(divisor))

if l>(n): 
    print("ERROR!!! ","Length of input greater than ", n)
    sys.exit(1)

#adjusting numbers 
dividend=dividend.zfill(n)
divisor=divisor.zfill(n)

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

def left_shift(A,Q):
    new=A+Q
    res=""
    for i in range(1,len(new)):
        res+=new[i]
    return (res[:n],res[n:])

def restoring(d1,d2):
    A=""
    A=A.zfill(n)
    Q=d1[:]
    M=d2[:]
    
    for i in range(n):
        #left-shift
        A,Q=left_shift(A,Q)
        N=twos_complement(M)
        A=add(A,N)
        if A[0]=='1':
            Q+="0"
            restore=True
        else:
            Q+="1"
            restore=False
        #Restore
        if restore: A=add(A,d2)
    return (Q,A)

quo,rem=restoring(dividend,divisor)
print(quo," and ",rem)

