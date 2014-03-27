import random

def getProb(n):
   for i in xrange(n):
     if toss() == 0:
       return 0
   return 1 

def toss():
  return random.choice([0,1])

