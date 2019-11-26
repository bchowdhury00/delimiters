#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args(char * line){
  char * source = &line;
  char delim[] = " ";
  char * args= malloc(0);
  int counter = 0;
  while (*source != NULL){
    args = realloc(args,counter * sizeof(char *));
    args[counter] = strsep(source,delim);
    counter++;
  }
  return &args;
}

int main(int argc, char * argv[]){
  char * cmd = argv[1];
  char ** args = parse_args(cmd);
  execvp(args[0],args);
  return 0;
}
      
