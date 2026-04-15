#include <stdio.h>
#include <windows.h>

int main(void) {
    SetConsoleOutputCP(65001);
    int nombres;
    printf("Entrez un nombre compris entre [5;15] ou égal à 20\n");
    scanf("%d", &nombres);
    while (!((nombres>=5 && nombres<=15)|| nombres == 20)) {
        printf("Erreur : le nombre saisi ne respecte pas les conditions spécifié, veuillez réessayer.\n");
        printf("Entrez un nombre compris entre [5;15] ou égal à 20\n");
        scanf("%d", &nombres);
    }
    printf("Bravo vous savez compter\n");
    return 0;
}