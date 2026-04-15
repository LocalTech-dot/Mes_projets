#include <stdio.h>


int main() {

                           //Controle d'Aquisition pour un Oui ou NON//

    /*
    char rep;

    do {
        printf("Voulez vous rejouer ? O/N\n");
        scanf(" %c",&rep);
        if (rep != 'o'&& rep != 'n' && rep != 'O' && rep != 'N') {
            printf("Veuillez écrire o ou n\n");
        }
    }while (rep != 'o'&& rep != 'n' && rep != 'O' && rep != 'N');

    if (rep == 'n'|| rep == 'N') {
        printf("Fin du programme.");
        return 0;
    }

    printf("c'est parti");
    */

                           //Controle d'Aquisition pour un Entier Positif//


    /*
    int rep;
    int scan;

    do {
        printf("Veuillez entrer un nombre entier positif\n");
        scan = scanf("%d", &rep);

        if (scan == 0) {
            printf("Erreur, veuillez entrer un nombre entier\n");
            while (getchar() != '\n');
        }
        else if (rep < 0) {
            printf("Erreur, veuillez entrer un nombre positif\n");
        }

    }while (scan == 0 || rep < 0);

    printf("c'est bien vous êtes aller à l'école\n");
    */

    return 0;
}