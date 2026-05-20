#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void) {

    FILE* fichier = fopen("../fichier.txt", "w");

    if (fichier != NULL) {

        char response[100];
        printf("Veuillez entrez un texte\n");
        fgets(response, 100, stdin);


        fprintf(fichier, "%s", response);
        fclose(fichier);

    }else {
        printf("Le fichier est introuvable");
    }
    return 0;
}