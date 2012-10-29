#include <assert.h>
#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv)
{
  int barcode[80][BC_NBITS] = {0};
  int i,j,numOfChar = 0;
  int currChar;


  for(i = 1; i < argc; ++i)
  {
	  for(j = 0;  ; ++j)
	  {
		  currChar = argv[i][j];
		  if(currChar == '\0')
		  {
			  break;
		  }
		  bc_char2bits(currChar,barcode[numOfChar]);
		  ++numOfChar;
		
		  /*printf("<%d , %d > \n",i,j);
		  printf("%c \n", argv[i][j]);
		  */
	  }
  }

  /* print */
  for(i = 0; i < numOfChar; ++i)
  {
	  for(j = 0;j < BC_NBITS ; ++j)
	  {
		if(barcode[i][j] == 1)
		  printf("#");
		  
		else
		  printf(" ");

	  }
  }
}