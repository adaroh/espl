#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  char c;
  
  FILE *file = fopen(argv[2] , "rt");
  if(!file)
  {
    perror("Error: could not open file!\n");
    return -1;
  }
  
  while((c = getopt(argc, argv, "hx:")) != -1)
  {
    switch(c)
    {
      case 'h':
	printf("abcdef\n");
	break;
      
      case 'x':
	printf("%d \n",getcksum(file));
	break;
	
      case '?':
       printf ("Usage: %s [-h] [-x <file>].\n", argv[0]);
       break;
    }
    
  }
  
  fclose(file);
}

int getcksum(FILE *file)
{
  unsigned int word;
  unsigned int cksum = 0;
  
  while(fread(&word, sizeof(word), 1, file)) 
  {
    cksum = cksum^word;
  }
  return cksum;
}