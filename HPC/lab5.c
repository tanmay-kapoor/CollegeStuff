#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int j = low, temp;
    for(int i = low+1; i<=high;  i++) {
        if(arr[i] <= pivot) {
            j++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void sortParallel(int arr[], int low, int high) {
    if(low < high) {
        int index = rand() % (high-low+1) + low;
        int temp = arr[index];
        arr[index] = arr[low];
        arr[low] = temp;

        int m = partition(arr, low, high);

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                sortParallel(arr, low, m-1);
            }

            #pragma omp section
            {
                sortParallel(arr, m+1, high);
            }
        }
    }
}

void sortSerial(int arr[], int low, int high) {
    if(low < high) {
        int index = rand() % (high-low+1) + low;
        int temp = arr[index];
        arr[index] = arr[low];
        arr[low] = temp;

        int m = partition(arr, low, high);
        sortParallel(arr, m+1, high);
        sortParallel(arr, low, m-1);
    }
}

int main() {
    int n;
    printf("n : ");
    scanf("%d", &n);
    int arr[n], a[n];

    for(int i = 0; i<n; i++) {
        arr[i] = rand() % 100;
        // printf("%d ", arr[i]);
        a[i] = arr[i];
    }
    // printf("\n");
    
    clock_t serialStart = clock();
    sortSerial(a, 0, n-1);
    double serial = (double)(clock() - serialStart)/CLOCKS_PER_SEC;
    printf("Serial time : %f\n", serial);

    double parStart = omp_get_wtime();
    sortParallel(arr, 0, n-1);
    double parallel = omp_get_wtime() - parStart;
    printf("Parallel time : %f\n", parallel);

    // printf("\nSerial : ");
    // for(int i = 0; i<n; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\nParallel : ");
    // for(int i = 0; i<n; i++) {
    //     printf("%d ", arr[i]);
    // }
    return 0;
}