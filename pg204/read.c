#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
#define BUFFER_SIZE 1025

int main(int argc, char** argv){
  //ssize_t read(int fd, void *buf, size_t count);
 
  //on peut recevoir plus que BUFFER_SIZE octets de données.
  //on doit faire une boucle qui essaie à chaque fois de lire tout cela
  //en le mettant dans buffer.
  ssize_t ecrits=0;
  ssize_t lues;
  while(1){
    //on declare a chaque tour un nouveau buffer.
    char buffer[BUFFER_SIZE];
    lues=read(STDIN_FILENO,buffer,BUFFER_SIZE);
    //on met dedans les donnees lues avec count=BUFFER_SIZE
    //mais lors de l'ecriture ca sera lues le retour de la fonction read (2).
    exit_if(lues<0,"erreur lors de la lecture sur le flux entrant.");
    if(0==lues){
      /*End_of_file.*/
      return EXIT_SUCCESS;
    }
    //on a lu lues octets depuis STDIN_FILENO.
    ssize_t w=write(STDOUT_FILENO,buffer,lues);
    exit_if(w<0,"erreur lors du report sur le modele d'echo.");
    ecrits+=w;
  }
  //ecrits constitue l'ensemble des octets le nombre transférés de stdin_fileno
  //vers le flux de sortie standard(0).
  return 0;
}
