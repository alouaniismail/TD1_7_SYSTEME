#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include "utils.h"

int main (int argc, char **argv)
{
    ssize_t retour;
    nopad valeur;

    valeur.c1 = 'a';
    valeur.l = 5;
    
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
