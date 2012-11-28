#include <string.h>
#include <stdio.h>

int cmpstr(char *str1, char *str2)
{
  int i;
  int answer = 0;
  int cStr1 = str1[0];
  int cStr2 = str2[0];
  
  printf("%s","in cmpstr");
  for(i = 1;(str1[i] == 0)||(str1[i] != str2[i])  ;++i )
  {
    cStr1 = str1[i];
    cStr2 = str2[i];
  }
  
  if(cStr1 != cStr2)
  {
    answer = cStr1 > cStr2 ? 1 :2 ;
  }
  
  return answer;
}