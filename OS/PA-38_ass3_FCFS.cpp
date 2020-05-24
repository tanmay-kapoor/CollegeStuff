//PA 38
//Tanmay Kapoor

#include<iostream>
using namespace std;

class process {
    public:
        int at, bt, ct, wt, tat;
};

int main() {
    int n;
    double total_tat = 0.0, total_wt = 0.0;

    cout<<"Enter number of processes : ";
    cin>>n;
    process p[n];

    for(int i= 0 ;i<n; i++) {
        cout<<"\nEnter arrival time for process "<<i<<" : ";
        cin>>p[i].at;
        cout<<"Enter burst time for process "<<i<<" : ";
        cin>>p[i].bt;
    }

    p[0].ct = p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    total_tat += p[0].tat;
    p[0].wt = p[0].tat - p[0].bt;
    total_wt += p[0].wt; 

    for(int i = 1; i<n; i++) {
        p[i].ct = p[i-1].ct + p[i].bt;        //CT = BT of current + CT of previous
        p[i].tat = p[i].ct - p[i].at;         //TAT = CT-AT
        total_tat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;         //WT = TAT-BT
        total_wt += p[i].wt;
    }

    cout<<"\n\nP#\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i<n; i++) {
        cout<<i<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\n";
    }

    cout<<"\nAvg TAT : "<<total_tat/n<<"\n";
    cout<<"Avg WT : "<<total_wt/n<<"\n";

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
