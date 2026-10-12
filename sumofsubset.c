#include <stdio.h>

int a[100], n, target;

void subset(int i, int sum) {
    int j;

    if (sum == target) {
        printf("{ ");
        for (j = 0; j < i; j++)
            printf("%d ", a[j]);
        printf("}\n");
        return;
    }

    if (i == n || sum > target)
        return;

    subset(i + 1, sum + a[i]);
    subset(i + 1, sum);
}

int main() {
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter positive elements in increasing order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with target sum:\n");
    subset(0, 0);

    return 0;
}