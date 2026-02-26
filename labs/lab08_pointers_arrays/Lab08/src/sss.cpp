#include <stdio.h>
#include <iostream>
#include <windows.h>

#define N 10

void Exercise4();
void f(int& a, int* b);

int main()
{
    using namespace std;

    int x = 5, y = 20;
    f(x, &y);
    cout << " 2.2)  " << x << " " << y << endl;


    printf("  \n");

    printf(" 1) StatMass indeks \n");
    int arr1[N] = { 0 };
    for (int i = 0; i < N; i++) {
        arr1[i] = i * i;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n 2) StatMass ukaz \n");
    int arr2[N] = { 0 };
    for (int i = 0; i < N; i++) {
        *(arr2 + i) = i * i;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr2 + i));
    }

    printf("\n 3) DinMass indeks  \n");
    int* d1 = new int[N];
    for (int i = 0; i < N; i++) {
        d1[i] = i * i;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", d1[i]);
    }
    delete[] d1;

    printf("\n 4) DinMass ukaz \n");
    int* d2 = new int[N];
    int* ptr = d2;
    for (int i = 0; i < N; i++) {
        *(ptr + i) = i * i;
    }
    ptr = d2;
    for (int i = 0; i < N; i++) {
        printf("%d ", *(ptr + i));
    }
    delete[] d2;

    printf("\n 3.2\n");

    int size1 = 8;
    int size2 = 7;

    int* darr1 = new int[size1];
    int* darr2 = new int[size2];
    int* res_arr = new int[size1 + size2];

    for (int i = 0; i < size1; i++) {
        darr1[i] = i * 2;
    }

    for (int i = 0; i < size2; i++) {
        darr2[i] = i * 2 + 1;
    }

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (darr1[i] < *(darr2 + j)) {
            res_arr[k] = darr1[i];
            i++;
        }
        else {
            res_arr[k] = *(darr2 + j);
            j++;
        }
        k++;
    }

    while (i < size1) {
        res_arr[k++] = darr1[i++];
    }

    while (j < size2) {
        res_arr[k++] = *(darr2 + j);
        j++;
    }

    printf("\n 1): ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", darr1[i]);
    }
    printf("\n");

    printf(" 2): ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", *(darr2 + i));
    }
    printf("\n");

    printf(" obd mass: ");
    for (int i = 0; i < (size1 + size2); i++) {
        printf("%d ", *(res_arr + i));
    }
    printf("\n");

    delete[] darr1;
    delete[] darr2;
    delete[] res_arr;

    Exercise4();

    return 0;
}

void f(int& a, int* b) {
    a *= 2;
    *b += 10;
}

void Exercise4()
{
    printf("\n 4 \n");

    struct Node {
        int id;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < 10; i++) {
        Node* newItem = new Node;
        newItem->id = i;
        newItem->next = NULL;
        newItem->prev = NULL;

        if (head == NULL) {
            head = newItem;
            tail = newItem;
        }
        else {
            tail->next = newItem;
            newItem->prev = tail;
            tail = newItem;
        }
    }

    printf("Spisok: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->id);
        current = current->next;
    }
    printf("\n");

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}