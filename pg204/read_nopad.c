#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include "utils.h"

int main (int argc, char **argv)
{
    ssize_t retour, r;
    nopad valeur;

    retour = read(STDIN_FILENO, &valeur, sizeof(nopad));
    if (-1 == retour) {
        perror("read");
        return EXIT_FAILURE;
    } else if (retour != sizeof(nopad)) {
        fprintf(stderr, "\"valeur\" n'a pas été lue en entier\n");
        return EXIT_FAILURE;
    }    

    r = read(STDIN_FILENO, &retour, sizeof(ssize_t));
    if (-1 == r) {
        /* Something went wrong: check on perror to know what */
        perror("read (return value)");
        return EXIT_FAILURE;
    } else if (sizeof(ssize_t) != r) {
        /* Less bytes were read than it should have -> error */
        fprintf(stderr, "\"retour\" n'a pas été lu en entier\n");
        return EXIT_FAILURE;
    }//reprise sur le devant.
    //a apprendre surtout pour les $1(les 3 versions(++)).

    printf("valeur={c: '%c', l: %ld}\n"
           "retour=%ld\n",
           valeur.c, valeur.l, (long) retour);
    return EXIT_SUCCESS;
}
