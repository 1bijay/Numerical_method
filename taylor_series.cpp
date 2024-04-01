#include <stdio.h>
#include <math.h>

double taylor_series_sin(double x, int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += pow(-1, i) * pow(x, 2 * i + 1) / tgamma(2 * i + 2);
    }
    return result;
}

int main() {
    double x;
    int n;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the number of terms (n): ");
    scanf("%d", &n);

    double sin_x = sin(x);
    double taylor_sin_x = taylor_series_sin(x, n);

    printf("Exact value of sin(%lf): %lf\n", x, sin_x);
    printf("Approximated value of sin(%lf) using Taylor series with %d terms: %lf\n", x, n, taylor_sin_x);

    return 0;
}
