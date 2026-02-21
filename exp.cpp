#include <iostream>
using namespace std;

// ---------- Insertion Sort (descending) ----------
void insertionSort(int arr[], int n)
{
    int startIndex, elementOnHand, currIndex;
    for (startIndex = 1; startIndex < n; startIndex++)
    {
        elementOnHand = arr[startIndex];
        currIndex = startIndex - 1;

        // flip the comparison from > to <
        while (currIndex >= 0 && arr[currIndex] < elementOnHand)
        {
            arr[currIndex + 1] = arr[currIndex];
            currIndex--;
        }
        arr[currIndex + 1] = elementOnHand;

        cout << "\nkey: " << elementOnHand << "-----";
        for (int i = 0; i < n; i++)
            cout << arr[i] << "\t";
    }

    cout << "\nOutput Array (Insertion)" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
}

// ---------- Selection Sort (descending) ----------
void selectionSort(int arr[], int n)
{
    int startIdx, curIdx, minIdx;
    for (startIdx = 0; startIdx < n - 1; startIdx++)
    {
        minIdx = startIdx;
        for (curIdx = startIdx + 1; curIdx < n; curIdx++)
        {
            // flip the comparison from > to <
            if (arr[curIdx] > arr[minIdx])
                minIdx = curIdx;
        }

        if (minIdx != startIdx)
        {
            swap(arr[minIdx], arr[startIdx]);
            cout << "\nKey: " << arr[startIdx] << " swap: " << arr[minIdx] << "----";
        }
    }

    cout << "\nOutput Array (Selection)" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
}

// ---------- main ----------
int main()
{
    int arr[] = {33, 66, 22, 99, 77, 11, 91, 55, 88, 44};
    int size_ = sizeof(arr) / sizeof(int);

    cout << "Original Array" << endl;
    for (int i = 0; i < size_; i++)
        cout << arr[i] << "\t";

    cout << "\n\n------Insert Sort------: " << endl;
    insertionSort(arr, size_);

    cout << "\n\n------Selection Sort------: " << endl;
    selectionSort(arr, size_);

    return 0;
}
