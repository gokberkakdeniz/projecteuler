#!/usr/bin/env python
def ESieve(bound):
    numberlist = [i for i in range(2, bound)]
    for i in range(bound-2):
        if numberlist[i] != 0:
            for j in range(i+numberlist[i], bound-2, numberlist[i]):
                numberlist[j]=0
    return [p for p in numberlist if p != 0]

def permutation(text):
    if len(text) in [0,1]:
        yield text
    else:
        container = set()
        for i in range(len(text)):
            ith_letter = text[i]
            text_without_ith_letter = text[:i] + text[i+1:]
            for p in permutation(text_without_ith_letter):
                if not ith_letter+p in container:
                    container.add(ith_letter+p)
                    yield ith_letter+p

def rotation(text, contains_itself = False):
    text_list = list(str(text))
    for i in range(0 if contains_itself else 1, len(text_list)):
        yield "".join(text_list[i:]+text_list[:i])


# real    12m4.197s
# user    12m1.366s
# sys     0m0.175s
primes = ESieve(1000000)
circular_primes = {prime for prime in primes if all([(True if int(rotated) in primes else False) for rotated in rotation(prime)])}
print(sorted(circular_primes))
print(len(circular_primes))
