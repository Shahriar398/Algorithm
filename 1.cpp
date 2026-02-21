#include <iostream>
using namespace std;

/* ----------------------------------------------------------
   Utility : print an array with a caption
---------------------------------------------------------- */
void printArray(const int a[], int n, const string& caption)
{
    cout << caption;
    for (int i = 0; i < n; ++i) cout << a[i] << '\t';
    cout << '\n';
}

/* ----------------------------------------------------------
   1.  INSERTION SORT – ASCENDING
---------------------------------------------------------- */
void insertionSortAscending(int a[], int n)
{
    cout << "\n--- Insertion Sort (Ascending) ---\n";
    cout << "Initial array : ";
    printArray(a, n, "");

    for (int i = 1; i < n; ++i)
    {
        int key = a[i];
        int j   = i - 1;

        cout << "\nKey = " << key << "  -->  ";
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;

        cout << "after placing key : ";
        printArray(a, n, "");
    }

    cout << "\nSorted (Insertion) : ";
    printArray(a, n, "");
}

/* ----------------------------------------------------------
   2.  SELECTION SORT – DESCENDING
---------------------------------------------------------- */
void selectionSortDescending(int a[], int n)
{
    cout << "\n--- Selection Sort (Descending) ---\n";
    cout << "Initial array : ";
    printArray(a, n, "");

    for (int i = 0; i < n - 1; ++i)
    {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] > a[maxIdx]) maxIdx = j;

        if (maxIdx != i)
        {
            swap(a[i], a[maxIdx]);
            cout << "Swapped " << a[i] << " & " << a[maxIdx] << "  -->  ";
        }
        else
        {
            cout << "No swap needed        -->  ";
        }
        printArray(a, n, "");
    }

    cout << "\nSorted (Selection) : ";
    printArray(a, n, "");
}

/* ----------------------------------------------------------
   3.  BUBBLE SORT – ASCENDING
---------------------------------------------------------- */
void bubbleSortAscending(int a[], int n)
{
    cout << "\n--- Bubble Sort (Ascending) ---\n";
    cout << "Initial array : ";
    printArray(a, n, "");

    bool swapped;
    for (int pass = 0; pass < n - 1; ++pass)
    {
        swapped = false;
        for (int i = 0; i < n - pass - 1; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
                cout << "Swapped " << a[i] << " & " << a[i + 1] << "  -->  ";
                printArray(a, n, "");
            }
        }
        if (!swapped)
        {
            cout << "No swaps in pass " << pass + 1
                 << " – array already sorted.\n";
            break;
        }
    }

    cout << "\nSorted (Bubble) : ";
    printArray(a, n, "");
}

/* ----------------------------------------------------------
   MAIN – run every sort on a fresh copy of the array
---------------------------------------------------------- */
int main()
{
    const int ORIGINAL[] = {33, 66, 22, 99, 77, 11, 91, 55, 88, 44};
    const int SIZE = sizeof(ORIGINAL) / sizeof(ORIGINAL[0]);

    cout << "Original array : ";
    printArray(ORIGINAL, SIZE, "");

    /* --- Insertion sort (ascending) --- */
    int arr1[SIZE];
    copy(ORIGINAL, ORIGINAL + SIZE, arr1);
    insertionSortAscending(arr1, SIZE);

    /* --- Selection sort (descending) --- */
    int arr2[SIZE];
    copy(ORIGINAL, ORIGINAL + SIZE, arr2);
    selectionSortDescending(arr2, SIZE);

    /* --- Bubble sort (ascending) --- */
    int arr3[SIZE];
    copy(ORIGINAL, ORIGINAL + SIZE, arr3);
    bubbleSortAscending(arr3, SIZE);

    return 0;
}
