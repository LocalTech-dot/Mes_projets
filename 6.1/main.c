#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tableau(int tab[], int taille, int min, int max) {
    for (int i = 0; i < taille; i++) {
        tab[i] = rand()%(max - min + 1) + min;
    }
}

void affichage(int tab[], int taille) {
    int compteurmin = 0;
    int compteurmax = 0;
    int minimum = tab[0];
    int maximum = tab[0];
    for (int i = 0; i < taille; i++) {

        if (tab[i] < minimum) {
            compteurmin = 1;
            minimum = tab[i];
        }
        else if (tab[i] == minimum) {
            compteurmin++;
        }
        if (tab[i] > maximum) {
            compteurmax = 1;
            maximum = tab[i];
        }
        else if (tab[i] == maximum) {
            compteurmax++;
        }
    }
    printf("La valeur minimal est %d, elle apparait %d fois\n" , minimum , compteurmin);
    printf("La valeur maximal est %d, elle apparait %d fois\n" , maximum , compteurmax);
}

void moyenne(int tab[], int taille) {
    float somme = 0;
    float moyenne;
    for (int i = 0; i < taille; i++) {
        somme = somme + tab[i];
    }
    moyenne = somme / taille;
    printf("La valeur moyenne est %.2f\n", moyenne);
}

int main(void) {
    srand(time(NULL));

    int taille = 50;
    int min = 0;
    int max = 20;
    int tab[taille];
    tableau(tab, taille, min, max);
    affichage(tab, taille);
    moyenne(tab, taille);

    return 0;d
}
