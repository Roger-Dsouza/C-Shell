#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  while (1==1){
  // TODO: Uncomment the code below to pass the first stage
  printf("$ ");
  char command[100];
  scanf("%s",command);

  if (strcmp("exit",command)==0){
   break;
  }
  printf("%s: command not found\n",command);
  }
  return 0;
}
