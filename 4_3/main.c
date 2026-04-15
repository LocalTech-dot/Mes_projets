#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void) {
    SetConsoleOutputCP(65001);
    srand(time(0));
    char s;
    do {
        printf("Voulez-vous lancer une partie ? (o/n) :\n");
        scanf(" %c", &s);
        if (s != 'o' && s != 'n') {
            printf("Erreur, Veuillez saisir exclusivement 'o' ou 'n'.\n");
        }
    } while (s != 'o' && s != 'n');

    if (s == 'n') {
        printf("Le programme s'arrete ici. Au revoir.\n");
        return 0;
    }
    Debut_jeux :
    int nb = rand()%5 + 17;
    int tour = 0;
    int priseusr ;
    int priseia ;

    do {
        if (nb > 0) {
            printf("Il y a  %d batonnets sur la table\n", nb);
            if (tour == 0) {
                do {
                    printf("Combien de batonnet voulez vous tirez, veuillez choisir un nombre entre 1 et 3\n");
                    scanf(" %d", &priseusr);

                    if (priseusr<1 || priseusr>3|| priseusr>nb) {
                        printf("Action impossible car il reste %d batonnets", nb);
                    }
                }while (!(priseusr>=1 && priseusr<=3)|| priseusr>nb);
                nb = nb - priseusr;
                if (nb == 0) {
                    printf("Vous avez perdu\n");
                    break;
                }
                tour = 1 - tour;
            }
            else if (tour == 1) {
                priseia = rand()%3 + 1;
                printf("L'ordinateur prend %d batonnets\n", priseia);
                nb = nb - priseia;
                if (nb == 0) {
                    printf("Vous avez Gagner, l'ordinateur à pris le dernier batonnets\n");
                    break;
                }
                tour = 1 - tour;
            }
        }
    }while (nb >0);

    do {
        printf("Voulez-vous relancer une partie ? (o/n) : ");
        scanf(" %c", &s);
        if (s != 'o' && s != 'n') {
            printf("Erreur, Veuillez saisir exclusivement 'o' ou 'n'.\n");
        }
    } while (s != 'o' && s != 'n');

    if (s == 'o') {
        goto Debut_jeux;
    }
    return 0;
}