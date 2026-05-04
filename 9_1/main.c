#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#ifdef _WIN32
 #include <windows.h>
#endif

void calculdet(float Tab[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            Tab[i][j] = rand() % 10;
        }
    }
    int a, b, c, d;
    a = Tab[0][0];
    b = Tab[0][1];
    c = Tab[1][0];
    d = Tab[1][1];
    int det = a*d - b*c;
    printf("Le déterminant de la matrice est %d", det);
}

int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);
    float Matrice[2][2];
    calculdet(Matrice);
    
    return 0;
}