#include <iostream>
#include<conio.h>
#include <algorithm>   // for max_element
using namespace std;

void CountingSort(int A[], int B[], int n, int k) {
    int* C = new int[k + 1];

    //loop 1
    for (int i = 1; i <= k; ++i)
    {
        C[i] = 0;
    }
    // loop 2
    for (int j = 1; j <= n; ++j)
    {
        C[A[j]]++;
    }
    // loop 3
    for (int i = 2; i <= k; ++i)
    {
        C[i] += C[i - 1];
    }
    // loop 4
    for (int j = n; j >= 1; --j)
    {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    delete[] C;
}

int main() {
    const int n = 7;
    const int MAX = 100;
    int A[MAX]   = {0, 4, 2, 2, 8, 3, 3, 1}; // A[1..7]
    int B[MAX];               // output array
    int k = *max_element(A + 1, A + n + 1);

    CountingSort(A, B, n, k);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; ++i)
    {
        cout << B[i] << ' ';
    }
    cout << '\n';
    getch();
}
