#define Nmax 20

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

T_Element *creerElement (char *val);
T_Element *creationElement() ;
T_Liste *creerListe();
int insererElement(T_Liste *list);
void afficherListe(T_Liste *l);
T_Element *rechercherElement (T_Liste * list, char * val);
void Rechercher ();

