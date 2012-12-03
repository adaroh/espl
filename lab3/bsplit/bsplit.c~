#include <stdio.h>
#include <unistd.h>
#include <string.h>

 #include "xsum.h"



int getcksum(FILE *);
int splitToSeveralFiles(FILE *, char *, int );

int main(int argc, char **argv)
{

  int operation;
  int sizeOfChunks = 1024; //default of chunk
  char* fileName = argv[0];
  
  while((operation = getopt(argc, argv, "bhx:")) != -1)
  {
      switch(operation)
      {
	
	case 'b':
	  sizeOfChunks = atoi(argv[argc-2]);
	  break;
	    
	case 'h':
	  printf("usage: %s [-x] or [-h] or [-b SIZE] <FILE>\n",argv[0]);
	  return 0;
	
	case 'x':
	  printf("0x%x\n",getcksum(file));
	  break;
      }
  }

  FILE *file = fopen(argv[argc-1] , "rt");
  if(!file)
  {
    perror("Error: could not open file!\n");
    return -1;
  }

  splitToSeveralFiles(file,argv[argc-1],sizeOfChunks);
  
  fclose(file);
}


int splitToSeveralFiles(FILE *file, char *nameInputFile, int sizeOfChunks)
{
    unsigned char newChunk[sizeOfChunks];
    memset(newChunk, 0 ,sizeOfChunks); //void * memset(void *dest, int  value_to_set, size_t number_of_bytes);
      
      
      
      int countOfFile = 1;
      int numOfBytes = 0;
      
      int word[size];
    
      char *nameOfOutputFile;
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


/*
http://www.java-samples.com/showtutorial.php?tutorialid=591 -mem (set,cut,move)
 */