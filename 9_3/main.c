#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#ifdef _WIN32
#include <windows.h>
#endif

void init_matrice(int n, int Tab[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Tab[i][j] = 0;
        }
    }
}

void placement(int)

int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);

    
    return 0;
}