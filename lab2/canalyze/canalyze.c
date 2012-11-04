#include <stdio.h>
#include <stdlib.h>
#include "fgetname.h"
#include "namelist.h"

int main(int argc,char **argv)
{
  int i,numOfWords = 0;
  char fileName[128]="";
  char name[128] = "";
  
  namelist name_list = make_namelist();
  
  for(i = 0; argv[1][i] ; ++i)
  {
    fileName[i] = argv[1][i];
  }
  
//   printf("file name: %s \n", fileName);
  FILE *file = fopen(fileName, "rf");
  if(!file)
  {
    printf("Error: could not open file!\n");
    return -1;
  }
  
  while(fgetname(name,128,file) != NULL)
  {
//     printf("%s \n",name);//TODO
    if(isKeyWords(name))
    {
     add_name(name_list,name);
     //       printf("   it's not a keywords \n");//TODO
    }
//     printf("\n");//TODO
  }
  
  fclose(file);
}

/*return 0 it's a keyWords
    1 it's not a keywords*/
int isKeyWords(char *name)
{
  char *keyWords[] = {"auto","break","case","char","const","continue","default","do"
  ,"double","else","enum","extern","float","for","goto","if"
  ,"int","long","register","return","short","signed","sizeof","static"
  ,"long","switch","typedef","union","unsigned","void","volatile","while"};
  
 int i; 
 
 for(i =0; i < 32 ; ++i)
 {
    if(strcmp(keyWords[i],name) == 0){
      return 0;
    }
 }
 return 1;
  
}