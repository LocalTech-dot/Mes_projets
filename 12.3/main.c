#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char source[100];
    char destinataire[100];
    printf("Quel est le chemin du fichier source ?");
    scanf("%d", source);
    printf("Quel est le chemin du fichier destinataire ?");
    scanf("%d", source);

    FILE *fichier = fopen(source, "r");
    return 0;
}