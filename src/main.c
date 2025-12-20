#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);
  while (1==1){
   printf("$ ");
   char command[100];
   scanf("%[^\t\n]",command);  

   char four_word[5];
   for (int i=0;i<4;i++){
   four_word[i]=command[i];
   }
   four_word[4]='\0';
  
   char text[strlen(command)];

   if (strcmp(four_word,"echo")==0){
   for (int i=0;i<strlen(command);i++){
     text[i-5]=command[i];
   }
   text[strlen(command)]='\0';
   printf("%s\n",text);

  }else if(strcmp("exit",command)==0){
   break;
  }else{
  printf("%s: command not found\n",command);
  }
  
}
return 0;

}
