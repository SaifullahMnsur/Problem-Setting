#include <stdio.h>
#include <stdlib.h>

int compare_function(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int t;
    scanf("%d", &t);

    while( t-- ){
        int n;
        scanf("%d", &n);
        int a[n];
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d", &a[i]);
        }

        qsort(a, n, sizeof(int), compare_function);

        for( int i = 0 ; i < n ; i++ ){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
