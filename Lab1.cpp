#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int startIndex ,elemOnHand ,currIndex;
    for(int startIndex =1;startIndex<n;startIndex++)
    {
        elemOnHand= arr[startIndex];
        currIndex= startIndex-1;
        while (currIndex>=0 && arr[currIndex]>elemOnHand)
        {
            arr[currIndex+1]=arr[currIndex] ;
            currIndex--;

        }
        arr[currIndex+1]= elemOnHand;
        cout <<"\nkey: "<<elemOnHand<< "----"<<endl;

        for(int i=0;i<n ;i++)
    {
        cout<<arr[i]<<"\t";
    }

    }
    cout <<"output array :"<<endl;
    for(int i=0;i<n ;i++)
    {
        cout<<arr[i]<<"\t";
    }

}

void selectionSort(int arr[] ,int n)
{
    int startIdx , currIdx , minIdx;
    for(startIdx=0; startIdx<n-1; startIdx++)
    {
        minIdx=startIdx;
        for (currIdx = startIdx+1; currIdx < n ; currIdx++)
        {
            if(arr[currIdx]>arr[minIdx])
            {
                minIdx= currIdx;
            }
        }//inner loop
        if(minIdx!=startIdx)
        {
            swap(arr[minIdx],arr[startIdx]);

        }//if
        cout <<"\nkey: "<<arr[minIdx]<<" swap : "<< arr[startIdx]<< "----"<<endl;

        for(int i=0;i<n ;i++)
        {
            cout<<arr[i]<<"\t";
        }
    }//outer loop
    cout <<"output array :"<<endl;
    for(int i=0;i<n ;i++)
    {
        cout<<arr[i]<<"\t";
    }

}


int main(){
    int arr[]= {33,66,22,99,77,11,91,55,88,44};
    int size_arr = sizeof(arr)/sizeof(arr[4]);
    cout<<"Arrary size :"<< size_arr<<endl;
    for(int i=0; i<size_arr ;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    insertionSort(arr,size_arr);
    cout<<endl;

    selectionSort(arr,size_arr);

    return 0;

}
