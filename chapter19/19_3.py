#! /usr/bin/env python
import os

i = 1
while i < 2000:
    print("page num:",i)
    val = os.system('./19_4 '+str(i)+' '+str(9999))
    i *=2


