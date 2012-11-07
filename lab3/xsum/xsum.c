#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  char c;
  
  FILE *file = fopen(argv[argc-1] , "rt");
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
	printf("usage: %s [-x] [-h] <FILE>\n",argv[0]);
	break;
      
      case 'x':
	printf("0x%x\n",getcksum(file));
	break;
  
      case'?'://TODO need to print decimalss
	printf("%d\n",getcksum(file));
	break;
    }
    
  }
  
  fclose(file);
}

int getcksum(FILE *file)
{
  unsigned int word = 0;
  unsigned int cksum = 0;
  
  while(fread(&word,1,sizeof(word),file)) 
  {
    cksum = cksum^word;
    word = 0;
  }
  return cksum;
}