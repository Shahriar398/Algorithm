#include<iostream>
#include<conio.h>
using namespace std;

// ---- insertionSort (ascending)


void insertionSort(int arr[], int n)
{
    int startIndex, elementOnHand, currIndex;
    for (startIndex = 1; startIndex < n; startIndex++)
    {
        elementOnHand = arr[startIndex];
        currIndex = startIndex - 1;

        while (currIndex >= 0 && arr[currIndex] > elementOnHand)
        {
            arr[currIndex + 1] = arr[currIndex];
            currIndex--;
        }
        arr[currIndex + 1] = elementOnHand;

        cout << "\nkey: " << elementOnHand << "---> ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << "\t";
    }
    cout << "\nOutput Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
}

    // ------ selectionSort (descending)


void selectionSort(int arr[], int n)
{
    int startIdx, curIdx, maxIdx;
    for (startIdx = 0; startIdx < n - 1; startIdx++)
    {
        maxIdx = startIdx;
        for (curIdx = startIdx + 1; curIdx < n; curIdx++)
            if (arr[curIdx] > arr[maxIdx])   //  for descending
                maxIdx = curIdx;

        if (maxIdx != startIdx)
            swap(arr[maxIdx], arr[startIdx]);

        cout << "\nkey: " << arr[startIdx] << "---> ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << "\t";
    }
    cout << "\nOutput Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
}

// --- bubbleSort (ascending)


void bubbleSort(int arr[], int n)
{
    bool swapped;
    for (int pass = 0; pass < n - 1; pass++)
    {
        swapped = false;
        for (int i = 0; i < n - pass - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        // print trace after every pass
        cout << "\nkey: pass " << pass + 1 << "---> ";
        for (int j = 0; j < n; j++)
            cout << arr[j] << "\t";

        if (!swapped) break;  // already sorted
    }
    cout << "\nOutput Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
}

int main()
{
    int arr[] = {33, 66, 22, 99, 77, 11, 91, 55, 88, 44};
    int size_ = sizeof(arr) / sizeof(int);

    cout << "Array size: " << size_ << endl;
    for (int i = 0; i < size_; i++)
        cout << arr[i] << "\t";

    cout << "\n\n------Insert Sort------\n";
    insertionSort(arr, size_);

    cout << "\n\n------Selection Sort (descending)------\n";
    selectionSort(arr, size_);

    cout << "\n\n------Bubble Sort (ascending)------\n";
    bubbleSort(arr, size_);

    getch();
}
