#include <stdio.h>
#include <stdlib.h>
#include "header/pendu.h"

int main( int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    char *mot = NULL;

    mot_Mystere(mot);
    printf("\nLe mot choisi est : %s\n\n", mot);

    return EXIT_SUCCESS;
}