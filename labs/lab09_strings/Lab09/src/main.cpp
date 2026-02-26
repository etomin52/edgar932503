#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstring>

using namespace std;

void task1() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char chr1[10] = "Hello ";
    char chr2[10] = "Artem";
    char result[20];

    strcpy_s(result, chr1); 
    cout << "strcpy_s(): " << result << "\n" << endl;

    strcat_s(result, chr2);
    cout << "strcat_s(): " << result << "\n" << endl;

    cout << "strlen(): " << strlen(result) << "\n" << endl;
    cout << "<<String>>" << "\n" << endl;

    string str1 = "Goodbye ";
    string str2 = "Artem";
    string StrResult;

    StrResult.append(str1);
    StrResult.append(str2);
    cout << "append(): " << StrResult << "\n" << endl;

    int N = StrResult.size();
    cout << "size(): " << N << "\n" << endl;

    StrResult.replace(8, 5, "Edgar");
    cout << "replace(): " << StrResult << "\n" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Задание 1" << "\n" << "<<Char>>" << endl;
    task1();

    int word_count = 0;
    cout << "Задание 4 < string > \n" << "Кол-во слов в массиве:" << endl;
    cin >> word_count;

    if ((word_count > 20) || (word_count <= 0)) {
        cout << "Кол-во должно быть 1 до 20 ";
        return 0;
    }

    vector<string> words;
    words.reserve(word_count);

    for (int i = 0; i < word_count; ) {
        string word;
        cout  << i + 1 << " слово: ";
        cin >> word;

        if (word.length() > 10) {
            cout << "Кол-во букв должно быть <=10" << endl;
        }
        else {
            words.push_back(word);
            i++;
        }
    }

    cout << "Вывод работы < string > :" << endl;
    for (int i = 1; i < word_count; i += 2) {
        cout << words[i] << endl;
    }

    cout << "Задание 4 < char > " << endl;

    char mass[20][11];
    char word2[11];

    for (int i = 0; i < word_count; ) {
        cout << i + 1 << " слово: ";
        cin >> word2;

        if (strlen(word2) > 10) {
            cout << "Кол-во букв должно быть <=10" << endl;
        }
        else {
            strcpy_s(mass[i], word2);
            i++;
        }
    }

    cout << "Вывод работы программы <char >:" << endl;
    for (int i = 1; i < word_count; i += 2) {
        cout << mass[i] << endl;
    }

    return 0;
}