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

/**
 * \brief Renvoie un mot choisi au hazard dans le DICTIONNAIRE
 * 
 * \return Chaine de caractere
 */
char * mot_Mystere() {
    FILE* dico = NULL;
    char mot[TAILLE_MAX_CHAINE] = "";
    if((dico = fopen(DICTIONNAIRE, "r")) != NULL) {
        char ligne[TAILLE_MAX_CHAINE] = "";
        int nb_ligne = 0;
        int ligneChoisi = 0;
        srand(time(NULL));

        while(fgets(ligne, TAILLE_MAX_CHAINE, dico) != NULL)
            nb_ligne++;

        rewind(dico);
        ligneChoisi = rand()%nb_ligne;
        printf("ligneChoisi = %d\n", ligneChoisi);
        while(ligneChoisi && fgets(ligne, TAILLE_MAX_CHAINE, dico) != NULL)
            ligneChoisi--;

        fgets(mot, TAILLE_MAX_CHAINE, dico);
        printf("Le mot est %s\n", mot);

        fclose(dico);
    }
    else {
        printf("Impossible d'ouvire le fichier %s", DICTIONNAIRE);
    }

    char *buffer = malloc(strlen(mot) + 1);

    if(buffer != NULL) 
        strcpy(buffer, mot);

    return buffer;
}

void loop_partie() {
    int coup = 10;
    char *motMystere = mot_Mystere();
    char motJoueur[strlen(motMystere)];
    for(unsigned int i=0;i<strlen(motMystere);i++)
        motJoueur[i] = '*';
    
    motJoueur[strlen(motMystere)] = '\0';

    printf("\nBienvenue dans le Pendu !\n\n");
    printf("Le mot mystere est %s\n", motMystere);
    printf("Votre mot est %s\n", motJoueur);

    /*
    while(coup && !action_joueur()) {
        coup--;
        affichage_etat_partie(coup)
    }
    */
    if(motMystere != NULL)
        free(motMystere);
}

//TODO: verifie sir le caractere est present dans dans la chaine mystere
// - si oui on affiche le ou les emplacement de la lettre
// - si non on enleve 1 vie ( si vie = 0 on arrete)


//TODO: affichage_etat_partie
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