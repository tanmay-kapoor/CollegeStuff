#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

void serialBubble(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        int first = i%2;

        for(int j = first; j<n-1; j+=2) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void parallelBubble(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        int first = i%2;

        #pragma omp parallel for
        for(int j = first; j<n-1; j+=2) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("n : ");
    scanf("%d", &n);
    int arr[n];
    int a[n];

    for(int i = 0; i<n; i++) {
        arr[i] = rand()%100;
        a[i] = arr[i];
    }

    clock_t serStart = clock();
    serialBubble(arr, n);
    double serial = (double)(clock() - serStart)/CLOCKS_PER_SEC;
    printf("Serial Time : %f", serial);

    double parStart = omp_get_wtime();
    parallelBubble(arr, n);
    double parallel = omp_get_wtime() - parStart;
    printf("\nParallel Time : %f", parallel);

    return 0;
}