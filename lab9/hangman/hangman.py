#!/usr/bin/python

import sys
import random
import os

wordlib = "long-words.txt"

def random_line(afile):
    line = next(afile)
    for num, aline in enumerate(afile):
      if random.randrange(num + 2): continue
      line = aline
    return line

def isFileEmpty(aFile):
     aFile.seek(0) 
     first_char = aFile.read(1) #get the first character
     if not first_char:
         print "Missing word library" #first character is the empty string..
         print "(online at http://www.intuitive.com/wicked/examples/long-words.txt save the file as %s and you're ready to play!)\n" %(wordlib)
         return 1
     else:
         aFile.seek(0) #first character wasn't empty, return to start of file.
         return 0


f = file(wordlib) 
if isFileEmpty(f) == 0:
    #init 
    games = 0
    word = random_line(f)
    lim = 6
    lengtrh = len(word)-1
    mistakes = 0
    finished =false
    wordArray = ["_ "]*lengtrh
    lettersArray = []
    
    while mistakes < lim and not finished:
      guess = str(raw_input("Guess a letter: "))
      if len(guess) > 1:
	if guess == "bye":
	  break
	else:
	  print  "Uh oh: You can only guess a single letter at a time"
      else:
	if 
    print "%s \n %s" %(word,wordBeforeGuess)
    #while wrongGuess !=0 :
      
     # print "Guess a letter: "
	
      