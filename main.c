#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M_PI 3.14159265358979323846

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: ./main <r> <n_steps>\n");
        return 1;
    }

    srand(time(NULL));

    double r = atof(argv[1]);
    unsigned long n_steps = strtoul(argv[2], NULL, 10);

    double volume = 1.33333333333 * M_PI * r*r*r;

    printf("[Analytical] sphere volume = %lf\n", volume);


    double r2 = r*r;

    unsigned long hit = 0;

    double x, y, z;
    for (unsigned long i = 0; i < n_steps; ++i) {
        x = ((double)rand() / RAND_MAX) * r;
        y = ((double)rand() / RAND_MAX) * r;
        z = ((double)rand() / RAND_MAX) * r;

        hit += (x*x + y*y + z*z) < r2;
    }

    double mc_volume = (double)hit / n_steps * r*r*r * 8;

    printf("[Monte Carlo] sphere volume = %lf\n", mc_volume);

    return 0;
}