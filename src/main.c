/**
 * \file main.c
 * \brief Jeu du Pendu
 * \author Eymeric S.
 * \version 0.1
 * \date 27 decembre 2018
 * 
 * Programme pour l'application du jeu du Pendu
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "header/pendu.h"

/**
 * \fn int main (void)
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

    char *mot = mot_Mystere();
    printf("\nLe mot choisi est : %s\n\n", mot);


    printf("Entrer un caractere : ");
    char test = lireCaractere();
    printf("Vous avez saisie : %c\n\n", test);

    if(mot != NULL)
        free(mot);

    return EXIT_SUCCESS;
}