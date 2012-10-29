#include <assert.h>
#include <stdio.h>
#include "bclib.h"
void printBarcode();

int main(int argc, char **argv)
{
  int barcode[80][BC_NBITS] = {0};
  int i,j,numOfChar = 0;


  for(i = 1; i < argc; ++i)
  {
	  for(j = 0;  ; ++j)
	  {
		  if(argv[i][j] == '\0')
		  {
			  break;
		  }
		  int bits[BC_NBITS] = {0};
		  barcode[numOfChar] = bc_char2bits(argv[i][j],bits);
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