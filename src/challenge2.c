/*
The Greplin Programming Challenge
 
 Level 2
 
 ----------------------------------------

 Congratulations.  You have reached level 2.
 
 To get the password for level 3, write code to find the first prime
 fibonacci number larger than a given minimum.  For example, the first
 prime fibonacci number larger than 10 is 13.

 When you are ready, go here or call this automated
 number (415) 799-9454.
 
 You will receive additional instructions at that time.  For the second portion
 of this task, note that for the number 12 we consider the sum of the prime divisors
 to be 2 + 3 = 5.  We do not include 2 twice even though it divides 12 twice.
*/

#include <stdio.h>

int is_prime(unsigned long tested)
{
    unsigned long divisor;

    for (divisor = (tested / 2); divisor > 1; divisor--)
        if ((tested % divisor) == 0)
            return 0;

    return 1;
}

unsigned long next_fibonacci()
{
    static unsigned long a = 0;
    static unsigned long b = 1;
    unsigned long nf = a + b;

    a = b;
    b = nf;

    return nf;
}

unsigned long next_prime()
{
    static unsigned long prime = 0;
    unsigned long tested = prime + 1;

    while (1) {
        if (is_prime(tested)) {
            prime = tested;
            return prime;
        } else {
            tested++;
        }
    }
}

int main(void)
{
    unsigned long given_minimum = 227000;
    unsigned long X;

    while ((X = next_fibonacci()) < given_minimum)
        ;

    while (!is_prime(X))
        X = next_fibonacci();

    X += 1;

    int np = next_prime(); // 1

    int challenge2 = 0;

    while (X != 1) {
        np = next_prime();

        if ((X % np) == 0) {
            while ((X % np) == 0)
                X = X / np;
            challenge2 += np;
        }
    }

    printf("Solution to challenge 2 is %d\n", challenge2);
}

