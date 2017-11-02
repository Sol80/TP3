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
    l->q=NULL;
    l->t=NULL;
    return l;
}


T_Element *creationElement() {
    printf("donner le nom de l element\n");
    char val[Nmax];
    T_Element *el1;
    //gets(val);
    scanf("%s",&val);
    el1=creerElement (val);
    printf("Element : le nom est %s, valeur precedent %d, valeur suivant %d \n",el1->valeur,el1->prec, el1->suiv);

}

void afficherListe(T_Liste *l)
{
    T_Element *en_cours = l->t;
    while(en_cours!=NULL)
    {
        printf("%s \t", en_cours->valeur);
        en_cours = en_cours->suiv;
    }
}


int insererElement(T_Liste *liste){
    T_Element *nv_elem;
    T_Element *en_cours, *precedent;
    en_cours=liste->t;
    precedent = NULL;

    nv_elem=creationElement();
    if (liste->taille==0)
    {
        liste->taille=1;
        liste->t = nv_elem;
        liste->q = nv_elem;
        return 0;
    }
    else {
        int i;
        for (i=0;i<liste->taille;i++) {
            if (en_cours!=NULL && strcmp(nv_elem->valeur,en_cours->valeur)==0)
                //L'élément existe déjà
                return -1;
            else {
                if (en_cours!=NULL && strcmp(nv_elem->valeur,en_cours->valeur)==-1){
                    //on vient tout juste de dépasser l'élément voulu
                    //On ajoute entre en_cours et precedent
                    //Si precedent = NULL => tête de liste
                    if(precedent == NULL)
                    {
                        nv_elem->suiv = en_cours;
                        liste->t=nv_elem;
                        en_cours->prec = nv_elem;
                    }
                    //Sinon entre les deux
                    else
                    {
                        nv_elem->suiv = en_cours;
                        en_cours->prec = nv_elem;
                        precedent->suiv = nv_elem;
                        nv_elem->prec = precedent;
                    }
                    liste->taille++;
                    return 0;
                }
                else{
                    //On a pas encore trouvé la place donc on avance
                    precedent = en_cours;
                    en_cours = en_cours->suiv;
                }
            }
        }
    }
    if(precedent == liste->q) //insertion en fin de liste /!\Mise à jour des attributs de liste
    {
        nv_elem->prec = precedent;
        precedent->suiv = nv_elem;
        liste->q = nv_elem;
        liste->taille++;
        return 0;
    }
}

T_Element *rechercherElement (T_Liste * list, char * val){
    int n,i;
    T_Element *elem_courant;
    n=list->taille;
    elem_courant=list->t;
    for (i=0;i<n;i++){
        if (strcmp(elem_courant->valeur,val)!=0)
            elem_courant=elem_courant->suiv;
        else return elem_courant;
    }
}

void Rechercher (){ //pour afficher les questions avant la recherche et le resultat de la recherche
    char val_elem,nom_liste;
    T_Element *elem1;
    printf("Donner le nom de l element rechercher\n");
    scanf("%s",&val_elem);
    printf("Donner le nom de la liste dans laquelle rechercher\n");
    scanf("%s",&nom_liste);
    elem1=rechercherElement (nom_liste,val_elem);
    printf("nom de l element : %s\n",elem1->valeur);
}

