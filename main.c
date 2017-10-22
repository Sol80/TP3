#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"



int main()
{
    creationElement();
    T_Liste *l1;
    l1=creerListe();
    printf("Liste : la taille est %d, valeur tete %d, valeur queue %d \n",l1->taille,l1->tete, l1->queue);
    printf("Hello world!\n");
    return 0;
}
