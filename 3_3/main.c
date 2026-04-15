#include <stdio.h>
void tables(int n) {

    for (int i = 1; i <= 10; i++) {
    int result = i * n;
        printf("%d * %d = %d\n",n,i, result);
    }
}
int main(void) {
    int nombres;
    printf("De quel nombres voulez vous obtenir la tables ?\n");
    scanf("%d",&nombres);

    tables(nombres);
    return 0;
}