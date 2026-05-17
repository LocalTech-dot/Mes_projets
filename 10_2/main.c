#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#endif

void genertab(int tab[], int n) {
    for (int i = 0; i < n ; i++) {
        tab[i] = rand() % 100;
    }
}

void printtab(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void triselect(int tab[], int n) {
    int min_index, temp;

    for (int i = 0; i < n - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = tab[i];
            tab[i] = tab[min_index];
            tab[min_index] = temp;
        }
    }
}
int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);
    int tab[100];
    genertab(tab, 100);
    printtab(tab, 100);
    printf("Trie en cours...\n");
    triselect(tab, 100);
    printtab(tab, 100);


    return 0;
}