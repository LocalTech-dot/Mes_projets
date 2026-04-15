#include <stdio.h>
int test(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    int nombres;

    printf("Entrer un entier pair\n");
    scanf("%d", &nombres);

    while (test(nombres) == 0) {
        printf("Veuillez Entrer un entier pair\n");
        scanf("%d", &nombres);
    }
    printf("Votre nombre est bien pair");


    return 0;
}