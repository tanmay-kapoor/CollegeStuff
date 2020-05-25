#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

int main() {
    int nf, N, no_tr=0;
    srand(time(NULL));

    cout<<"Number of frames : \n";
    cin>>nf;

    int m;
    cout<<"Seq no field in bits : \n";
    cin>>m;
    
    N=(pow(2,m))-1;
    cout<<"\nWindow size = "<<N<<"\n\n";
    
    int i=1;
    while(i<=nf)
    {
        int x=0;
        for(int j=i;j<i+N && j<=nf;j++)
        {
            cout<<"Sent Frame "<<j<<endl;
            no_tr++;
        }
        for(int j=i;j<i+N && j<=nf;j++)
        {
            int flag = rand()%2;
            if(!flag)
            {
                cout<<"Acknowledgment sent for Frame "<<j<<endl;
                x++;
            }
            else
                {  
                cout<<"Frame "<<j<<" Not Received"<<endl;
                cout<<"Retransmitting Window"<<endl;
                break;
                }
        }
        cout<<endl;
        i+=x;
    }
    
    cout<<"Total number of transmissions : "<<no_tr<<endl;
    return 0;
}

/*OUTPUT
Number of frames :
12
Seq no field in bits :
2

Window size = 3

Sent Frame 1
Sent Frame 2
Sent Frame 3
Acknowledgment sent for Frame 1
Acknowledgment sent for Frame 2
Frame 3 Not Received
Retransmitting Window

Sent Frame 3
Sent Frame 4
Sent Frame 5
Acknowledgment sent for Frame 3
Frame 4 Not Received
Retransmitting Window

Sent Frame 4
Sent Frame 5
Sent Frame 6
Acknowledgment sent for Frame 4
Acknowledgment sent for Frame 5
Frame 6 Not Received
Retransmitting Window

Sent Frame 6
Sent Frame 7
Sent Frame 8
Frame 6 Not Received
Retransmitting Window

Sent Frame 6
Sent Frame 7
Sent Frame 8
Acknowledgment sent for Frame 6
Acknowledgment sent for Frame 7
Acknowledgment sent for Frame 8

Sent Frame 9
Sent Frame 10
Sent Frame 11
Acknowledgment sent for Frame 9
Frame 10 Not Received
Retransmitting Window

Sent Frame 10
Sent Frame 11
Sent Frame 12
Acknowledgment sent for Frame 10
Acknowledgment sent for Frame 11
Acknowledgment sent for Frame 12

Total number of transmissions : 21
*/