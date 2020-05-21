/*
Name: Tanmay Kapoor
Divison: A
Batch: A3
Roll no.: PA-38
*/                               

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

class Gnode {
    string username;
    int id;
    Gnode *next;

public:
    Gnode() {
        id = 0;
        username = "\0";
        next = NULL;
    }
    friend class graph;
};

class graph {

    Gnode *head[20];
    int n;

public:
    void create();
    void adj_list();
    void DFS_n();
    void DFS_n(int pos, int *);
    void DFS_nr();
    void BFS_nr();
};

void graph::create() {

    cout << "Enter number of users: ";
    cin >> n;
    for (int i = 0; i < n; i++) {

        head[i] = new Gnode;
        cout << "\nEnter Username: ";
        cin >> head[i]->username;
        cout << "Enter User-ID: ";
        cin >> head[i]->id;
    }

    int choice;
    for (int j = 0; j < n; j++) {

        Gnode *temp, *curr;
        temp = head[j];

        do {
            curr = new Gnode;
            cout << "\nEnter names who are friends with " << head[j]->username << " : ";
            cin >> curr->username;
            curr->next = NULL;

            if (curr->username == head[j]->username) {

                cout << "Same username exists." << endl;
                delete curr;
            } else {

                temp->next = curr;
                temp = temp->next;
            }

            cout << "'1' to continue, Otherwise '0':\t";
            cin >> choice;
        } while (choice == 1);
    }
}

void graph::adj_list() {

    Gnode *temp;
    cout << "\nUsers and their friend list\n";
    for (int j = 0; j < n; j++) {

        temp = head[j];
        temp = temp->next;
        cout << "\n";
        cout << head[j]->username << "\t\t\t\t:\t";
        while (temp != NULL) {

            cout << temp->username << "\t\t";
            temp = temp->next;
        }
    }
}

void graph::DFS_n() {

    int visited[n];
    string name;

    for (int j = 0; j < n; j++)
        visited[j] = 0;

    cout << "\nEnter starting name: ";
    cin >> name;

    int pos = 0;
    while (name != head[pos]->username)
        pos++;

    cout << "DFS:\t";
    DFS_n(pos, visited);
}

void graph::DFS_n(int pos, int *visited) {

    cout << head[pos]->username << "\t\t";
    visited[pos] = 1;

    int loc = 0;
    Gnode *temp;

    for (temp = head[pos]->next; temp != NULL; temp = temp->next) {

        while (temp->username != head[loc]->username)
            loc++;

        if (!visited[loc])
            DFS_n(loc, visited);
    }
}

void graph::DFS_nr() {

    stack<int> s;
    int visited[n];
    string name;

    for (int j = 0; j < n; j++)
        visited[j] = 0;

    cout << "\nEnter starting name: ";
    cin >> name;

    int pos = 0;
    while (name != head[pos]->username)
        pos++;

    s.push(pos);

    do {
        pos = s.top();
        s.pop();
        cout << head[pos]->username << "\t\t";
        visited[pos] = 1;

        Gnode *temp;
        int loc = 0;

        for (temp = head[pos]->next; temp != NULL; temp = temp->next) {

            while (temp->username != head[loc]->username)
                loc++;

            if (!visited[loc]){
                s.push(loc);
                visited[loc] = 1;
            }
        }
    } while (!s.empty());
}

void graph::BFS_nr() {

    queue<int> q;
    int visited[n];
    string name;

    for (int j = 0; j < n; j++)
        visited[j] = 0;

    cout << "\nEnter starting name: ";
    cin >> name;

    int pos = 0;
    while (name != head[pos]->username)
        pos++;

    q.push(pos);
    visited[pos] = 1;

    while (!q.empty()) {

        pos = q.front();
        q.pop();
        cout << head[pos]->username << "\t\t";
        Gnode *temp;
        int loc = 0;

        for (temp = head[pos]->next; temp != NULL; temp = temp->next) {

            while (temp->username != head[loc]->username)
                loc++;

            if (!visited[loc]) {
                q.push(loc);
                visited[loc] = 1;
            }
        }
    }
}

int main() {

    graph g;
    int ch;
    do {
        cout << "\n\n1. Create";
        cout << "\n2. Display Adjacency List";
        cout << "\n3. DFS";
        cout << "\n4. DFS [Non-recursive]";
        cout << "\n5. BFS [Non-recursive]";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {

            case 1:
                g.create();
                break;

            case 2:
                g.adj_list();
                break;

            case 3:
                g.DFS_n();
                break;

            case 4:
                cout << "DFS:\t";
                g.DFS_nr();
                break;

            case 5:
                cout << "BFS:\t";
                g.BFS_nr();
                break;

            case 6:
            break;

            default:
                cout << "Invalid Input";
        }
    } while (ch !=6 );

    return 0;
}

/*
OUTPUT

1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
6. Exit
Enter your choice: 1
Enter number of users: 5

Enter Username: Tanmay
Enter User-ID: 1

Enter Username: Apoorv
Enter User-ID: 2

Enter Username: Manas
Enter User-ID: 3

Enter Username: Afraz
Enter User-ID: 4

Enter Username: Anany
Enter User-ID: 5

Enter names who are friends with Tanmay : Apoorv
'1' to continue, Otherwise '0': 1

Enter names who are friends with Tanmay : Manas
'1' to continue, Otherwise '0': 0

Enter names who are friends with Apoorv : Tanmay
'1' to continue, Otherwise '0': 1

Enter names who are friends with Apoorv : Manas
'1' to continue, Otherwise '0': 1

Enter names who are friends with Apoorv : Afraz
'1' to continue, Otherwise '0': 1

Enter names who are friends with Apoorv : Anany
'1' to continue, Otherwise '0': 0

Enter names who are friends with Manas : Tanmay
'1' to continue, Otherwise '0': 1

Enter names who are friends with Manas : Apoorv
'1' to continue, Otherwise '0': 0

Enter names who are friends with Afraz : Apoorv
'1' to continue, Otherwise '0': 1

Enter names who are friends with Afraz : Anany
'1' to continue, Otherwise '0': 0

Enter names who are friends with Anany : Apoorv
'1' to continue, Otherwise '0': 1

Enter names who are friends with Anany : Afraz
'1' to continue, Otherwise '0': 0


1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
6. Exit
Enter your choice: 2

Users and their friend list

Tanmay                          :       Apoorv          Manas
Apoorv                          :       Tanmay          Manas           Afraz           Anany
Manas                           :       Tanmay          Apoorv
Afraz                           :       Apoorv          Anany
Anany                           :       Apoorv          Afraz

1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
6. Exit
Enter your choice: 4
DFS:
Enter starting name: Apoorv
Apoorv          Anany           Afraz           Manas           Tanmay

1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
6. Exit
Enter your choice: 5
BFS:
Enter starting name: Apoorv
Apoorv          Tanmay          Manas           Afraz           Anany

1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
6. Exit
Enter your choice: 3

Enter starting name: Apoorv
DFS:    Apoorv          Tanmay          Manas           Afraz           Anany

1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
6. Exit
Enter your choice: 6

*/