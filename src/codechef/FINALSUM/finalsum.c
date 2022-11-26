#include <stdio.h>

int get_array(int *v, int len)
{
    int i;
    int sum = 0;

    for (i = 0; i < len; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }

    return sum;
}

int main(void)
{
    int i, j;
    int T;
    int N, Q;
    int sum;

    scanf("%d", &T);

    for(i = 0; i < T; i++) {
        scanf("%d %d", &N, &Q);

        int array[N];
        sum = get_array(array, N);

        int ini, end;
        for (j = 0; j < Q; j++) {
            scanf("%d %d", &ini, &end);
            if (((end - ini) % 2) == 0)
                sum++;
        }
        printf("%d\n", sum);
    }
}

