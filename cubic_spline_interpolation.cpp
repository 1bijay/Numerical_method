#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

double cubic_spline_interpolate(Point* points, int n, double x) {
    double a[n], b[n], c[n], d[n], h[n - 1], alpha[n - 1], l[n], mu[n], z[n];
    
    for (int i = 0; i < n; i++) {
        a[i] = points[i].y;
    }

    for (int i = 0; i < n - 1; i++) {
        h[i] = points[i + 1].x - points[i].x;
    }

    for (int i = 1; i < n - 1; i++) {
        alpha[i] = 3.0 * (a[i + 1] - a[i]) / h[i] - 3.0 * (a[i] - a[i - 1]) / h[i - 1];
    }

    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;

    for (int i = 1; i < n - 1; i++) {
        l[i] = 2.0 * (points[i + 1].x - points[i - 1].x) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1;
    z[n - 1] = 0;
    c[n - 1] = 0;

    for (int j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
    }

    int j = 0;
    while (j < n && x > points[j].x) j++;
    if (j >= n) j = n - 1;
    else if (j > 0 && x - points[j - 1].x < points[j].x - x) j--;
    double dx = x - points[j].x;
    return a[j] + (b[j] + (c[j] + d[j] * dx) * dx) * dx;
}

int main() {
    Point points[] = {{0, 0}, {1, 1}, {2, 4}, {3, 9}, {4, 16}};
    int n = sizeof(points) / sizeof(points[0]);

    printf("Cubic Spline Interpolation:\n");
    printf("x\t\tInterpolated Value\n");
    for (double x = 0; x <= 4; x += 0.5) {
        printf("%.2f\t\t%.2f\n", x, cubic_spline_interpolate(points, n, x));
    }

    return 0;
}
