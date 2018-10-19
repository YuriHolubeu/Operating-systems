#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

char *original;
char *token;

original = malloc(sizeof(char)*100);
scanf("%s", original);

original = strdup(original);


token=strtok(original, ", ");

while (token !=NULL){
printf("token: %s\n", token);
token=strtok(NULL, ",");

}

  return 0;
}
