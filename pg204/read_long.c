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

  //nouveau stdin bufferisation.//en entier celui-ci seulement.///
  printf("%lu\n",retour);
  ssize_t r;//lecture de stdout en tant que nombre d'octets imprimés.
  ssize_t retour2=read(STDOUT_FILENO,&r,sizeof(ssize_t));
  
  //pour analyser l'exo.
  exit_if(retour==-1,"something wrong with read procedure.");
  exit_if(sizeof(long)!=retour,"ça n'a pas étés lus en tant qu'entier.");
  
  exit_if(-1==retour2,"something wrong with the second copy.");
  exit_if(sizeof(ssize_t)!=retour2,"retour n'a pas été lue en entier(2/2)");
  return EXIT_SUCCESS;
}
