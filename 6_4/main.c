#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#endif


void decalage(int taille, int tab[]) {
    int i;
    int j = 0;
    for (i = 0; i < taille; i++) {
        if (tab[i] != 0) {
            tab[j] = tab[i];
            j++;
        }
    }
    for (j; j < taille; j++) {
        tab[j] = 0;
    }
}

void tirage(int taille, int tab[], int tirage) {
    int retire;
    for (int i = 0; i < tirage; i++) {
        retire = rand() % taille;
        tab[retire] = 0;
    }
}

void generation(int taille, int tab[]) {
    for (int i = 0; i < taille; i++) {
        tab[i] = i+1;
    }
}

void affichage(int taille, int tab[]) {
    for (int i = 0; i < taille; i++) {
        if (tab[i] != 0) {
            printf("%d\t", tab[i]);
        }
    }
    printf("\n");
}


int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);

    int taille = 49;
    int tab[taille];
    int boule_tiré = 6;
    generation(taille, tab);
    affichage(taille, tab);
    printf("Tirage des %d boules\n", boule_tiré);
    tirage(taille, tab, boule_tiré);
    decalage(taille, tab);
    affichage(taille, tab);


    return 0;
}