#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int startIndex, elementOnHand, currIndex;
    for (int startIndex = 1; startIndex < n; startIndex++)
    {
        elementOnHand = arr[startIndex];
        currIndex = startIndex - 1;
        while (currIndex >= 0 && arr[currIndex] > elementOnHand)
        {
            arr[currIndex + 1] = arr[currIndex];
            currIndex--;
        }
        arr[currIndex + 1] = elementOnHand;

        cout << "\nkey: " << elementOnHand << "-----";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << "\t";
        }
    }
    cout << "\nOutput Array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}

void selectionSort(int arr[], int n)
{
    int startIdx, curIdx, minIdx;
    for (startIdx = 0; startIdx < n - 1; startIdx++)
    {
        minIdx = startIdx;
        for (curIdx = startIdx + 1; curIdx < n; curIdx++)
        {
            if (arr[curIdx] > arr[minIdx])
            {
                minIdx = curIdx;
            }
        }
        if (minIdx != startIdx)
        {
            swap(arr[minIdx], arr[startIdx]);
            cout << "\nKey: " << arr[minIdx] << " swap: " << arr[startIdx] << "----";
        }
    }
    cout << "\nOutput Array" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
}

int main()
{
    int arr[] = {33, 66, 22, 99, 77, 11, 91, 55, 88, 44};
    int size_ = sizeof(arr) / sizeof(int);
    cout << "Array size:  " << size_ << endl;
    for (int i = 0; i < size_; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << "\n\n------Insert Sort------: " << endl;
    insertionSort(arr, size_);

    cout << "\n\n------Selection Sort------: " << endl;
    selectionSort(arr, size_);

    /* ----------------------------------------------------------
       NEW CRITERIA – EXTRA DRIVER AFTER ORIGINAL OUTPUT
       ---------------------------------------------------------- */
    int original[] = {33, 66, 22, 99, 77, 11, 91, 55, 88, 44};
    const int SZ = sizeof(original) / sizeof(original[0]);

    /* 1) Insertion Sort – Ascending */
    int a1[SZ]; copy(original, original + SZ, a1);
    {
        cout << "\n\n--- Insertion Sort (Ascending) ---\n";
        for (int i = 1; i < SZ; ++i)
        {
            int key = a1[i], j = i - 1;
            cout << "Key = " << key << "  -->  ";
            while (j >= 0 && a1[j] > key)
            {
                a1[j + 1] = a1[j];
                --j;
            }
            a1[j + 1] = key;
            for (int k = 0; k < SZ; ++k) cout << a1[k] << '\t';
            cout << '\n';
        }
        cout << "Sorted (Insertion): ";
        for (int k = 0; k < SZ; ++k) cout << a1[k] << '\t';
    }

    /* 2) Selection Sort – Descending */
    int a2[SZ]; copy(original, original + SZ, a2);
    {
        cout << "\n\n--- Selection Sort (Descending) ---\n";
        for (int i = 0; i < SZ - 1; ++i)
        {
            int maxIdx = i;
            for (int j = i + 1; j < SZ; ++j)
                if (a2[j] > a2[maxIdx]) maxIdx = j;
            if (maxIdx != i) swap(a2[i], a2[maxIdx]);
            for (int k = 0; k < SZ; ++k) cout << a2[k] << '\t';
            cout << '\n';
        }
        cout << "Sorted (Selection): ";
        for (int k = 0; k < SZ; ++k) cout << a2[k] << '\t';
    }

    /* 3) Bubble Sort – Ascending */
    int a3[SZ]; copy(original, original + SZ, a3);
    {
        cout << "\n\n--- Bubble Sort (Ascending) ---\n";
        bool swapped;
        for (int pass = 0; pass < SZ - 1; ++pass)
        {
            swapped = false;
            for (int i = 0; i < SZ - pass - 1; ++i)
                if (a3[i] > a3[i + 1])
                {
                    swap(a3[i], a3[i + 1]);
                    swapped = true;
                    for (int k = 0; k < SZ; ++k) cout << a3[k] << '\t';
                    cout << "  (swap " << a3[i] << " & " << a3[i + 1] << ")\n";
                }
            if (!swapped)
            {
                cout << "No swaps in pass " << pass + 1 << " – already sorted.\n";
                break;
            }
        }
        cout << "Sorted (Bubble): ";
        for (int k = 0; k < SZ; ++k) cout << a3[k] << '\t';
    }
    cout << endl;

    return 0;
}
