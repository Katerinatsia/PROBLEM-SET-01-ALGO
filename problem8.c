#include <stdio.h>
#define ARR_SIZE 10
#define  EVEN_SIZE 5 //calulated by n/log(n)

/*Functions*/
void divide_evens(int arr[], int even[], int odd[], int size);
void print_array(int arr[], int size);
void merge_array(int arr[], int even[], int odd[], int size);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

/*main*/
int main(int argc, char *argv[]){
    int arr[ARR_SIZE]={3, 6, 8, 5, 7, 2, 34, 9, 4, 13};
    int even[EVEN_SIZE]={0}, odd[ARR_SIZE-EVEN_SIZE]={0};

    //divide the array to even and odds
    divide_evens(arr, even, odd, ARR_SIZE);
    printf("Array Before\n");
    print_array(arr, ARR_SIZE);

    //sort even array with mergeSort
    mergeSort(even, 0, EVEN_SIZE-1);
    //merge even and odd arrays
    merge_array(arr, even, odd, ARR_SIZE);
    printf("Array After\n");
    print_array(arr, ARR_SIZE);
    return(0);
}

/*This function divides an array of integers into subarrays with even and odd numbers*/
void divide_evens(int arr[], int even[], int odd[], int size){
    int i,j=0, k=0;
    for(i=0; i<size; i++){
        if(arr[i] % 2 == 0){
            even[j] = arr[i];
            j++;
        }else{
            odd[k] = arr[i];
            k++;
        }
    }
}

/*This function prints an array*/
void print_array(int arr[], int size){
    int i;
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}

/*This function merges the two arrays (even and odd)*/
void merge_array(int arr[], int even[], int odd[], int size){
    int i,j=0,k=0; //counters

    for(i=0; i<size; i++){
        if((j>=ARR_SIZE-EVEN_SIZE)||((even[k]!=0) && (even[k]<odd[j]))){
            arr[i]=even[k];
            k++;
        }else{
            arr[i]=odd[j];
            j++;
        }
    }
}

/*Merge sort algorithm*/
void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int l_size = mid - left + 1;
    int r_size = right - mid;
    int L[l_size], R[r_size];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < l_size; i++)
        L[i] = arr[left + i];
    for (j = 0; j < r_size; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = j = 0;
    k = left;
    while (i < l_size && j < r_size) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < l_size) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < r_size) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*This function sorts sub-arrays*/
void mergeSort(int arr[], int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
