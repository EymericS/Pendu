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

#define DICTIONNAIRE "asset/dictionnaire.txt" //! \def Chemin vers le fichier contenant le dictionnaire

char lireCaractere();

char * mot_Mystere();

#endif