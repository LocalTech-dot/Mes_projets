#include <stdio.h>
int test(int n) {
    for (int i = 2; i < n; i++) {
        int result = n%i;
        if (result == 0)
            return 1;
    }
    return 0;
}
int main(void) {
    int nombres;
    printf("Quel nombres voulez vous tester ? \n");
    scanf("%d", &nombres);

    if (test(nombres) == 1)
        printf("%d n'est pas un nombre premier",nombres);
    else
        printf("%d est un nombre premier",nombres);

    return 0;
}