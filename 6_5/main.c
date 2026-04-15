# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#ifdef _WIN32
# include <windows.h>
#endif

int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);

    char tab[10] = {'B','O','N','J','O','U','R'};
    for (int i = 0; i < 10; i++) {
        printf("%c", tab[i]);
    }
    return 0;
}