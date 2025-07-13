'''
Question:
Use the Lehmann algorithm to check whether the given number P is prime or not?
'''

import random

def lehmann_primality_test(P, k=5):
    if P <= 2:
        return P == 2

    if P % 2 == 0:
        return False  

    for _ in range(k):
        a = random.randint(2, P - 2)
        exp = (P - 1) // 2
        result = pow(a, exp, P)

        if result != 1 and result != P - 1:
            return False  

    return True  

P = int(input("Enter a number to test: "))
if lehmann_primality_test(P, k=10):
    print(f"{P} is probably prime.")
else:
    print(f"{P} is composite.")
