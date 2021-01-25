#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>

void serialAddition(int a[], int b[], int n) {
    int c[n];
    clock_t start = clock();

    for(int i = 0; i<n; i++) {
        c[i] = a[i] + b[i];
    }
    double time = (double)(clock() - start)/CLOCKS_PER_SEC;

    printf("\nSerial : ");
    for(int i = 0; i<n; i++) {
        printf("%d ", c[i]);
    }
    printf("\nSerial time : %f\n", time);
}

void parallelAddition(int a[], int b[], int n) {
    int c[n];
    double start = omp_get_wtime();

    #pragma omp parallel for
    for(int i = 0; i<n; i++) {
        c[i] = a[i] + b[i];
    }
    double time = omp_get_wtime() - start;

    printf("Parallel : ");
    for(int i = 0; i<n; i++) {
        printf("%d ", c[i]);
    }
    printf("\nParallel time : %f\n", time);
}

void serialSubtraction(int a[], int b[], int n) {
    int c[n];
    clock_t start = clock();

    for(int i = 0; i<n; i++) {
        c[i] = a[i] - b[i];
    }
    double time = (double)(clock() - start)/CLOCKS_PER_SEC;

    printf("\nSerial : ");
    for(int i = 0; i<n; i++) {
        printf("%d ", c[i]);
    }
    printf("\nSerial time : %f\n", time);
}

void parallelSubtraction(int a[], int b[], int n) {
    int c[n];
    double start = omp_get_wtime();

    #pragma omp parallel for shared(c)
    for(int i = 0; i<n; i++) {
        c[i] = a[i] - b[i];
    }
    double time = omp_get_wtime() - start;

    printf("Parallel : ");
    for(int i = 0; i<n; i++) {
        printf("%d ", c[i]);
    }
    printf("\nParallel time : %f\n", time);
}

void serialMultiplication(int a[], int b[], int n) {
    int c[n];
    clock_t start = clock();

    for(int i = 0; i<n; i++) {
        c[i] = a[i] * b[i];
    }
    double time = (double)(clock() - start)/CLOCKS_PER_SEC;

    printf("\nSerial : ");
    for(int i = 0; i<n; i++) {
        printf("%d ", c[i]);
    }
    printf("\nSerial time : %f\n", time);
}

void parallelMultiplication(int a[], int b[], int n) {
    int c[n];
    double start = omp_get_wtime();

    #pragma omp parallel for shared(c)
    for(int i = 0; i<n; i++) {
        c[i] = a[i] * b[i];
    }
    double time = omp_get_wtime() - start;

    printf("Parallel : ");
    for(int i = 0; i<n; i++) {
        printf("%d ", c[i]);
    }
    printf("\nParallel time : %f\n", time);
}

int main() {
    int n = 10;
    int ch, a[n], b[n];

    for(int i = 0; i<n; i++) {
        a[i] = rand()%20;
        b[i] = rand()%20;
    }
    printf("Array 1 : ");
    for(int i = 0; i<n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nArray 2 : ");
    for(int  i = 0; i<n; i++) {
        printf("%d ", b[i]);
    }

    printf("\n");

    do {
        printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Exit\nEnter choice : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                serialAddition(a, b, n);
                parallelAddition(a, b, n);
            break;

            case 2:
                serialSubtraction(a, b, n);
                parallelSubtraction(a, b, n);
            break;

            case 3:
                serialMultiplication(a, b, n);
                parallelMultiplication(a, b, n);
                
            break;

            case 4: 
            break;

            default:
                printf("\nInvalid choice\n");
        }
    } while(ch != 4);

    return 0;
}