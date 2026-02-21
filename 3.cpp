#include <iostream>
#include <vector>
#include <algorithm>   // <- required for max_element
using namespace std;

/* Counting-Sort exactly as in the slides
   A[1..n]  : input array (1-based indexing)
   B[1..n]  : sorted output
   k        : max value in A
*/
void CountingSort(const vector<int>& A, vector<int>& B, int k) {
    int n = A.size() - 1;        // A[0] unused, we use 1..n
    vector<int> C(k + 1, 0);     // C[0..k]

    /* ---- loop 1 ---- */
    for (int i = 1; i <= k; ++i) C[i] = 0;

    /* ---- loop 2 ---- */
    for (int j = 1; j <= n; ++j) C[A[j]]++;

    /* ---- loop 3 ---- */
    for (int i = 2; i <= k; ++i) C[i] += C[i - 1];

    /* ---- loop 4 ---- */
    for (int j = n; j >= 1; --j) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main() {
    /* 1-based indexing: put dummy at index 0 */
    vector<int> A = {0, 4, 2, 2, 8, 3, 3, 1};  // A[1..7]
    int n = 7;
    vector<int> B(n + 1);                        // B[1..7]

    int k = *max_element(A.begin() + 1, A.end());

    CountingSort(A, B, k);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; ++i) cout << B[i] << ' ';
    cout << '\n';
    return 0;
}
