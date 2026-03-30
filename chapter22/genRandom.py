#! /usr/bin/env python
import random
num = 10
arr = []

for j in range(1,10):
    i = random.randint(0,num)
    arr.append(i)

file = open('/home/bake/ostep-homework/vm-beyondphys-policy/1.txt','w')

for j in arr:
    file.write(str(j)+'\n')

file.close()
