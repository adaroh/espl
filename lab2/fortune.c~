#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
  int i, numOfLine = 0;
  char line[128];
  char fileName[128]="";
  for(i = 0; argv[1][i] ; ++i)
  {
    fileName[i] = argv[1][i];
  }
  
  FILE *file = fopen(fileName, "rf");
  if(!file)
  {
    printf("Error: could not open file!\n");
    return -1;
  }
  numOfLine = getNumOfLine(file);
  int randLine = getRandomNumber(numOfLine); 
  
  printLine(fileName,randLine);
  fclose(file);
  
  return 0;
}

int getNumOfLine(FILE *file)
{
  char line[128];
  int numOfLine = 0;
  while(!feof(file))
  {
    fgets(line,127,file);
    ++numOfLine;     
  }
  return numOfLine;
}

int getRandomNumber(int numOfLine)
{
  srand(time(NULL));
  return rand() % (numOfLine + 1);
}

void printLine(char *fileName, int randLine)
{
  char line[128];
  int i;
  FILE *file2 = fopen(fileName, "rf");
  for(i = 0; i < randLine; ++i)
  {
    fgets(line,127,file2);
  }
  printf("%d: %s \n",randLine,line);
  
  fclose(file2);
}