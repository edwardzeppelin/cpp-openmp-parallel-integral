/*

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

    omp_set_num_threads(28);

    #pragma omp parallel
    {
        #pragma omp critical
        {
            std::cout << "Thread " << omp_get_thread_num() << " of " << omp_get_num_threads() << std::endl;
        }
        double local_integral = 0.0;
        #pragma omp for
            for (int i = 0; i < n; i++) {
                double x = a + (i + 0.5) * h;
                local_integral += f(x) * h;
            }
            #pragma omp critical
            integral += local_integral;

    }

    std::cout << integral << std::endl;
    return 0;
}*/

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