#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
  int i, numOfLine = 0;
//   char line[128];
  char fileName[]="";
  for(i = 0; argv[1][i] ; ++i)
    fileName[i] = argv[1][i];
  FILE *file = fopen(fileName, "rf");
  if(!file)
  {
    printf("Error: could not open file!\n");
    return -1;
  }
  while(feof(file))
  {
    ++numOfLine;
  }
  
  printf("number of lines: %d",numOfLine);
  
//   fclose(file);
  
  return 0;
}
