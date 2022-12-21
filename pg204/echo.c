#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

int main(int argc, char** argv){
  //ssize_t write(int fd, const void* buf, size_t count).
  for(int i=1;i<=argc-1;i++){
    const char* buf=argv[i];
    size_t count=strlen(buf);
    ssize_t bytes=write(0,buf,count);
    exit_if(bytes<0,"erreur ecriture sur la sortie standard.");
    const char* saut="\t";
    size_t count2=strlen(saut);
    ssize_t bytes2=write(STDOUT_FILENO,saut,count2);
    exit_if(bytes2<0,"erreur retour chariot sur la sortie standard.");
  }
  return 0;
}
