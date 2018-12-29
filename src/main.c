/**
 * \file main.c
 * \brief Jeu du Pendu
 * \author Eymeric S.
 * \version 1.1
 * \date 27 decembre 2018
 * 
 * Programme pour l'application du jeu du Pendu
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "header/pendu.h"
#include "header/chaineCaractere.h"

/**
 * \brief Entree du programme.
 * 
 * \param argc Nombre d'entree du programme
 * \param argv Tableau de chaine de caractere - Liste des parametres donne au programme
 * 
 * \return EXIT_SUCCESS - Arret normal du programme.
 */
int main( int argc, char *argv[] ) {
    (void)argc;
    (void)argv;
    int partie = 0;
    char choix = 0;

    printf("\nBienvenue dans le Pendu !\n");

    do {
        printf("\nJouer une nouvelle partie ? (o/n) : ");
        scanf("%c", &choix);
        while(getchar() != '\n');

        if(choix == 'o' || choix == 'O') {
            partie = 1;
            loop_partie();
        }
        else if(choix == 'n' || choix == 'N')
            partie = 0;
        else {
            partie = -1;
            printf("%c n'est pas un choix valide !\n", choix);
        }

    }while(partie);
    
    printf("\nA une prochaine !\n");

    return EXIT_SUCCESS;
}