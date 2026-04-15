#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void) {
    SetConsoleOutputCP(65001); // Pour les accents
    srand(time(NULL));
    int niveau = 1;
    int suite[100];
    int repuser, i;

    char s;
    do {
        printf("Voulez vous commencer une partie ?\n");
        scanf(" %c", &s);
        if (s != 'o'&& s != 'n') {
            printf("Erreur, veuiller entrer 'o' pour oui ou 'n' pour non\n");
        }
        else if (s == 'n') {
            return 0;
        }
    }while (s != 'o' && s != 'n');

    Debut_jeux :
    printf("\n--- NIVEAU %d ---\n", niveau);


    for (i = 0; i < niveau + 2; i++) {
        suite[i] = rand() % 10;
        printf("%d ", suite[i]);
    }
    printf("\n");


    Sleep(3000);


    system("cls");


    printf("Entrez la suite : ");
    int correct = 1;
    for (i = 0; i < niveau + 2; i++) {
        if (scanf("%d", &repuser) != 1) break;
        if (repuser != suite[i]) {
            correct = 0;
            break;
        }
    }

    if (correct) {
        printf("bravo le kho bendero !\n");
        niveau++;
        goto Debut_jeux;

    }
    else {
        printf("perdu sale jnoun Le score final est : %d\n", niveau);
    }
    Sleep(3000);
    return 0;
}