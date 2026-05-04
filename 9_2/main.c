 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

#ifdef _WIN32
    #include<windows.h>
#endif

void produit(int x, int Tab[x][x],int Vect[x], int Result[x]) {

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            Tab[i][j] = rand()%10;
        }
    }

    for (int i = 0; i < x; i++) {
            Vect[i]= rand()%10;
    }

    for (int i = 0; i < x; i++) {
        Result[i] = 0;
        for (int j = 0; j < x; j++) {
            Result[i] += Tab[i][j] * Vect[j];
        }

    }

}



int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);
    int setmatrice;

    printf("De quel taille voulez vous que votre matrice soit ?");
    scanf("%d",&setmatrice);

    int Tab[setmatrice][setmatrice];
    int Vect[setmatrice];
    int Result[setmatrice];

    produit(setmatrice,Tab,Vect,Result);

    for (int i = 0; i < setmatrice; i++) {
        printf(" %d\n", Result[i]);
    }

    
    return 0;
}