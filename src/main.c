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

    loop_partie();

    return EXIT_SUCCESS;
}