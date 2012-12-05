#include <assert.h>
#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv)
{
  int barcode[80][BC_NBITS] = {0};
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

  /*print*/
    for(j = 0; j < BC_NBITS ;++j)
    {
       for(i = 0; i < numOfChar; ++i)
       {
	 printf("%c",barcode[i][j] == 0 ? ' '  : '#');
       }
       printf("\n");
    }
  return 0;
}