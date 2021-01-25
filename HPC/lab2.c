#include<stdio.h>
#include<omp.h>
#include<time.h>

void serial(int n) {
    for(int i = 0; i<n; i++) {
        printf("%d\n", i);
    }
    for(int i = n-1; i>=0; i--) {
        printf("%d\n", i);
    }
}

void parallel(int n) {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            for(int i = 0; i<n; i++) {
                printf("%d\n", i);
            }
        }

        #pragma omp section
        {
            for(int i = n-1; i>=0; i--) {
                printf("%d\n", i);
            }
        }
    }
}

int main() {
    int n;
    printf("n : ");
    scanf("%d", &n);

    clock_t serialStart = clock();
    serial(n);
    double ser = (double)(clock() - serialStart)/CLOCKS_PER_SEC;

    double parStart = omp_get_wtime();
    parallel(n);
    double par = omp_get_wtime() - parStart; 

    printf("Serial = %f\nParallel = %f\n", ser, par);

    return 0;
}