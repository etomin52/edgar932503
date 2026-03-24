#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// вывод лоб
void print_doska(const vector<vector<int>>& doska, int k) {
    for (int i = 0; i < k; ++i, cout << endl)
        for (int j = 0; j < k; ++j)
            if (doska[i][j] == 1) cout << "Q ";  // проверяет 0 1 1-ферзь 0- точка
            else cout << ". ";
    cout << endl;
}

//  вывод алг кост 
void print_doska(const vector<int>& doska_kost, int k) {
    for (int i = 0; i < k; ++i, cout << endl)   
        for (int j = 0; j < k; ++j)
            if (doska_kost[i] == j) cout << "Q "; // равнивает номер строки с текущим столбцом если совпало- ферзь
            else cout << ". ";
    cout << endl;
}

//  проверка  лоб
bool proverka_v_lob(const vector<vector<int>>& doska, int strok, int stolb, int razmer) {
    for (int i = 1; i <= strok; ++i) {
        if (doska[strok - i][stolb] == 1) return false; // вертикаль
        if (stolb - i >= 0 && doska[strok - i][stolb - i] == 1) return false; // с лева вверх 
        if (stolb + i < razmer && doska[strok - i][stolb + i] == 1) return false; // справа вверх 
    }
    return true;
}

//  рек лоб 
void v_lob(vector<vector<int>>& doska, int strok, int razmer, int& countl) {
    if (strok == razmer) {
        countl++;
        if (razmer <= 20) print_doska(doska, razmer);
        return;
    }
    for (int stolb = 0; stolb < razmer; ++stolb) {
        if (proverka_v_lob(doska, strok, stolb, razmer)) {
            doska[strok][stolb] = 1;
            v_lob(doska, strok + 1, razmer, countl);
            doska[strok][stolb] = 0; // бектрекинг 
        }
    }
}


//  проверка алг кост 
bool proverka_kost(const vector<int>& doska_kost, int strok, int stolb) {
    for (int i = 0; i < strok; ++i) {
        if (doska_kost[i] == stolb) return false; //проверка вертикали, не может быть 2 однаковых значения в массиве
        if (abs(doska_kost[i] - stolb) == strok - i) return false; //диагональ айди ферзя 
    }
    return true;
}

// рек алг кост 
void kost(vector<int>& doska_kost, int strok, int razmer, int& count_kost) {
    if (strok == razmer) {
        count_kost++;
        if (razmer <= 20) print_doska(doska_kost, razmer);
        return;
    }
    for (int stolb = 0; stolb < razmer; ++stolb) {
        if (proverka_kost(doska_kost, strok, stolb)) {
            doska_kost[strok] = stolb;
            kost(doska_kost, strok + 1, razmer, count_kost); // бектрекинг скрытый в рекурсии, он перезаписывает число удаляя старый элемент 
        }
    }
}

int main() {
    int razmer;
    cout << "Vvedite chislo: ";
    cin >> razmer;
    if (razmer <= 0) return 0;

    vector<vector<int>> doska(razmer, vector<int>(razmer, 0));
    vector<int> doska_kost(razmer, 0);

    int countl = 0, count_kost = 0;

    // время лоб
    auto start_lob = high_resolution_clock::now();
    v_lob(doska, 0, razmer, countl);
    auto end_lob = high_resolution_clock::now();
    auto time_lob = duration<double, milli>(end_lob - start_lob).count();

    // время алг кост 
    auto start_kost = high_resolution_clock::now();
    kost(doska_kost, 0, razmer, count_kost);
    auto end_kost = high_resolution_clock::now();
    auto time_kost = duration<double, milli>(end_kost - start_kost).count();

    // вывод времени
    cout << "Sposob 1 : " << time_lob << " ms" << endl;
    cout << "Sposob 2 : " << time_kost << " ms" << endl;

    if (time_lob > time_kost) {
        cout << "Sposob 2 bystree na " << (time_lob - time_kost) << " ms" << endl;
    }
    else if (time_kost > time_lob) {
        cout << "Sposob 1 bystree na " << (time_kost - time_lob) << " ms" << endl;
    }
    else {
        cout << "Vremya odinakovoe" << endl;
    }

    return 0;
}