#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include "utils.h"

int main (int argc, char **argv)
{
    ssize_t retour;
    nopad valeur;
    printf("%ld\n",(long)(sizeof(nopad)));
    //24 car long l 8*3=24 stockage oui donc bourrage eventuel d'octets
    //les empilements sur mesure sur la pile d'appels.
    valeur.c1 = 'a';
    valeur.l = 5;

    //avec | od -x on retrouve bel est bien tout a gauche (l'inverse) 0061 ....(3)
    //qui correspond en hexadecimal a un certain a en bourrage eventuel..
    //on retrouve aussi 5 sur 2*4=8 octets comme prévu.(l'avant aussi)
    
    retour = write(STDOUT_FILENO, &valeur, sizeof(nopad));
    if (-1 == retour) {
        /* Something went wrong: check on perror to know what */
        perror("write (valeur)");
        return EXIT_FAILURE;
    } else if (sizeof(nopad) != retour) {
        /* Less bytes were written than it should have -> error */
        fprintf(stderr, "\"valeur\" n'a pas été écrite en entier.\n");
        return EXIT_FAILURE;
    }
    /* retour est ici affecté APRÈS l'appel système, et donc
       l'ancienne valeur est écrite dans STDOUT_FILENO avant le retour
       de l'appel, et donc l'affectation. */
       //cela va clairement justifier ce qu'on avait dit avant dans la deuxieme version de read_long.(voilà)

    //on va afficher le nombre d'octets lus.

    //on aimerait bien apres l'affichage des donnees en od -x inspecter le nombre
    //d'octets lus. avec od -x on obtient un nombre en hexadecimal dont
    //la traduction en texte nous donne ........61.
    //ce qui correspond en binaire à 16 soit 16 octets lus ce qui est totalement
    //cohérent avec ce qu'on fait.
    retour = write(STDOUT_FILENO, &retour, sizeof(ssize_t));
    if (-1 == retour) {
        /* Something went wrong: check on perror to know what */
        perror("write (retour)");
        return EXIT_FAILURE;
    } else if (sizeof(ssize_t) != retour) {
        /* Less bytes were written than it should. Error */
        fprintf(stderr, "\"retour\" n'a pas été écrit en entier.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
