#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

//seulement car j'ai compris et je suis pas sûr de l'execution(qui importe
//peu dans les annexes (*)).
int main (int argc, char **argv)
{
    ssize_t retour, r;
    long l;

    printf("read standard: sizeof valeur=%ld, sizeof retour=%ld\n",
           (long) sizeof(long), (long) sizeof(ssize_t));

    retour = read(STDIN_FILENO, &l, sizeof(long));
    if (-1 == retour) {
        /* Something went wrong: check on perror to know what */
        perror("read (value)");
        return EXIT_FAILURE;
    } else if (sizeof(long) != retour) {
        /* Less bytes were read than it should have -> error */
        fprintf(stderr, "\"l\" n'a pas été lu en entier\n");
        return EXIT_FAILURE;
    }
    //retour contient le nombre d'octets lus
    //cela se rejecte de stdin pour aller a stdout qui est le nouveau stdin.
    //et nous y voilà entrain de lire le stdin soit le nombre lu dans & retour
    //de type ssize_t.
    r = read(STDIN_FILENO, &retour, sizeof(ssize_t));
    if (-1 == r) {
        /* Something went wrong: check on perror to know what */
        perror("read (return value)");
        return EXIT_FAILURE;
    } else if (sizeof(ssize_t) != r) {
        /* Less bytes were read than it should have -> error */
        fprintf(stderr, "\"retour\" n'a pas été lu en entier\n");
        return EXIT_FAILURE;
    }

    printf("valeur=%ld\n"
           "retour=%ld\n",
           l, (long) retour);
    return EXIT_SUCCESS;//ce code est à apprendre car on l'a compris!

    //ce programme ce comporte comme si il lisait en entree stdin
    //le contenu de ./write_number en execution. (retour normal que ca soit 0;ref: lseek(length->+infini.))///
}
