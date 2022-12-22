#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

int main(int argc, char** argv){
  //ce qui est produit par write_number c'est:
  //l'affichage d'un long l qu'on va ecrire sur stdin donc long l et &l $2
  //de read dans retour avec sizeof(long).
  //et un ssize_t correspondant au nombre d'octets d'avant.
  long l;
  ssize_t retour=read(STDIN_FILENO,&l,sizeof(long));
  printf("%ld\n",l);
  printf("%lu\n",retour);

  exit_if(retour==-1,"something wrong with read procedure.");
  exit_if(sizeof(long)!=retour,"ça n'a pas étés lus en tant qu'entier.");

  return EXIT_SUCCESS;
}
