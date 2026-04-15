#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

    int test;
    srand(time(0));
    do {
        int numalea = rand()%1000;
        int numuser, tentatives = 1;
        printf("Le numéro à bien été généré, vous avez désormais 7 tentatives\n");
        printf("Veuillez entrer un numéro :\n");
        scanf("%d", &numuser);
        while ((numuser != numalea)&&(tentatives<7)) {
            tentatives ++;
            if (numuser < numalea) {
                printf("C'est plus\n");
                printf("Veuillez entrer un numéro :\n");
                scanf("%d", &numuser);
            }
            else if (numuser > numalea) {
                printf("C'est moins\n");
                printf("Veuillez entrer un numéro :\n");
                scanf("%d", &numuser);
            }

        }
        if (numuser == numalea) {
            printf("Vous avez le bon numéro ! Mais vous n'avez rien gagner de plus.");
        }
        else {
            printf("Perdu !");
        }

        printf("Voulez vous rejouer ? 1 pour Oui; 0 pour Non...\n");
        scanf("%d", &test);

    }
    while (test == 1);

    return 0;
}