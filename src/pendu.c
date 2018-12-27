#include "header/pendu.h"

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

//TODO: lire un caractère de l'utilisateur

//TODO: verifie sir le caractere est present dans dans la chaine mystere

//TODO: affichage partie

//TODO: boucle partie