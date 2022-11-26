#include <stdio.h>

void get_array(int *v, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        scanf("%d", &v[i]);
    }
}

int get_max(int *v1, int *v2, int len)
{
    int i;
    int max = v1[0];
    for (i = 0; i < len; i++) {
        if (v1[i] > max)
            max = v1[i];
        if (v2[i] > max)
            max = v2[i];
    }
    return max;
}

int get_min(int *v1, int *v2, int len)
{
    int i;
    int min = v1[0];
    for (i = 0; i < len; i++) {
        if (v1[i] < min)
            min = v1[i];
        if (v2[i] < min)
            min = v2[i];
    }
    return min;
}

int main(void)
{
    int i, j;
    int T, N;

    scanf("%d", &T);

    for(i = 0; i < T; i++) {
        scanf("%d", &N);

        int arrival[N];
        int departure[N];

        get_array(arrival, N);
        get_array(departure, N);

        int min = get_min(arrival, departure, N);
        int max = get_max(arrival, departure, N);

        int test;
        int max_concurrent = 0;
        int concurrent;

        for (test = min; test <= max; test++) {
            concurrent = 0;
            for (j = 0; j < N; j++) {
                if ((test >= arrival[j]) && (test < departure[j]))
                    concurrent++;
            }
            if (concurrent > max_concurrent)
                max_concurrent = concurrent;
        }

        printf("%d\n", max_concurrent);
        max_concurrent = 0;

    }
}

