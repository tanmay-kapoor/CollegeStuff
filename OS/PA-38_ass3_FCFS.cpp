//PA 38
//Tanmay Kapoor

#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of processes : ";
    cin>>n;

    int ct[20], at[50], wt[50], bt[50], tat[5];
    double total_tat = 0.0, total_wt = 0.0;

    for(int i= 0 ;i<n; i++) {
        cout<<"\nEnter arrival time for process "<<i<<" : ";
        cin>>at[i];
        cout<<"Enter burst time for process "<<i<<" : ";
        cin>>bt[i];
    }

    ct[0] = bt[0];
    tat[0] = ct[0] - at[0];
    total_tat += tat[0];
    wt[0] = tat[0] - bt[0];
    total_wt += wt[0]; 

    for(int i = 1; i<n; i++) {
        ct[i] = ct[i-1] + bt[i];        //CT = BT of current + CT of previous
        tat[i] = ct[i] - at[i];         //TAT = CT-AT
        total_tat += tat[i];
        wt[i] = tat[i] - bt[i];         //WT = TAT-BT
        total_wt += wt[i];
    }

    cout<<"\n\nP#\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i<n; i++) {
        cout<<i<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
    }

    cout<<"\nAvg TAT : "<<total_tat/n<<"\n";
    cout<<"Avg WT : "<<total_wt/n)<<"\n";

    return 0;
}
/* output
Enter number of processes : 5

Enter arrival time for process 0 : 0
Enter burst time for process 0 : 2

Enter arrival time for process 1 : 1
Enter burst time for process 1 : 6

Enter arrival time for process 2 : 2
Enter burst time for process 2 : 4

Enter arrival time for process 3 : 3
Enter burst time for process 3 : 9

Enter arrival time for process 4 : 4
Enter burst time for process 4 : 12


P#      AT      BT      CT      TAT     WT
0       0       2       2       2       0
1       1       6       8       7       1
2       2       4       12      10      6
3       3       9       21      18      9
4       4       12      33      29      17

Avg TAT : 13.2
Avg WT : 6.6
*/
