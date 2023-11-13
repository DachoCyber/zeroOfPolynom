#include <stdio.h>
#include <math.h>

double izracunaj_polinom(double koeficijenti[], int stepen, double x) {
    double rezultat = 0.0;
    for (int i = 0; i <= stepen; i++) {
        rezultat += koeficijenti[i] * pow(x, stepen - i);
    }
    return rezultat;
}

double nadji_nulu(double koeficijenti[], int stepen, int min, int max, double epsilon) {
    double korak = 1.0;

    while (korak > epsilon) {
        int promenio_znak = 0;

        for (int i = min; i <= max; i++) {
            double x1 = i;
            double x2 = i + 1;

            double y1 = izracunaj_polinom(koeficijenti, stepen, x1);
            double y2 = izracunaj_polinom(koeficijenti, stepen, x2);

            if (y1 * y2 < 0) {
                promenio_znak = 1;
                printf("Pronađena nula u intervalu (%.2f, %.2f)\n", x1, x2);
            }
        }

        if (!promenio_znak) {
            break;
        }

        korak /= 10.0;
    }

    return 0;
}

int main() {
    int stepen;
    printf("Unesite stepen polinoma: ");
    scanf("%d", &stepen);

    double koeficijenti[stepen + 1];
    printf("Unesite koeficijente polinoma (od najstarijeg do slobodnog clana):\n");
    for (int i = stepen; i >= 0; i--) {
        printf("Koeficijent za x^%d: ", i);
        scanf("%lf", &koeficijenti[i]);
    }

    int min, max;
    printf("Unesite interval [min, max] za pretragu nule (celi brojevi): ");
    scanf("%d %d", &min, &max);

    double epsilon;
    printf("Unesite vrednost epsilon: ");
    scanf("%lf", &epsilon);

    nadji_nulu(koeficijenti, stepen, min, max, epsilon);

    return 0;
}

