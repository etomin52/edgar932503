#include <iostream>
using namespace std;

const int Max_znach = 17;
const int Kolvo_znach = 18;

void pack(const int source[], int n, int packed[]) {
    for (int i = 0; i < Kolvo_znach; i++) packed[i] = 0;
    for (int i = 0; i < n; i++) packed[source[i]]++;
}

void unpack(const int packed[], int restored[], int n) {
    int index = 0;
    for (int val = 0; val < Kolvo_znach; val++) {
        for (int count = 0; count < packed[val]; count++) {
            restored[index++] = val;
        }
    }
}


int main() {
    const int N = 1000000;
    int* original = new int[N];

    int pos = 0;
    for (int val = 0; val <= Max_znach; val++) {
        int count = N / Kolvo_znach;

        if (val < N % Kolvo_znach) count++;
        for (int j = 0; j < count; j++) original[pos++] = val;
    }



    cout << "Ishod. massiv: " << N << " elementov, "
        << N * sizeof(int) << " bt" << endl;

    int packed[Kolvo_znach] = { 0 };
    pack(original, N, packed);

    cout << "Upakovano: " << Kolvo_znach << " elementov, "
        << Kolvo_znach * sizeof(int) << " bt" << endl;



    int* restored = new int[N];
    unpack(packed, restored, N);

    cout << "Raspakovano: " << N << " elementov, "
        << N * sizeof(int) << " bt" << endl;


    delete[] original;
    delete[] restored;

    return 0;
}