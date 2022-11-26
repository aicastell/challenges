#include <stdio.h>
#include <string.h>

int main(void)
{
    int T, N;
    char B[40000]; // len(B) = len(A) = 40000
    char X[80000]; // X = A+B, len(X) = 80000
    char C[80000]; // len(C) = len(A) + len(B)

    int alphabet[256]; // ASCII

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%s %s", X, B);
        strcat(X, B);

        // count number of each char in alphabet
        memset(alphabet, 0, sizeof(alphabet));
        for (int j=0; X[j]; j++) {
            alphabet[X[j]]++;
        }

        scanf("%d", &N);

        int permutes = 1;
        for (int child = 0; (child < N); child++) {
            scanf("%s", C);
            for (int j=0; C[j] && (permutes); j++) {
                if (alphabet[C[j]] > 0) {
                    alphabet[C[j]]--;
                } else {
                    permutes = 0;
                }
            }
        }

        // print solution
        (permutes) ? printf("YES\n") : printf("NO\n");
    }
}

