#include <iostream>
#include <omp.h>

double f(double x) {
    return x * x * x;
}

int main() {

    srand(time(0));

    double a = rand() % 10;
    double b = a + 1.0 + rand() % 10;

    double h = 0.001;
    int n = (b - a) / h;
    double integral = 0.0;

    #pragma omp parallel for reduction(+:integral)
    for (int i = 0; i < n; i++) {

        double x = a + (i + 0.5) * h;
        integral += f(x) * h;
    }

    std::cout << integral << std::endl;
    return 0;
}
