import sys
import os

t=int(input())
while t:
    c=0
    a,b=[int(x) for x in input().split()]
    for i in range(b,a+1,b):
        c+=(i%10)
    sys.stdout.write(str(c))
    sys.stdout.write("\n");

