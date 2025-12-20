#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  char *builtin[3]={"echo","exit","type"};
  while (1==1){
   setbuf(stdout, NULL);
   setbuf(stdin,NULL);
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
   text[strlen(command)-5]='\0';
   printf("%s\n",text);

  }else if(strcmp("exit",command)==0){
  break;

  }else if (strcmp("type",four_word)==0){
   for (int i=5;i<strlen(command);i++){
     text[i-5]=command[i];
   }
   text[strlen(command)-5]='\0';
   bool isType=false;
   for (int a=0;a<3;a++){
    if (strcmp(text,builtin[a])==0) isType=true;
   }

   if (isType==true) printf("%s is a shell builtin\n",text);
   else printf("%s: not found\n",text);
  }else{
  printf("%s: command not found\n",command);
  }
  
}
return 0;

}
