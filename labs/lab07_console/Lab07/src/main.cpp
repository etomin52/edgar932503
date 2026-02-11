#include <iostream>
#include <cmath>

double f(double x) {
    return sin(x) / x;
}

int main() {
    double x0;
    std::cin >> x0;

    if (x0 <= 0 || x0 > 4) {
        std::cout << "error\n";
        return 1;
    }

    const int N_POINTS = 10;
    const double x_end = 4.0;
    double step = (x_end - x0) / (N_POINTS - 1);

    for (int i = 0; i < N_POINTS; ++i) {
        double x = x0 + i * step;
        std::cout << "x = " << x << ", f(x) = " << f(x) << "\n";
    }

    long long max_value;
    std::cin >> max_value;

    if (max_value < 0) {
        std::cout << "0 0\n";
        return 0;
    }

    long long a = 0, b = 1;
    long long S = 0;
    int N = 0;

    while (S + a <= max_value) {
        S += a;
        N++;
        long long temp = a + b;
        a = b;
        b = temp;
    }

    std::cout << N << " " << S << "\n";

    return 0;
}