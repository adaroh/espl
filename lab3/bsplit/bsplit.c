#include <stdio.h>
#include <unistd.h>
#include <string.h>
/* #include "xsum.h" TODO
 */

int main(int argc, char **argv)
{
  char c;
  
  FILE *file = fopen(argv[argc-1] , "rt");
  if(!file)
  {
    perror("Error: could not open file!\n");
    return -1;
  }
  /*TODO 
 * check size before 
 * int limSize = (size == 0) ? (1024/sizeof(int)) : size/sizeof(int);
 */
  
  int size = 1024;//TODO
  setChunksFiles(file,argv[argc-1],size);
  
  /*
  while((c = getopt(argc, argv, "bhx:")) != -1)
  {
      switch(c)
      {
	
	case 'b':
	  
	  break;
	    
	case 'h':
	  printf("usage: %s [-x] [-h] <FILE>\n",argv[0]);
	  break;
	
	case 'x':
	  printf("0x%x\n",getcksum(file));
	  break;
    
	case'?'://TODO need to print decimalsss
	  printf("%d\n",getcksum(file));
	  break;
      }
  }
  */
  
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


int setChunksFiles(FILE *file, char *nameInputFile, int size)
{
  int countOfFile = 1;
  int numOfBytes = 0;
  
  int word[size];
 
  char *nameOfOutPutFile;
  FILE *outputFile;
  
  
  while(numOfBytes = fread(word,1,size,file))
  {
    strcat(nameInputFile,(".%d",countOfFile));
    outputFile = fopen(nameOfOutPutFile , "wt");
  
    fwrite(word, 1, numOfBytes , outputFile);
    ++countOfFile;
    
    fclose(outputFile);
  }
}