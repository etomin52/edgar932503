#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

void printMatrix(double** a, int m, int n, ofstream& out) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1) out << "| ";
            out << setw(10) << fixed << setprecision(4) << a[i][j] << " ";
        }
        out << endl;
    }
}

int gaussJordan(double** a, int m, int n) {
    int rank = 0;
    for (int col = 0; col < n && rank < m; col++) {
        int maxRow = rank;
        for (int i = rank + 1; i < m; i++)
            if (abs(a[i][col]) > abs(a[maxRow][col])) maxRow = i;

        if (abs(a[maxRow][col]) < EPS) continue;
        swap(a[maxRow], a[rank]);

        double pivot = a[rank][col];
        for (int j = col; j <= n; j++) a[rank][j] /= pivot;

        for (int i = 0; i < m; i++) {
            if (i != rank && abs(a[i][col]) > EPS) {
                double factor = a[i][col];
                for (int j = col; j <= n; j++)
                    a[i][j] -= factor * a[rank][j];
            }
        }
        rank++;
    }
    return rank;
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream in("input.txt");
    ofstream out("output.txt");

    int M, N;
    in >> M >> N;

    //выд памяти 
    double** a = new double* [M];
    for (int i = 0; i < M; i++) {
        a[i] = new double[N + 1];
        for (int j = 0; j <= N; j++) in >> a[i][j];
    }

    out << "ISHODNAYA MATRICA:\n";
    printMatrix(a, M, N + 1, out);

    int rank = gaussJordan(a, M, N);

    out << "\nPRIVEDENNAYA MATRICA:\n";
    printMatrix(a, M, N + 1, out);
    out << "Rang: " << rank << ", Neizvestnyh: " << N << "\n\n";

    //проверка на несовмест
    bool noSolution = false;
    for (int i = rank; i < M; i++)
        if (abs(a[i][N]) > EPS) { noSolution = true; break; }

    if (noSolution) {
        out << "Sistema nesovmestna (net reshenij)\n";
    }
    else if (rank < N) {
        out << "Edinstvennogo reshenija net (rang matricy " << rank
            << " menshe kolichestva neizvestnyh " << N << ")\n";
    }
    else {
        out << "Edinstvennoe reshenie:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                if (abs(a[i][j]) > EPS) {
                    out << "x" << j + 1 << " = " << a[i][N] << endl;
                    break;
                }
        }
    }

    //освобож памяти 
    for (int i = 0; i < M; i++) delete[] a[i];
    delete[] a;

    cout << "Rezultat v output.txt\n";
    return 0;
}