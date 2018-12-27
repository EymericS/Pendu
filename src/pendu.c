#include "header/pendu.h"

//TODO: Choisir un mot dans le dico
void mot_Mystere(char * mot) {
    //TODO: recherche dans le fichier
    //TODO: en majuscule
    char pendu[] = "AVION"; //FIXME:
    printf("\n-> mot mystere, pendu : %s\n", pendu);

    // Creation d'un tableau dynamique a partir d pointeur 
    mot = malloc((strlen(pendu)+1) * sizeof(char));

    // Remplie le tableau dyn avec le mot
    strcpy(mot, pendu);
    printf("\n-> mot copie, mot : %s\n", mot);
}

//TODO: lire un caractère de l'utilisateur

//TODO: verifie sir le caractere est present dans dans la chaine mystere

//TODO: affichage partie

//TODO: boucle partie