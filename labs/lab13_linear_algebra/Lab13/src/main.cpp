#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

//вывод матрицы
void printMatrix(double** a, int m, int n, ofstream& out) {
    out << setprecision(6);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1) out << "| ";
            out << setw(12) << fixed << a[i][j] << " ";
        }
        out << endl;
    }
}

int gaussTriangular(double** a, int m, int n) {
    int rank = 0;
    for (int col = 0; col < n && rank < m; col++) {
        int maxRow = rank; //поиск большего модуля 
        for (int i = rank + 1; i < m; i++)
            if (abs(a[i][col]) > abs(a[maxRow][col]))
                maxRow = i;

        if (abs(a[maxRow][col]) < EPS) continue;

        swap(a[maxRow], a[rank]);

        double pivot = a[rank][col]; //делим строчку на число 
        for (int j = col; j <= n; j++)
            a[rank][j] /= pivot;

        for (int i = rank + 1; i < m; i++) { //обнуление элементов ниже 
            if (abs(a[i][col]) > EPS) {
                double factor = a[i][col];
                for (int j = col; j <= n; j++)
                    a[i][j] -= factor * a[rank][j];
            }
        }
        rank++;
    }
    return rank;
}

int main() { //вход в мейн 
    ifstream in("input.txt"); //открываем файл для считвания
    ofstream out("output.txt"); //открываем файл для записи

    int M, N;
    in >> M >> N;

    double** a = new double* [M]; // выделение памяти под матрицу 
    for (int i = 0; i < M; i++) {
        a[i] = new double[N + 1];
        for (int j = 0; j <= N; j++)
            in >> a[i][j];
    }

    out << "ISHODNAYA MATRICA:\n";
    printMatrix(a, M, N + 1, out);

    int rank = gaussTriangular(a, M, N);

    out << "\nTREUGOLNAYA MATRICA:\n";
    printMatrix(a, M, N + 1, out);
    out << "\nRang: " << rank << ", Neizvestnyh: " << N << "\n\n";

    bool noSolution = false; // проверка несовместимость 
    for (int i = rank; i < M; i++)
        if (abs(a[i][N]) > EPS) {
            noSolution = true;
            break;
        }

    if (noSolution) {
        out << "net reshenij\n";
    }
    else if (rank < N) {
        out << "Edinstvennogo reshenija net (rang matricy " << rank
            << " menshe kolichestva neizvestnyh " << N << ")\n";
    }
    else {
        out << "Edinstvennoe reshenie:\n";
        double* x = new double[N]();

        // ищем позиции для вед эл
        int* leadCol = new int[rank];
        for (int i = 0; i < rank; i++) {
            leadCol[i] = -1;
            for (int j = 0; j < N; j++) {
                if (abs(a[i][j]) > EPS) {
                    leadCol[i] = j;
                    break;
                }
            }
        }

        // обр подстановка 
        for (int i = rank - 1; i >= 0; i--) {
            int col = leadCol[i];
            if (col == -1) continue;

            x[col] = a[i][N];
            for (int j = col + 1; j < N; j++) {
                x[col] -= a[i][j] * x[j];
            }
        }

        for (int i = 0; i < N; i++)
            out << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;

        delete[] x; //очистка массивов вспомогат. 
        delete[] leadCol;
    }

    for (int i = 0; i < M; i++)
        delete[] a[i]; // очистка матрицы
    delete[] a;

    cout << "Rezultat v output.txt\n";
    return 0;
}