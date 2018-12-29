#ifndef _CHAINE_CARACTERE_H_
#define _CHAINE_CARACTERE_H_

/**
 * \file chaineCaractere.h
 * \brief Fichier declaration
 * \author Eymeric S.
 * \version 1.5
 * \date 27 decembre 2018
 * 
 * Fichier contenant la declaration des fonctions et variable et/ou constante pour la manipulation de chaine de caractere
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void chaine_pop( char chaine[], int mode ) ;
int verifie_lettre( char mot[], char recherche[], char c ) ;
void str_toupper( char str[] ) ;

#endif