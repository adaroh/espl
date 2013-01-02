#!/usr/bin/python
import sys

f = file("grades.csv")

numOfRow = 0
avg = float(0)
gradesList = {}
gradeStudentList = {}

f.next()
for line in f:
  print line ,  
  strArr = line.strip().split(",")
  student, brochure, grade = strArr
  numOfRow += 1
  avg+= float(grade)
  if grade in gradesList:
    gradesList[grade] += 1
    gradeStudentList[grade] += (","+brochure)
  else:
    gradeStudentList[grade] = brochure
    gradesList[grade] = 1
    
  
#print the Average of grades
print "\nAverage: " +str(avg/numOfRow) +"\n"


for name, number in gradesList.iteritems():
  print ("The number of grade:%s is %d" % (name ,number) +":%s" % gradeStudentList[name])