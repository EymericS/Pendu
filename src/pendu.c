/**
 * \file pendu.c
 * \brief Fichier d'implementation 
 * \author Eymeric S.
 * \version 1.5
 * \date 30 decembre 2018
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

        while(ligneChoisi && fgets(ligne, TAILLE_MAX_CHAINE, dico) != NULL)
            ligneChoisi--;

        fgets(mot, TAILLE_MAX_CHAINE, dico);

        fclose(dico);
    }
    else {
        printf("Impossible d'ouvire le fichier %s", DICTIONNAIRE);
    }

    char *buffer = malloc(strlen(mot)); // On enleve la place du '\n'

    if(buffer != NULL) 
        strcpy(buffer, mot);

    buffer[strlen(mot)-1] = '\0'; // On remplace \n par \0 la chaine

    return buffer;
}

/**
 * \brief Boucle de deroulement d'une partie de pendu
 * 
 */
void loop_partie() {
    char choix = 0;
    int coup = 10;

    do {
        printf("\nMode disponible :\n");
        printf("\t1 - Solo\n");
        printf("\t2 - Duo\n");
        printf("\tq - Exit\n");
        printf("Quel mode voulez-vous ? ");
        scanf("%c", &choix);
        while(getchar() != '\n');

        if(choix == '1'){ // Mode solo
            printf("\nVous commencer un nouvelle partie !\n");
            choix = 'q';
            char saisieJoueur = 0;
            char *motMystere = mot_Mystere(); // Creation du mot mystere
            char motJoueur[strlen(motMystere)+1];
            motJoueur[0] = '\0';

            for(unsigned int i = 0 ; i < strlen(motMystere) ; i++)
                strcat(motJoueur, "*");
            
            motJoueur[strlen(motJoueur)] = '\0'; // Creation du mot joueur

            while (coup && strcmp(motJoueur, motMystere)) {
                printf("\nIl vous reste %d coups a jouer\n", coup);
                printf("Quel est le mot secret ? %s\n", motJoueur);
                printf("Proposez une lettre : ");
                saisieJoueur = lireCaractere();
                coup -= verifie_lettre(motMystere, motJoueur, saisieJoueur);
            }
            
            if(coup)
                printf("\nGagne ! Le mot secret etait bien : %s ( %s ) !\n", motMystere, motJoueur);
            else
                printf("\nPerdu ! Vous n'avez plus de coup a jouer. Le mot secret etait : %s ( %s ) !\n", motMystere, motJoueur);

            if(motMystere != NULL) 
                free(motMystere);

        }
        else if(choix == '2') { // Mode duo
            printf("\nVous commencer un nouvelle partie !\n");
            choix = 'q';
            char saisieJoueur = 0;
            char motMystere[TAILLE_MAX_CHAINE];
            printf("\nMerci de choisir le mot a trouver (%d caractere max): ", TAILLE_MAX_CHAINE);
            fgets(motMystere, TAILLE_MAX_CHAINE, stdin);
            motMystere[strlen(motMystere)-1] = '\0';
            str_toupper(motMystere);
            
            char motJoueur[strlen(motMystere)+1];
            motJoueur[0] = '\0';

            for(unsigned int i = 0 ; i < strlen(motMystere) ; i++)
                strcat(motJoueur, "*");
            
            motJoueur[strlen(motJoueur)] = '\0'; // Creation du mot joueur
            clear_term();

            while (coup && strcmp(motJoueur, motMystere)) {
                printf("\nIl vous reste %d coups a jouer\n", coup);
                printf("Quel est le mot secret ? %s\n", motJoueur);
                printf("Proposez une lettre : ");
                saisieJoueur = lireCaractere();
                coup -= verifie_lettre(motMystere, motJoueur, saisieJoueur);
            }
            
            if(coup)
                printf("\nGagne ! Le mot secret etait bien : %s ( %s ) !\n", motMystere, motJoueur);
            else
                printf("\nPerdu ! Vous n'avez plus de coup a jouer. Le mot secret etait : %s ( %s ) !\n", motMystere, motJoueur);
 
        }
        else if(choix =='q') ;
        else {
            choix = -1;
            printf("%c n'est pas un choix valide !\n", choix);
        }

    }while(choix != 'q');

}

/**
 * \brief Vide l'affichage du termnial
 * 
 */
void clear_term() {
    #ifdef _WIN32
    system("cls");
    #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
    #else
        #error "OS not supported."
    #endif
}