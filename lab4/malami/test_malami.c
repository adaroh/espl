#include <stdlib.h>
#include <stdio.h>

extern int malami(char*);

int main(int argc, char **argv) 
{
    char word[80];
    printf("insert a number: ");
    scanf("%s",word);
    printf("%d \n",malami(word));

    return 0;
}