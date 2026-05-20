#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char path[100];
    char insulte[30];
    char texte[256];
    int insulteTrouvee = 0;


    printf("Indiquez le chemin du fichier : ");
    scanf("%s", path);

    printf("Quelle est votre insulte preferee en portugais : ");
    scanf(" %29[^\n]", insulte);

    FILE* fichier = fopen(path, "r");

    if (fichier != NULL) {
        while (fgets(texte, sizeof(texte), fichier) != NULL) {
            if (strstr(texte, insulte) != NULL) {
                insulteTrouvee = 1;
            }
        }

        fclose(fichier);


        if (insulteTrouvee) {
            printf("Max %s\n", insulte);
        } else {
            printf("Desole, impossible d'insulter Max en portugais, Lucien ne connait pas encore cette insulte.\n");
        }

    } else {
        printf("Erreur : Le fichier '%s' est introuvable.\n", path);
    }

    return 0;
}