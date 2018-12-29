#ifndef _PENDU_H_
#define _PENDU_H_

/**
 * \file pendu.h
 * \brief Fichier declaration
 * \author Eymeric S.
 * \version 0.1
 * \date 27 decembre 2018
 * 
 * Fichier contenant la declaration des fonctions et variable et/ou constante pour l'application du 'Pendu'
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "chaineCaractere.h"

#define DICTIONNAIRE "asset/dictionnaire.txt" //! \def Chemin vers le fichier contenant le dictionnaire
#define TAILLE_MAX_CHAINE 50 //! \def Nombre de caractere maximum d'une chaine de caractere

char lireCaractere() ;
char * mot_Mystere() ;
void loop_partie() ;

#endif