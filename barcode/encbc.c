#include <assert.h>
#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv)
{
  int barcode[80][BC_NBITS] = {0};
  int i,j;
    
  for(i = 1, j = 0; i < argc; ++i)
  {
      barcode[i] =   bc_char2bits(argv[1][0]);   
  }
  
  /* print */
  for(){
    for(i = 0; i < BC_NBITS; ++i)
    {
      for(j = 0;j < ; ++j)
      {
	if(barcode[][] == 1)
	  printf("#");
	  
	else
	  printf(" ");
	
      }
    }
  }
  
  
}

