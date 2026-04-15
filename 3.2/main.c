#include <stdio.h>
#include <windows.h>

long long Factoriel(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++)
        result = result*i;
    return result;
}

int main() {
    SetConsoleOutputCP(65001);
    int nombres;
    printf("Entrer un nombre compris entre 1 et 20 :\n");
    scanf("%d", &nombres);

    long long fact = Factoriel(nombres);
    printf("%d à pour factoriel %lld \n", nombres, fact);
    return 0;
}