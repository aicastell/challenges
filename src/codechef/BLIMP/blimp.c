#include <stdio.h>

// returns max element in array
long get_array(long *v, int len)
{
    int i;
    long max = 0;

    for (i = 0; i < len; i++) {
        scanf("%ld", &v[i]);
        if (max < v[i])
            max = v[i];
    }

    return max;
}

int main(void)
{
    int T, N;
    long X, Y;

    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d %ld %ld", &N, &X, &Y);
        long max;
        long cities[N];
        long iter = 0;

        max = get_array(cities, N);

        if (Y >= X) {
            iter = (max + Y - 1) / Y;
        }
        else {
            for(int j = (N - 1); j>=0; j--){
                cities[j] = cities[j] - (iter * Y);
                if (cities[j] > 0) {
                    iter += (cities[j] + X - 1) / X;
                }
            }
        }

        printf("%ld\n", iter);
    }
}

