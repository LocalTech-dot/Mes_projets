 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

#ifdef _WIN32
 #include <windows.h>
#endif

void genertab(int tab[],int taille) {
    for (int i = 0; i < taille; i++) {
        tab[i] = rand() % 10;
    }
}

void printtab(int tab[],int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void tribulle(int tab[], int taille) {
    int perm;
    int temp = 0;
    do {
        perm = 0;
        for (int i = 0; i < taille - 1; i++) {
            if (tab[i] > tab[i+1]) {
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                perm = 1;
            }
        }
    }while (perm == 1);
}
int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);
    int tab[100];
    genertab(tab,100);
    printtab(tab,100);
    tribulle(tab,100);
    printf("Trie en cours...\n");
    printtab(tab,100);

    
    return 0;
}