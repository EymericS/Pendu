#include <stdio.h>
#include <stdlib.h>
#include "header/pendu.h"

int main( int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    char *mot = mot_Mystere();
    printf("\nLe mot choisi est : %s\n\n", mot);

    if(mot != NULL)
        free(mot);

    return EXIT_SUCCESS;
}