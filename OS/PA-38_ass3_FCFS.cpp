//PA 38
//Tanmay Kapoor
#include<stdio.h>

int main() {
    int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
    int n,sum=0;
    float total_TAT=0,total_WT=0;

    printf("Enter no. of processes\n");
    scanf("%d",&n);

    printf("Enter arrival time and burst time for each process\n");

    for(int i=0;i<n;i++) {
        printf("Arrival time of process[%d] ",i+1);
        scanf("%d",&at[i]);
        printf("Burst time of process[%d] ",i+1);
        scanf("%d",&bt[i]);
        printf("\n");
    }

    //calculate completion time of processes
    for(int j=0;j<n;j++) {
        sum+=bt[j];
        ct[j]+=sum;
    }

    //calculate turnaround time and waiting times
    for(int k=0;k<n;k++) {
        tat[k]=ct[k]-at[k];
        total_TAT+=tat[k];
    }

    for(int k=0;k<n;k++) {
        wt[k]=tat[k]-bt[k];
        total_WT+=wt[k];
    }

    printf("Solution: \n\n");
    printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");

    for(int i=0;i<n;i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
    printf("Average WT = %f\n\n",totalWT/n);

    return 0;
}
/* output
Enter number of processes       3
Enter arrival time and burst time for each process

Arrival time of process[1]      1
Burst time of process[1]        3

Arrival time of process[2]      2
Burst time of process[2]        4

Arrival time of process[3]      3
Burst time of process[3]        5

Solution:

P#       AT      BT      CT      TAT     WT

P1       1       3       3       2       -1
P2       2       4       7       5       1
P3       3       5       12      9       4


Average Turnaround Time = 5.333333
Average WT = 1.333333
*/
