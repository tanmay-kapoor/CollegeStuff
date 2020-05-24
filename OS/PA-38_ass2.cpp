#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

void asc(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }  
    display(arr, n);
} 

void desc(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            if(arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }  
    display(arr, n);
}

int main() {
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter n elements : \n";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    cout<<"\n";
    pid_t pid = fork();

    if(pid > 0) {
        //wait(NULL);                               if want paremt process to wait while child executes
        cout<<"This is the parent process\n";
        asc(arr, n);

    } else if(pid == 0) {
        cout<<"This is the child process\n";
        desc(arr, n);
        
    } else {
        cout<<"Failed to fork\n";
    }

    return 0;
}
