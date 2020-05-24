/* Tanmay Kapoor
   ROLL NO.- PA38
*/
#include<stdio.h>
int main() {
    int at[10],bt[10],x[10];
    int wt[10],tat[10],completion[10];
    int i,j,smallest,count=0,time,n;
    float avg_wt=0,avg_tat=0,end;S

    printf("\nEnter the number of Processes: ");  //Number of Processes as Input
    scanf("%d",&n);

    for(i=0; i<n; i++) {
        printf("\nEnter arrival time of process: ");  //Arrival time as Input
        scanf("%d",&at[i]);
    }

    for(i=0; i<n; i++) {
        printf("\nEnter burst time of process: ");  //Burst time as Input
        scanf("%d",&bt[i]);
    }

    for(i=0; i<n; i++)
        x[i]=bt[i];

    bt[9]=9999;
    for(time=0; count!=n; time++) {
        smallest=9;
        for(i=0; i<n; i++) {
            if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0 )
                smallest=i;
        }
        bt[smallest]--;

        if(bt[smallest]==0) {
            count++;
            end=time+1;
            completion[smallest] = end;
            wt[smallest] = end - at[smallest] - x[smallest];
            tat[smallest] = end - at[smallest];
        }
    }
   
    printf("Process\tarrival-time\tburst-time\twaiting-time\tturnaround-time\t\n");

    for(i=0; i<n; i++) {
        printf("p[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n ",i+1,at[i],x[i],wt[i],tat[i]);
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }

    printf("\n\nAverage waiting time =%f\n",avg_wt/n);
    printf("  Average Turnaround time =%f",avg_tat/n);
    printf("\n");
   
   return 0;
}

/* OUTPUT:-
Enter the number of Processes: 5

Enter arrival time of process1: 0

Enter arrival time of process2: 2

Enter arrival time of process3: 4

Enter arrival time of process4: 5

Enter arrival time of process5: 7

Enter burst time of process1: 7

Enter burst time of process2: 4

Enter burst time of process3: 1

Enter burst time of process4: 4

Enter burst time of process5: 9
Process arrival-time    burst-time      waiting-time    turnaround-time
 p[1]           0               7               9               16
 p[2]           2               4               1               5
 p[3]           4               1               0               1
 p[4]           5               4               2               6
 p[5]           7               9               9               18


Average waiting time =4.200000
  Average Turnaround time =9.200000
*/

