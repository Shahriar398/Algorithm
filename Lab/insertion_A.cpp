#include<iostream>
using namespace std;
void insertionSort (int arr[], int n){

    int startIndex, elementOnHand, currIndex;
    for (int startIndex=1; startIndex<n; startIndex++)
    {
        elementOnHand= arr[startIndex];
        currIndex = startIndex-1;
        while (currIndex>=0 && arr[currIndex]>elementOnHand)
        {
                arr[currIndex+1]=arr[currIndex];
                currIndex--;


        }// while

        arr[currIndex+1]=elementOnHand;

        cout<< "\nkey: "<< elementOnHand<< "-----";
        for (int i=0; i<n; i++)
        {
            cout<<arr[i]<<"\t";
        } //simulation


    }//for

    cout<<"\nOutput Array "<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }


}//insert

void selectionSort (int arr[], int n)
{

    int startIdx, curIdx, minIdx;
    for (startIdx=0; startIdx<n-1; startIdx++)
    {
        minIdx=startIdx;
        for (curIdx=startIdx+1; curIdx<n; curIdx++)
        {
            if (arr[curIdx]>arr[minIdx])
            {
                minIdx =curIdx;
            }
        }//if
    }//inner for
    if (minIdx!=startIdx)
    {
        swap(arr[minIdx], arr[startIdx]);
        cout<<"\nKey: "<<arr[minIdx]<<" swap: " << arr[startIdx]<<"----";

}//outer for

    cout<<"\nOutput Array"<<endl;
    for(int i=0; i<n; i++)


        cout<<arr[i]<<"\t";
}//select

int main()
{
    int arr[]={33,66,22,99,77,11,91,55,88,44};
    int size_ = sizeof(arr)/sizeof(int);//sizeof(arr[4])
    cout<< "Array size:  "<<size_<<endl;
    for(int i=0; i<size_; i++)
        {
        cout<<arr[i]<<"\t";
        }

        //call insert
        cout<<"\n\n------Insert Sort------: "<<endl;
        insertionSort( arr, size_);

        cout<<"\n\n------Selection Sort------: "<<endl;
        selectionSort( arr, size_);

   return 0;

}//main
