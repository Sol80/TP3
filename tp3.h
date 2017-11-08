#define Nmax 20
#define Mmax 100

typedef struct Element {
    char valeur[Nmax];
    struct Element*suiv;
    struct Element*prec;
}T_Element;

typedef struct Liste {
    int taille;
    T_Element*t;
    T_Element*q;
}T_Liste;

typedef struct TabListe {
    char nom_liste[Nmax];
    T_Liste *liste;
}TabListe;

typedef struct Table {
    TabListe *Tableau[Mmax];
}Table;

T_Element *creerElement (char *val);
T_Element *creationElement() ;
T_Liste *creerListe();
TabListe *creationListe();
int insererElement(T_Liste *list);
void afficherListe(T_Liste *l);
T_Element *rechercherElement (T_Liste * list, char * val);
void Rechercher (Table *table1);
int supprimerElement (T_Liste * list,char * val);
void suppressionElement (Table *table1);
int supprimerListe (T_Liste * list);
void suppressionListe (Table *table1);
