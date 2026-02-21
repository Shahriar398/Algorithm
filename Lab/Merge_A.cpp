#include <iostream>
#include<cmath>// INF
#define INFINITY 999999
using namespace std;

int mergeCount = 0;

void Merge (int A[], int start, int mid, int endd)
{
    mergeCount++;

    int n1= mid-start+1;
    int n2= endd-mid;
    int L[n1+1],R[n2+1];
    for (int i=0; i<n1; i++)
        L[i]=A [start+i];
    for (int j=0; j<n2; j++)
        R[j]= A[mid+1+j];
      L[n1]= INFINITY;
      R[n2]= INT_MAX;
      int i =0, j=0;
      for (int k=start; k<=endd; k++)
      {
          if (L[i]<= R[j])
          {
              A[k]= L[i];
              i++;
          }//if
          else{
            A[k]=R[j];
            j++;
          }//else
      }//for

}//merge


void merge_sort(int A[], int start, int endd)
{
    if(start<endd)
    {
        int mid= (start+endd)/2;
        merge_sort(A, start, mid);
        merge_sort(A, mid+1, endd);
        Merge(A, start, mid, endd);

    }//if
}//merge

int main()
{
    int arr[]= {4,6,2,3,8,-1,12,-4,-12,7};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<< "Array:" <<len<<endl;
    for (int i=0; i<len; i++)
    {
        cout<<arr[i]<< "   ";
    }

    merge_sort (arr,0,len-1);
    cout<< "\n\n------Sorted array------"<<endl;
    for (int i=0; i<len; i++)
    {
        cout<<arr[i]<<  "  ";

        //cout<<endl;
    }
    cout << "\n\nTotal merge: " << mergeCount << endl;
}//main
