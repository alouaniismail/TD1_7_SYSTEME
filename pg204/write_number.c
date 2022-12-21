#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

int main(int argc, char** argv){
  //ssize_t write(int fd, const void* buf, size_t count).
  long l=5;
  ssize_t bytes=write(STDOUT_FILENO,&l,sizeof(l));
  exit_if(bytes==-1,"erreur ecriture sur la sortie standard.");
  exit_if(bytes!=sizeof(l),"pas d'ecriture en tant que l'entier qu'on veut.");
  ssize_t bytes2=write(STDOUT_FILENO,&bytes,sizeof(ssize_t));
  exit_if(bytes2==-1,"erreur de même que précédemmet");
  exit_if(bytes2!=sizeof(ssize_t),"retour n'a pas ete ecrit en entier.");
  return 0;
}
