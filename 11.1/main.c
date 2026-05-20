# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#ifdef _WIN32
# include <windows.h>
#endif

int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);

    
    return 0;
}