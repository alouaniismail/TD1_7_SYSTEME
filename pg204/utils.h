#ifndef _UTILS_H
#define _UTILS_H

#include <signal.h> // for sigset_t

typedef struct nopad{
  char c1;
  char c2;
  long l;//bourrage sur une seule ligne de taille double d'un vecteur de 8
  //char soit 8*2=16 octets.(avec CFLAGS+=-O3 la taille ne va pas changer
  //mais le résultat oui..)
}nopad;

/**
 * exit printing error prefixed by `prefix` if `condition` is true (non zero)
 */
void exit_if(int condition, const char *prefix);

/**
 * Compute fibonnaci of `n` (takes time around 40 on my computer)
 */
unsigned long long fibo(int n);

/**
 * splits `argv` between `args1` or `args2`
 * if they are before or after the separator "--".
 * Returns -1 on error
 */
int split_args(char *argv[], char *args1[], char *args2[]);

int create_waiting_child(int time);

const char *signame(int signal);
void print_sigset(int fd, const sigset_t *sigset);

void print_signals(int fd);

#endif
