#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


T_Element *creerElement (char *val) {

T_Element *el;
el=malloc(sizeof(T_Element));
if (el==NULL)
    return NULL;
strcpy (el->valeur,val);
el->suiv=NULL;
el->prec=NULL;
return el;

}

T_Liste *creerListe() {

T_Liste *l;
l=malloc(sizeof(T_Liste));
if (l==NULL)
    return NULL;
l->taille=0;
l->queue=NULL;
l->tete=NULL;
return l;


}


T_Element *creationElement() {
    printf("donner le nom de l element\n");
    char val[Nmax];
    T_Element *el1;
    gets(val);
    el1=creerElement (val);
    printf("Element : le nom est %s, valeur precedent %d, valeur suivant %d \n",el1->valeur,el1->prec, el1->suiv);

}

int insererElement(T_Liste *list){
    T_Element *el1, *el2;
    el1=creationElement();
    if (list->taille==0)
    {
        list->taille=1;
        list->tete = el1;
        list->queue = el1;
        return 0;
    }
    else {
        int i;
        el2=list->tete;
        for (i=0;i<list->taille;i++) {
            if (strcmp(el1->valeur,el2->valeur)==0)
                return -1;
            else {
                if (strcmp(el1->valeur,el2->valeur)==-1){
                    el1->prec=el2->prec;
                    el1->suiv=el2;
                    el2->prec=el1;
                    el1->prec->suiv=el1;
                    list->taille++;
                    if (el1->prec==NULL)
                        list->tete=el1;
                    return 0
                }
                if (strcmp(el1->valeur,el2->valeur)==1){
                    el2=el2->suiv;
                    if (el2->suiv==NULL){
                        el2->suiv=el1;
                        el1->prec=el2;
                        list->queue=el1;
                        list->taille++;
                        return 0;
                    }
                }

            }



        }


    }




}




