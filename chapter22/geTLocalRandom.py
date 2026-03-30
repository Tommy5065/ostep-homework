#! /usr/bin/env python
import random
num = 10
CanRat = 0.8
MAX = 10
arry = []

hotPage = set()
coldPage = set()
numLlist = set(range(0,MAX))

while len(coldPage) < (MAX*CanRat):
    i = random.choice(list(numLlist))
    coldPage.add(i)

hotPage = numLlist - coldPage

for r in range(0,num):
    if (random.random()>CanRat): # 20%时间
        t = random.choice(list(coldPage))
    else:
        t = random.choice(list(hotPage))
    arry.append(t)

file = open('/home/bake/ostep-homework/vm-beyondphys-policy/1.txt','w')

for j in arry:
    file.write(str(j)+'\n')

file.close()
    
