#include <stdio.h>

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    int s[20];
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

    int l, d;
    for( int i = 0 ; i < q ; i++ ){
        scanf("%d%d", &l, &d);
        l--;
        int currInd = s[l];
        if( currInd > 0 ){
            while ( currInd > 0 && d > 0 )
            {
                d -= g[l][currInd-1];
                c[l] -= g[l][currInd-1];
                currInd--;
            }
            s[l] = currInd;
            printf("%d\n", c[l]);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
