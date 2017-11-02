#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"



int main()
{
    T_Liste *l1;
    int choix;

    do
    {
        printf("\n\n-------------- Actions : ---------------\n");
        printf("\t1. Creer une liste\n");
        printf("\t2. Ajouter element liste\n");
        printf("\t5. Afficher liste\n");
        printf("\t6. Rechercher element\n");
        printf("\t8. Quitter\n");

        printf("Entrer votre choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 1 : l1 = creerListe(); break;
            case 2 : insererElement(l1); break; //Faire affichage Echec/Erreur
            case 5 : afficherListe(l1); break;
            case 6 : Rechercher ();
            case 8 : break; //on va quitter <3
            default : break;
        }
    } while (choix != 8);
}

