#include <string.h>
#include <stdio.h>

int cmpstr(char *str1, char *str2)
{
  int i;
  int answer = 0;
   
  for(i = 0;(str1[i] != 0)&&(str2[i] != 0)  ;++i )
  {
    if(str1[i] != str2[i])
    {
      answer = str1[i] > str2[i] ? 1 : 2 ;
      break;
    }
  }
  if (str1[i]==0 && str2[i]!=0)
      answer = 2;
  if(str1[i]!=0 && str2[i]==0)
      answer = 1;
  
  
  return answer;
}