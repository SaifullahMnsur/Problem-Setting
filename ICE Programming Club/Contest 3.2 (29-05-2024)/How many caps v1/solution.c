#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int s[21];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int g[20][150];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i]; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    int c[20] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i]; j++) {
            c[i] += g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", c[i]);
    }

    return 0;
}
