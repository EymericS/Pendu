/**
 * \file pendu.c
 * \brief Fichier d'implementation 
 * \author Eymeric S.
 * \version 0.1
 * \date 27 decembre 2018
 * 
 * Fichier contenant l'implementation des fonctions pour l'application du 'Pendu'
 * 
 */

#include "header/pendu.h"


/**
 * \brief Lit et retourne le premier caractere saisie par l'utilisateur (Transforme en majuscule)
 * 
 * \return Caractere en majuscule
 */
char lireCaractere() {
    char caractere = toupper(getchar());

    while(getchar() != '\n');

    return caractere;
}

//TODO: Choisir un mot dans le dico

char * mot_Mystere() {
    //TODO: recherche dans le fichier
    //TODO: en majuscule

    char mot[] = "AVION"; //FIXME:

    char *buffer = malloc(strlen(mot) + 1);

    if(buffer != NULL) 
        strcpy(buffer, mot);

    return buffer;
}

//TODO: verifie sir le caractere est present dans dans la chaine mystere
// - si oui on affiche le ou les emplacement de la lettre
// - si non on enleve 1 vie ( si vie = 0 on arrete)


//TODO: affichage partie
/*
Bienvenue dans le Pendu ! -> debut
 
Il vous reste 10 coups a jouer -> info vie joueur -> 1
Quel est le mot secret ? ****** -> affichage de létat d'avancement pour le joueur -> 2
Proposez une lettre : E -> demande une lettre au joueur -> 3

#### Boucle a-2-3 ####
(informer du dernier cou^p)

Gagne ! Le mot secret etait bien : MARRON -> joueur gagne -> fin jeu
Perdu ! Vous n'avez plus de coup a jouer. Le mot secret etait : MARRON

*/
//TODO: boucle partie