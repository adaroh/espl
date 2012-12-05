#include <assert.h>
#include <stdio.h>
#include "bclib.h"

void start();
void printBarcode(int);
int getLineToArray(int,char **);

int barcode[80][BC_NBITS] = {0};

int main2(int argc, char **argv){
  start(argc,argv);
  
  return 0;
}


void start(int argc,char **argv){
  int numOfChar = 0;
  numOfChar = getLineToArray(argc,argv);
 
  printBarcode(numOfChar);  
}

void printBarcode(int numOfChar){
  int j,i;
  for(j = 0; j < BC_NBITS ;++j)
  {
      for(i = 0; i < numOfChar; ++i)
      {
	printf("%c",barcode[i][j] == 0 ? ' '  : '#');
      }
      printf("\n");
  }
}

int getLineToArray(int argc,char **argv){
  int i,j,numOfChar = 0;
  
  for(i = 1; i < argc; ++i)
  {
    for(j = 0; argv[i][j] ; ++j,++numOfChar)
    {
	bc_char2bits(argv[i][j],barcode[numOfChar]);
    }
    
    if(i < argc -1)
    {
      bc_char2bits(' ',barcode[numOfChar]);
      ++numOfChar;
    }
  }
  return numOfChar;
}