#include <iostream>
using namespace std;

void mergesort(int arr[], int low, int high){
    if (low<high){
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high){
    int n1 = (mid-low+1)/2;
    int n2 = (high-mid)/2;
    int left[n1];
    int right[n2];
    
    for(int i=0; i<n1; i++)
        left[i] = arr[low+i];

    for(int i=0; i<2; i++)
        right[i] = arr[mid+i+1];

    int i=0, j=0, k=0;

    while(i<n1 && j<n2){
        if(left[i] < right[i]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}