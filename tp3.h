#define Nmax 20

typedef struct Element {

char valeur[Nmax];
int*suiv;
int*prec;

}T_Element;

typedef struct Liste {

int taille;
int*tete;
int*queue;

}T_Liste;

T_Element *creerElement (char *val);
T_Element *creationElement() ;
T_Liste *creerListe();

