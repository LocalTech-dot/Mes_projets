#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void décalage(int decalage, int tableau[], int taille) {
    int temp[taille];
    int vrai_decalage = decalage%taille; //sécurité au cas où l'utilisateur est complètement con et décale de plus de 10
    if (vrai_decalage < 0) {
        vrai_decalage += taille;
    }
    for (int i = 0; i < taille; i++) {
        int nouvelle_position = (i+vrai_decalage)%taille;
        temp[nouvelle_position] = tableau[i];
    }
    for (int i = 0; i < taille; i++) {
        tableau[i] = temp[i];
    }
}

void génération(int tableau[], int taille, int maximum) {
    for (int i = 0; i < taille; i++) {
        tableau[i] = rand()%maximum;
    }
}

void affichage(int tableau[], int taille, int minimum, int maximum) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
}
int main(void) {
    SetConsoleOutputCP(65001);
    srand(time(NULL));

    int min = 0;
    int max = 10;
    int taille = 10;
    int tab[taille];
    int decalage;

    génération(tab, taille, max);
    affichage(tab, taille, min, max);
    printf("De Combien voulez vous décaler le tableau ?\n");
    scanf("%d", &decalage);
    décalage(decalage, tab, taille);
    affichage(tab, taille, min, max);



    return 0;
}
