#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"



int main()
{
    TabListe *tab1;
    T_Liste *list1;
    int choix;
    Table *table1;
    int i=0;
    table1=malloc(sizeof(Table));

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
            case 1 : tab1 = creationListe(); list1 = tab1->liste; table1->Tableau[i]=tab1; i++; break; //on cree une liste et on l ajoute dans le tableau des listes
            case 2 : insererElement(list1); break; //Faire affichage Echec/Erreur
            case 5 : afficherListe(list1); break;
            case 6 : Rechercher (table1);
            case 8 : break; //pour quitter
            default : break;
        }
    } while (choix != 8);
}
