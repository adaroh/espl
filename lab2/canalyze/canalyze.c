#include <stdio.h>
#include <stdlib.h>
#include "fgetname.h"
#include "namelist.h"
#include <string.h>

int myStrcmp(const void* s1, const void* s2);

int main(int argc,char **argv)
{
  int i,numOfWords = 0;
  char name[NAMELEN];
  FILE *file;
  
  namelist name_list = make_namelist();
  
  for(i = 1; i < argc ; ++i)
  {
      file = fopen(argv[i], "rf");
      if(!file)
      {
	printf("Error: could not open file!\n");
	return -1;
      }

      while(fgetname(name,sizeof(name),file) != NULL)
      {
	  if(isKeyWords(name))
	  {
	    add_name(name_list,name);
	  }
      }
      fclose(file);
  }
  qsort(name_list->names ,name_list->size ,sizeof(struct namestat), myStrcmp);
  
  for(i = 0 ; i < name_list->size ; ++i)
  {
    printf("%s %d \n",name_list->names[i].name,name_list->names[i].count);  
  }
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
 
 for(i =0; i < sizeof(keyWords)/sizeof(char*); ++i)
 {
    if(strcmp(keyWords[i],name) == 0){
      return 0;
    }
 }
 return 1;
  
}


int myStrcmp(const void* s1, const void* s2)
{
  return strcmp(((struct namestat*)s1)->name,((struct namestat*)s2)->name);
}
