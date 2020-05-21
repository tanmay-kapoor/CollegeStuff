/*
Tanmay Kapoor
Div A
PA-38
Batch A-3
*/

#include <iostream>
using namespace std;

class prim {
    int nodes, min;
    int cost[50][50], visited[50];

    public:
        prim();
        void input();
        void output();
        void minSpanningTree();
};

prim::prim() {

    cout<<"\nEnter number of cities : ";
    cin>>nodes;
}

void prim::input() {

    cout<<"\nEnter cost of connection between the cities. Enter 0 if no connection exists.\n";

    int charge;

    for(int i= 0; i<nodes; i++) {

        visited[i] = 0;

       for(int j = i+1; j<nodes; j++) { 

           cout<<"Cost of connection between cities "<<i<<" and "<<j<<" : ";
           cin>>charge;

           cost[i][j] = cost[j][i] = charge;
       }
    }
}

void prim::output() {

    cout<<"\nCost adjacency matrix :";

    for(int i = 0; i<nodes; i++) {

        cout<<"\n";
        for(int j = 0; j<nodes; j++) {
            cout<<cost[i][j]<<"\t";
        }
    }
}

void prim::minSpanningTree() {

    int start;

    cout<<"\n\nEnter starting city : ";
    cin>>start;
    visited[start] = 1;

    cout<<"\n\nMinimum Spanning Tree:";
    int u, v, total = 0;

    for(int counter = 0; counter < nodes-1; counter++) {

        min = 999;

        for(int i = 0; i<nodes; i++) {

            if(visited[i] == 1) {

                for(int j = 0; j<nodes; j++) {

                    if(visited[j]==0) {

                        if(cost[i][j] < min && cost[i][j] != 0) {

                            min = cost[i][j];
                            u =  i;
                            v = j;
                        }
                    }
                }
            }
        }

        visited[v] = 1;
        total += min;
        cout<<"\nConnection : "<<u<<" and "<<v<<";\tcost : "<<min;
    }

    cout<<"\n\nMinimum cost : "<<total;
}

int main() {

    prim ob;
    ob.input();
    ob.output();
    ob.minSpanningTree();

    return 0;
}

/*
OUTPUT:

Enter number of cities : 6

Enter cost of connection between the cities. Enter 0 if no connection exists.
Cost of connection between cities 0 and 1 : 5
Cost of connection between cities 0 and 2 : 0
Cost of connection between cities 0 and 3 : 0
Cost of connection between cities 0 and 4 : 10
Cost of connection between cities 0 and 5 : 8
Cost of connection between cities 1 and 2 : 3
Cost of connection between cities 1 and 3 : 0
Cost of connection between cities 1 and 4 : 11
Cost of connection between cities 1 and 5 : 0
Cost of connection between cities 2 and 3 : 1
Cost of connection between cities 2 and 4 : 6
Cost of connection between cities 2 and 5 : 2
Cost of connection between cities 3 and 4 : 9
Cost of connection between cities 3 and 5 : 0
Cost of connection between cities 4 and 5 : 2

Cost adjacency matrix :
0       5       0       0       10      8
5       0       3       0       11      0
0       3       0       1       6       2
0       0       1       0       9       0
10      11      6       9       0       2
8       0       2       0       2       0

Enter starting city : 2


Minimum Spanning Tree:
Connection : 2 and 3;   cost : 1
Connection : 2 and 5;   cost : 2
Connection : 5 and 4;   cost : 2
Connection : 2 and 1;   cost : 3
Connection : 1 and 0;   cost : 5

Minimum cost : 13

*/