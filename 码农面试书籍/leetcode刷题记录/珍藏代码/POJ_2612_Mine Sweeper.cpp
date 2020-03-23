#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
using namespace std;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        getchar();
        int i, j;
        char **g = (char **)malloc(sizeof(char*)*(n + 2));
        char **t = (char **)malloc(sizeof(char*)*(n + 2));
        char **shuchu = (char**)malloc(sizeof(char*)*(n + 2));
        for (i = 0; i < (n + 2); i++) {
            g[i] = (char *)malloc(sizeof(char)*(n + 2));
        }
        for (i = 0; i < (n + 2); i++) {
            t[i] = (char *)malloc(sizeof(char)*(n + 2));
        }
        for (i = 0; i < n + 2; i++) {
            shuchu[i] = (char *)malloc(sizeof(char)*(n + 2));
        }
        for (i = 0; i < (n + 2); i++) {
            for (j = 0; j < (n + 2); j++) {
                g[i][j] = '0';
            }
        }
        for (i = 0; i < (n + 2); i++) {
            for (j = 0; j < (n + 2); j++) {
                t[i][j] = '0';
            }
        }
        for (i = 0; i < n + 2; i++) {
            for (j = 0; j < n + 2; j++) {
                shuchu[i][j] = '.';
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%c", &g[i][j]);
            }
            scanf("%*c");
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%c", &t[i][j]);
            }
            scanf("%*c");
        }


        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {

                if (t[i][j] == 'x') {
                    shuchu[i][j] = 48;
                    if (g[i][j] == '.') {
                        if (g[i][j - 1] == '*') shuchu[i][j]++;
                        if (g[i - 1][j - 1] == '*') shuchu[i][j]++;
                        if (g[i - 1][j] == '*') shuchu[i][j]++;
                        if (g[i - 1][j + 1] == '*') shuchu[i][j]++;
                        if (g[i][j + 1] == '*') shuchu[i][j]++;
                        if (g[i + 1][j + 1] == '*') shuchu[i][j]++;
                        if (g[i + 1][j] == '*') shuchu[i][j]++;
                        if (g[i + 1][j - 1] == '*') shuchu[i][j]++;
                    }
                    if (g[i][j] == '*') {
                        shuchu[i][j] = '*';
                        int p, q;
                        for (p = 1; p <= n; p++) {
                            for (q = 1; q <= n; q++) {
                                if (shuchu[p][q] == '.') shuchu[p][q] = g[p][q];

                            }
                        }

                    }
                }

            }

        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                printf("%c", shuchu[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
