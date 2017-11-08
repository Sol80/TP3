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

TabListe *creationListe(){
    char nom_list[Nmax];
    TabListe *tab1;
    tab1=malloc(sizeof(TabListe));
    T_Liste *list1;
    printf("donner le nom de la liste a creer\n");
    scanf("%s",&nom_list);
    list1 = creerListe();
    tab1->liste=list1;
    //tab1->nom_liste=nom_list;
    strcpy(tab1->nom_liste,nom_list);
    return tab1;
}

T_Element *creationElement() {
    printf("donner le nom de l element\n");
    char val[Nmax];
    T_Element *el1;
    //gets(val);
    scanf("%s",&val);
    el1=creerElement (val);
    //printf("Element : le nom est %s, valeur precedent %d, valeur suivant %d \n",el1->valeur,el1->prec, el1->suiv);
    return el1;
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
    int succes=0;
    T_Element *elem_courant;
    n=list->taille;
    elem_courant=list->t;
    for (i=0;i<n;i++){
        if (strcmp(elem_courant->valeur,val)!=0)
            elem_courant=elem_courant->suiv;
        else succes=1;
    }
    if (succes==1)
        return elem_courant;
    else { printf("l element recherche n est pas present dans la liste\n");
            return NULL; }
}

void Rechercher (Table *table1){ //pour afficher les questions avant la recherche et le resultat de la recherche

    char val_elem[Nmax],nom_liste1[Nmax],nom_en_cours[Nmax];
    T_Element *elem1;
    T_Liste *list1;
    TabListe *tablist1;
    int n;
    int i=0;
    int succes=-1;

    printf("Donner le nom de la liste dans laquelle rechercher\n");
    scanf("%s",&nom_liste1);
    printf("Donner le nom de l element a rechercher\n");
    scanf("%s",&val_elem);

    tablist1=table1->Tableau[0];
    strcpy(nom_en_cours,tablist1->nom_liste); //on recupere le nom de la premiere liste
    list1=tablist1->liste; //on recupere le pointeur sur la premiere liste
    n=sizeof(table1)/4; //la taille d un element du tableau vaut 4 donc on divise par 4 pour avoir le nombre d elements du tableau

    while (i<n){ //tant qu'on n'a pas parcouru tout le tableau on fait:

        if (strcmp(nom_en_cours,nom_liste1)!=0){ //si le nom de la liste du tableau est different de celui demande on fait:
            if (i<n-1){
                i++; //si on a pas atteint le dernier element, on prend l element suivant du tableau
                tablist1=table1->Tableau[i];
                strcpy(nom_en_cours,tablist1->nom_liste);
                list1=tablist1->liste;
            }else i++;
        }else {
        succes=i; //succes prend la valeur de i pour laquelle le nom de la liste de l element i du tableau est egale au nom de liste demande
        i=n; //i prend la valeur n pour que l'on sorte de la boucle
        }
    }

    if (succes!=-1){
        list1=table1->Tableau[succes]->liste;
        elem1=rechercherElement (list1,val_elem);
        printf("nom de l element : %s\n",elem1->valeur);
    } else printf("le nom de la liste n est pas correct\n");

    return 0;
}

int supprimerElement (T_Liste * list,char * val){
    T_Element * elem, * predecesseur, * successeur;
    elem = rechercherElement(list,val);
    if (elem != NULL){  //on execute la fonction si on a trouve l element a supprimer
        /*predecesseur=elem->prec; //on recupere un pointeur vers le predecesseur de l element a supprimer
        successeur=elem->suiv;  //on recupere un pointeur vers le successeur de l element a supprimer
        predecesseur->suiv = successeur; //on indique que le successeur de l element avant l element supprime est le successeur initial de l element supprime
        successeur->prec = predecesseur;*/  //on indique que le predecesseur de l element apres l element supprime est le predecesseur initial de l element supprime
        //elem->prec->suiv=elem->suiv;
        //elem->suiv->prec=elem->prec;
        free(elem);  //on libere l espace memoire aloue a l element supprime
        return 0;
    }
    else return -1; //si on a pas trouve l element on retourne une erreur => la suppression n a pas fonctionne
}

void suppressionElement (Table *table1){

    char val_elem[Nmax],nom_liste1[Nmax],nom_en_cours[Nmax];
    T_Element *elem1;
    T_Liste *list1;
    TabListe *tablist1;
    int n,resultat;
    int i=0;
    int succes=-1;

    printf("Donner le nom de la liste dans laquelle supprimer un element\n");
    scanf("%s",&nom_liste1);
    printf("Donner le nom de l element a supprimer\n");
    scanf("%s",&val_elem);

    tablist1=table1->Tableau[0];
    strcpy(nom_en_cours,tablist1->nom_liste); //on recupere le nom de la premiere liste
    list1=tablist1->liste; //on recupere le pointeur sur la premiere liste
    n=sizeof(table1)/4; //la taille d un element du tableau vaut 4 donc on divise par 4 pour avoir le nombre d elements du tableau

    while (i<n){ //tant qu'on n'a pas parcouru tout le tableau on fait:

        if (strcmp(nom_en_cours,nom_liste1)!=0){ //si le nom de la liste du tableau est different de celui demande on fait:
            if (i<n-1){
                i++; //si on a pas atteint le dernier element, on prend l element suivant du tableau
                tablist1=table1->Tableau[i];
                strcpy(nom_en_cours,tablist1->nom_liste);
                list1=tablist1->liste;
            }else i++;
        }else {
        succes=i; //succes prend la valeur de i pour laquelle le nom de la liste de l element i du tableau est egale au nom de liste demande
        i=n; //i prend la valeur n pour que l'on sorte de la boucle
        }
    }

    if (succes!=-1){
        list1=table1->Tableau[succes]->liste;
        resultat = supprimerElement (list1,val_elem);
        if (resultat == 0)
            printf("la suppression a bien ete realisee\n");
        else printf("echec de la suppression\n");
    } else printf("le nom de la liste n est pas correct\n");

    return 0;
}

int supprimerListe (T_Liste * list){
    int i,n,succes;
    n = list->taille;
    T_Element * elem;
    elem=list->t;
    for (i=0;i<n;i++){
        succes=supprimerElement(list,elem->valeur); //on supprime chaque element de la liste choisie
        if (succes != 0){
            printf("echec de la suppression\n");
            return -1; //si on n arrive pas a supprimer un element de la liste on retourne une erreur
        }
        if (i != n-1)
            elem=elem->suiv; //une fois l element supprime on prend le suivant si ce n est pas le dernier
    }
    free(list); //une fois tous les elements supprimes on libere l espace memoire de la liste supprimee
    return 0;
}

void suppressionListe (Table *table1){

    char nom_liste1[Nmax],nom_en_cours[Nmax];
    T_Liste *list1;
    TabListe *tablist1;
    int n,resultat;
    int i=0;
    int succes=-1;

    printf("Donner le nom de la liste dans laquelle supprimer un element\n");
    scanf("%s",&nom_liste1);

    tablist1=table1->Tableau[0];
    strcpy(nom_en_cours,tablist1->nom_liste); //on recupere le nom de la premiere liste
    list1=tablist1->liste; //on recupere le pointeur sur la premiere liste
    n=sizeof(table1)/4; //la taille d un element du tableau vaut 4 donc on divise par 4 pour avoir le nombre d elements du tableau


    while (i<n){ //tant qu'on n'a pas parcouru tout le tableau on fait:

        if (strcmp(nom_en_cours,nom_liste1)!=0){ //si le nom de la liste du tableau est different de celui demande on fait:
            if (i<n-1){
                i++; //si on a pas atteint le dernier element, on prend l element suivant du tableau
                tablist1=table1->Tableau[i];
                strcpy(nom_en_cours,tablist1->nom_liste);
                list1=tablist1->liste;
            }else i++;
        }else {
        succes=i; //succes prend la valeur de i pour laquelle le nom de la liste de l element i du tableau est egale au nom de liste demande
        i=n; //i prend la valeur n pour que l'on sorte de la boucle
        }
    }

    if (succes!=-1){
        list1=table1->Tableau[succes]->liste;
        resultat = supprimerListe(list1);
        if (resultat == 0)
            printf("la suppression a bien ete realisee\n");
        else printf("echec de la suppression\n");
    } else printf("le nom de la liste n est pas correct\n");

    return 0;
}
