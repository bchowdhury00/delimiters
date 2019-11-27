#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args(char * line){
  char delim[] = " ";
  char ** args = malloc(6 * sizeof(char*));
  int counter = 0;
  while (line != NULL){
    args[counter] = strsep(&line,delim);
    counter++;
  }
  args[counter] = NULL;
  return args;
}

int main(int argc, char * argv[]){
  char * cmd = argv[1];
  char ** args = parse_args(cmd);
  execvp(args[0],args);
  return 0;
}
      
