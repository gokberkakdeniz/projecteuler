import os

f = open("Q22.txt", mode='r')
names = sorted(f.read().replace('"', '').split(","))
f.close()

print(sum([(i+1) * sum(ord(c)-64 for c in n) for i, n in enumerate(names)], 0))
