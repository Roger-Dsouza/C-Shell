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
  int a=strlen(command);
   

  char four_word[5];
  for (int i=0;i<4;i++){
   four_word[i]=command[i];
  }
  
  char text[strlen(command)];

  if (strcmp(four_word,"echo")==0){
   for (int i=4;i<strlen(command);i++){
	text[(i-4)]=command[i];

}
   text[strlen(command)]='\0';
   printf("%s\n",command);


  }


  if (strcmp("exit",command)==0){
   break;
  }
  printf("%s: command not found\n",command);
  }
  return 0;
}
