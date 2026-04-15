#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void recherche(int n, int t[n], int x) {
    int trouver = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == x) {
            printf("%d ", i+1);
            trouver = 1;
            break;
        }
        }
    if (trouver != 1) {
        printf("votre valeur n'est pas dans le tableau");
    }
}

void afficher(int n, int t[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", t[i]);
    }
    printf("\n\n");
}

void generation(int n, int t[n]) {
    for (int i = 0; i < n; i++) {
        t[i] = rand() % 100;
    }
}

int main(void) {
    srand(time(NULL));

    int taille = 100;
    int tab[taille];
    int x;
    generation(taille, tab);
    afficher(taille, tab);
    printf("Quel valeur voulez vous chercher dans le tableau ?\n");
    scanf("%d", &x);
    recherche(taille, tab, x);

    return 0;
}