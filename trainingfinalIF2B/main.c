#include <stdio.h>
char* placend(char *tab) {
    int mot = 0;
    while (mot == 0 && *tab != '\0') {
        if ( *tab == ' ' ) {
            *tab =  '\0';
            mot = 1;
            tab++;
        }else {
            tab++;
        }
    }
    return tab;
}

int count(const char *tab) {
    int count = 0;
    int mot = 0;
    while (*tab != '\0') {
        if ( *tab != ' ' && *tab != '\t'  && *tab != '\n' ) {
            if (mot == 0) {
                mot = 1;
                count++;
            }
        }else {
            mot = 0;
        }
        tab++;
    }
    return count;
}

void token() {
    char resp[100];
    printf("Veuillez entrez une phrase\n");
    scanf("%s",resp);
    int n = count(resp);
    for (int i = 0; i < n; i++) {
        printf("%s\n",placend(resp));
    }

}