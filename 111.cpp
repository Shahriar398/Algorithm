#include<iostream>
using namespace std;

/* ---------- Insertion Sort (unchanged) ---------- */
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

/* ---------- Completed Selection Sort (Descending) with steps ---------- */
void selectionSort(int arr[], int n)
{
    cout << "\n--- Selection Sort (Descending) ---\n";
    cout << "Start: ";
    for (int k = 0; k < n; ++k) cout << arr[k] << '\t';
    cout << '\n';

    int startIdx, curIdx, maxIdx;
    for (startIdx = 0; startIdx < n - 1; ++startIdx)
    {
        maxIdx = startIdx;
        for (curIdx = startIdx + 1; curIdx < n; ++curIdx)
        {
            if (arr[curIdx] > arr[maxIdx])      // descending order
                maxIdx = curIdx;
        }

        if (maxIdx != startIdx)
        {
            swap(arr[maxIdx], arr[startIdx]);
            cout << "Step: swapped " << arr[startIdx] << " & " << arr[maxIdx]
                 << "  -->  ";
        }
        else
        {
            cout << "Step: no swap needed            -->  ";
        }

        for (int k = 0; k < n; ++k) cout << arr[k] << '\t';
        cout << '\n';
    }

    cout << "Sorted (Selection): ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << '\t';
}

/* ---------- main ---------- */
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

    return 0;
}
