#include <stdio.h>
#include <math.h>

#define N_E12 12

int main() {
    double E12[N_E12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

    double R_min;
    printf("Entrez la resistance minimale (Ohm) : ");
    scanf("%lf", &R_min);

    // Normalisation de R_min dans la décade 1–10
    int decade = 0;
    double R_norm = R_min;

    while (R_norm >= 10.0) {
        R_norm /= 10.0;
        decade++;
    }
    while (R_norm < 1.0) {
        R_norm *= 10.0;
        decade--;
    }

    // Recherche de la valeur immédiatement supérieure
    double best = E12[N_E12 - 1]; // valeur la plus haute par défaut

    for (int i = 0; i < N_E12; i++) {
        if (E12[i] >= R_norm) {
            best = E12[i];
            break;
        }
    }

    // Reconstruction de la valeur réelle
    double R_final = best * pow(10, decade);

    printf("Resistance minimale demandee : %.2f Ohm\n", R_min);
    printf("Resistance normalisee choisie : %.2f Ohm\n", R_final);

    return 0;
}

