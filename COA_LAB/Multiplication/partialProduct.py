#Q -> Multiplier
#B -> Multiplicand
def rjust_number(n1, n2):
    l1 = len(n1)
    l2 = len(n2)
    if l1 > l2:
        n2 = n2 .rjust(l1, '0')
    elif l2 > l1 :
        n1 = n1.rjust(l2, '0')

    return (n1, n2)

def add(A, B, N):
    A = A[::-1]
    B = B[::-1]

    res = ""
    Carry = 0 
    for i in range(N):
        S = int(A[i]) ^ int(B[i]) ^ Carry 
        Carry = ( int(A[i]) & int(B[i]) ) | ( Carry & ( int(A[i]) ^ int(B[i] ) ) )
        res = str(S) + res

    res = str(Carry) + res 

    return res 


def partialProduct(Q, B, N):
    A = "0"  
    

    for i in range(N):
        if(Q[-1] =='1'):
            A, B = rjust_number(A, B);
            A = add(A, B, len(B))

        Q = A[-1] + Q[:(N-1)]
        A = '0' + A[: (len(A)-1) ]

    return (A+Q)

def main():
    result = partialProduct("10", "10", 2)
    print(result)


if __name__ == '__main__':
    main()





