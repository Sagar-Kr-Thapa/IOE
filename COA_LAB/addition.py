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

# ans=['0' for _ in range(n)]
# a=list(a)
# b=list(b)

# def add():
#     carry=0
#     for i in range(n-1,-1,-1):
#         if( (a[i]=='0' and b[i]=='1') or (b[i]=='0' and a[i]=='1') ):
#             if carry:
#                 ans[i]='0'
#             else:
#                 ans[i]='1'
#         elif ( a[i]=='0' and b[i]=='0' ):
#             if carry:
#                 ans[i]='1'
#                 carry=0
#             else:
#                 ans[i]='0'
#         else:
#             if carry:
#                 ans[i]='1'
#             else:
#                 ans[i]='0'
#                 carry=1
#     return carry
def add(a,b):
    a=a[::-1]
    b=b[::-1]

    result=""
    carry=0
    for i in range(n):
        s=int(a[i])^int(b[i])^carry
        carry=(int(a[i]) & int(b[i])) | ((int(a[i])^int(b[i]))&carry)
        result = str(s) + result
    return (result,carry)
ans,carry=add(a,b)
print( "Sum:",ans ," and " ,"Carry:", carry )

