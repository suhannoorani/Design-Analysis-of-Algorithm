#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char a[101], b[101];
    int dp[101][101];
    int m, n, i, j;

    printf("Enter first string: ");
    scanf("%100s", a);

    printf("Enter second string: ");
    scanf("%100s", b);

    m = strlen(a);
    n = strlen(b);

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
        }
    }

    printf("Length of LCS = %d\n", dp[m][n]);

    return 0;
}