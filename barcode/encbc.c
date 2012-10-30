#include <assert.h>
#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv)
{
  int barcode[80][BC_NBITS] = {0};
  int i,j,numOfChar = 0;

  for(i = 1; i < argc; ++i)
  {
	  for(j = 0; argv[i][j] ; ++j)
	  {
		  bc_char2bits(argv[i][j],barcode[numOfChar]);
		  ++numOfChar;
		
		  printf("<%d , %d > \n",i,j);
		  printf("%c \n \n", argv[i][j]);
		  
	  }
  }

  /* print */
  for(i = 1; i < BC_NBITS; ++i)
  {
	  for(j = 0;j < numOfChar ; ++j)
	  {
		if(barcode[i][j])
		  printf("1");
		  
		else
		  printf("0");

	  }
	  printf("\n");
  }
  return 0;
}