#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include "utils.h"

int main (int argc, char **argv)
{
    ssize_t retour, r;
    nopad valeur;

    retour = read(STDIN_FILENO, &valeur, sizeof(nopad));
    printf("%lu\n",(long)retour);
    if (-1 == retour) {
        perror("read");
        return EXIT_FAILURE;
    } else if (retour != sizeof(nopad)) {
        fprintf(stderr, "\"valeur\" n'a pas été lue en entier\n");
        return EXIT_FAILURE;
    }    

    //on va s'intéresser au nombre d'octets lus ici comme write_number ?
    //c'est différent on ecrit pas ce qu'on passe en parametre, l'exterieur est
    //mis en ecriture bufferise instanciammement par $2.

    //ici, ce qu'on doit retenir c'est à chaque fois qu'on fait un read sur un truc pas char* specialement typé autrement et qu'on fait une autre affectation avec une autre ssize_t valeur non initialisée par exemple avec stdin_fineno et la valeur precedente en &retour par exemple ici et sizoe_ssize_t) c'est qu'on lit le nombre d'octets lus de l'appel précédent. A RETENIR.
    //sinon on va rester bloqué pour l'éternité. OUFFF!

       
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
           valeur.c1, valeur.l, (long) retour);
    return EXIT_SUCCESS;
    //avec ./read_nopad <./write_nopad (reflechir de cette façon tjrs), on retrouve:
    //{c:'',l:0} retour=grande valeur car réecriture donc allongement de bits
    //valeur déjà présente persistance dans le même main(un et un seul) d'où la grande valeur. (RIEN N'A ETE ECRIT BIEN SUR SANS od-X(valeur par défaut DE la structure : nopad).

    //en od -x apres traduction en code ascii text direct sans passer par le binaire le hexadecimal marque tout, on se rend compte que des valeurs char* et int* ont ete bel et bien ecrites mais cela est très ambigue pour décoder plus une ligne de plus(la valeur manquante je crois) car cela implique même la valeur qui a été changé de 16(le nombre lu d'octets).


    //FIN DU TD1.(read/write(1/2))
    //remarque derniere __int64_t=sizeof(n) et (*(int*)) PIdR %ld pour les 64 bits de long long signed int il faut les memoriser.
    //la procedure de fonctions a part n'est pas difficile a mettre en oeuvre. 
}
