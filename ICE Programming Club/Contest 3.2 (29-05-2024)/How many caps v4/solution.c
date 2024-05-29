#include <stdio.h>

int compare_function(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int s[20];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    int M[20];
    for( int i = 0 ; i < n; i++ ){
        scanf("%d", &M[i]);
    }

    int g[20][150];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i]; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    int c[20] = {0};

    for (int i = 0; i < n; i++) {
        qsort(g[i], s[i], sizeof(int), compare_function);
        for (int j = 0; j < M[i]; j++) {
            c[i] += g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", c[i]);
    }

    return 0;
}
