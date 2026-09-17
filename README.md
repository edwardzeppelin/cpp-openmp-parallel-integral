# OpenMP Numerical Integration in C++

A C++ program demonstrating parallel numerical integration of polynomial functions using OpenMP parallelization and reduction.

## Overview

This project implements numerical integration using the Midpoint Riemann Sum rule. To accelerate computation, the integration loop is parallelized across available CPU threads using OpenMP (`#pragma omp parallel for reduction(+:integral)`).

### Key Details
* **Target Function**: $f(x) = x^3$
* **Numerical Method**: Midpoint Rule with step size $h = 0.001$
* **Parallelization Technique**: OpenMP parallel `for` loop with scalar reduction
* **Interval Bounds**: Randomly generated interval $[a, b]$ at runtime

## Project Structure

* `main.cpp` — Primary implementation using `#pragma omp parallel for reduction(+:integral)` for efficient parallel sum reduction.

## Build & Execution

### Prerequisites
* GCC / Clang / MSVC compiler with OpenMP support.

### Compilation (GCC/Linux/macOS)
Compile with the `-fopenmp` flag to enable OpenMP parallel processing:

```bash
g++ -O2 -fopenmp main.cpp -o openmp_integral
```
