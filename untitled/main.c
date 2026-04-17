 <stdio.h>
 <stdlib.h>
 <time.h>

#ifdef _WIN32
 <windows.h>
#endif

int main(void) {
    srand(time(NULL));
    SetConsoleOutputCP(65001);

    
    return 0;
}