#include <sys/types.h>
#include <sys/stat.h>
//le sys/stat.h ici avec sys/types.h tjrs (sys/wait.h pour les fork avancées).
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv)
{
    struct stat infos;
    //la fonction est fstat sur un fd avec &infos pour effet de bord
    //recuperer le st_mode qu'on va appliquer sur
    //S_ISREG ou S_ISSOCK,etc...
    if (-1 == (fstat(STDIN_FILENO, &infos))) {
        /* Something went wrong: check on perror to know what */
        perror("fstat");
        return EXIT_FAILURE;
    }
    if (S_ISREG(infos.st_mode))
        printf("regular file\n");
    else if (S_ISDIR(infos.st_mode))
        printf("directory\n");
    else if (S_ISCHR(infos.st_mode))
      printf("character device\n");//et c'est bien cela
    //un device(~périphérique) concu pour les caracteres (ascii code adresses--2222.(((())))).//////////////
    else if (S_ISBLK(infos.st_mode))
        printf("block device\n");
    else if (S_ISFIFO(infos.st_mode))
        printf("FIFO (named pipe)\n");
    else if (S_ISLNK(infos.st_mode))
        printf("symbolic link\n");
    else if (S_ISSOCK(infos.st_mode))
        printf("socket\n");
    return EXIT_SUCCESS;
}
