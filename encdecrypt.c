#include <stdio.h>
#include <string.h>

int isPrime(int num) {
    if (num < 2)
        return 0;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

double calculateExponentiation(int base, int exponent) {
    double result = 1.0;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int calculateModulo(int dividend, int divisor) {
    while (dividend >= divisor) {
        dividend -= divisor;
    }

    return dividend;
}

void main() {
    int a, b, i, j, t, x, n, k = 0, flag = 0, prime[100];
    char m[20], pp[20];
    double e, d;
    float p[20], c[20];

    for (i = 0; i < 100; i++) {
        if (isPrime(i))
            prime[k++] = i;
    }

    a = prime[k - 1];
    b = prime[k - 2];
    n = a * b;
    t = (a - 1) * (b - 1);
    e = (double)prime[2];
    d = 1 / e;

    printf("\nKey of encryption is: %lf\n", d);
    printf("\nEnter the plaintext: ");
    scanf("%s", m);
    x = strlen(m);

    printf("\nDecryption status from Source to Destination:\n");
    printf("\nSource\t->----------------------------------<-destination\n");
    printf("\nChar\tnumeric\tcipher\t\tnumeric\t\tchar \n");
    printf("***********************************************************\n");

    for (i = 0; i < x; i++) {
        printf("%c\t%d", m[i], m[i] - 97);

        c[i] = calculateModulo(calculateExponentiation(m[i] - 97, e), n);
        printf("\t%f", c[i]);

        p[i] = calculateModulo(calculateExponentiation(c[i], d), n);
        printf("\t%f", p[i]);

        pp[i] = p[i] + 97;
        printf("\t%c\n", pp[i]);

        printf("***********************************************************\n");
    }
}
