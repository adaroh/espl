#!/usr/bin/python

import sys
import random

def random_line(afile):
    line = next(afile)
    for num, aline in enumerate(afile):
      if random.randrange(num + 2): continue
      line = aline
    return line

f = file("long-words.txt")
if f

games = 0
line = random_line(f)
print(line)
