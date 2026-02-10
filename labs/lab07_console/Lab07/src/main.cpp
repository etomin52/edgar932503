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

    const int N = 10;
    const double x_end = 4.0;
    double step = (x_end - x0) / (N - 1);

    for (int i = 0; i < N; ++i) {
        double x = x0 + i * step;
        std::cout << "x = " << x << ", f(x) = " << f(x) << "\n";
    }

    return 0;
}