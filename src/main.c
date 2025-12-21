#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <unistd.h>

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
   else{
      bool inDir=false;
      char buffer[100];
      char *path=getenv("PATH");  //Gets the path specified.
      if (path==NULL){
        printf("%s:not found\n",text);

      }else{
      int a=0;
      int pos=0;
      while (path[a]!='\0' &&inDir!=true){
        buffer[pos]=path[a]; //Copies chars into string buffer.
        if (path[a]==':'){
           buffer[pos]='\0'; //Directory path is created.
           a+=1;
           pos=0;
           DIR *directory;
           struct dirent *entry;

           directory=opendir(buffer);
           if (directory==NULL){
            printf("%s Directory not found.\n",text);
           }else{
             while ((entry=readdir(directory))!=NULL){
            if (strcmp(entry->d_name,text)==0){
              printf("%s\n",buffer);
              printf("%s is %s/%s\n",text,buffer,entry->d_name);
              inDir=true;
             
            }

           }
           if (closedir(directory)==-1){
            printf("Error closing directory.\n");
            return 1;

           }

        } 
      }
      a+=1;
      pos+=1;
          
      }
      if (inDir==false) printf("%s: not found\n",text);

      } 


      



   }
  }else{
  printf("%s: command not found\n",command);
  }
  
}
return 0;

}
