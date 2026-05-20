 <stdio.h>
 <stdlib.h>
 <time.h>

#ifdef _WIN32
 <windows.h>
#endif

int main(void) {
    srand(time(NULL)); // Optionnel : initialisation du random
    
    return 0;
}