#include <stdio.h>
#include <math.h>

#define N_E12 12

int main() {
    double E12[N_E12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

    double R_target;
    printf("Entrez une resistance (Ohm) : ");
    scanf("%lf", &R_target);

    // On ramène R dans la décade 1–10
    int decade = 0;
    double R_norm = R_target;

    while (R_norm >= 10.0) {
        R_norm /= 10.0;
        decade++;
    }
    while (R_norm < 1.0) {
        R_norm *= 10.0;
        decade--;
    }

    // Chercher la valeur E12 la plus proche
    double best = E12[0];
    double min_diff = fabs(R_norm - E12[0]);

    for (int i = 1; i < N_E12; i++) {
        double diff = fabs(R_norm - E12[i]);
        if (diff < min_diff) {
            min_diff = diff;
            best = E12[i];
        }
    }

    // Retour à l'échelle originale
    double R_final = best * pow(10, decade);

    printf("Resistance cible       : %.2f Ohm\n", R_target);
    printf("Resistance normalisee  : %.2f Ohm\n", R_final);

    return 0;
}
