/*
Tanmay Kapoor
PA-38
Batch A-3
Div A
*/

#include <iostream>
#define max 50
using namespace std;

class heap {
    int n;
    int marks[max+1];

    public:
        heap();
        void minHeap();
        void insertMin(int i);
        void maxHeap();
        void insertMax(int i);
        void display();
};

heap::heap() {
    cout<<"\nEnter number of students : ";
    cin>>n;
}

void heap::minHeap() {
    int i = 1, j = n;
    cout<<"\nEnter marks of "<<n<<" students : \n";
    do {
        cin>>marks[i];
        insertMin(i);
        i++;
        j--;
    }while(j>0);

    cout<<"\nMin heap : ";
    display();
    cout<<"\nMin marks : "<<marks[1]<<"\n";
}

void heap::insertMin(int i) {
    int ele = marks[i];

    while(i>1 && marks[i/2] > ele) {
        marks[i] = marks[i/2];
        i = i/2;
    }
    marks[i] = ele;
}

void heap::maxHeap() {
    int i = 1, j = n;
    cout<<"\nEnter marks of "<<n<<" students : \n";
    do {
        cin>>marks[i];
        insertMax(i);
        i++;
        j--;
    }while(j>0);

    cout<<"\nMax heap : ";
    display();
    cout<<"\nMax marks : "<<marks[1]<<"\n";
}

void heap::insertMax(int i) {
    int ele = marks[i];

    while(i>1 && marks[i/2] < ele) {
        marks[i] = marks[i/2];
        i = i/2;
    }
    marks[i] = ele;
}

void heap::display() {
    for(int i = 1; i<n+1; i++) {
        cout<<marks[i]<<"\t";
    }
}

int main() {
    heap ob;
    int ch;
    do {
        cout<<"\n1. Min Heap\n2. Max Heap\n3. Exit\nEnter choice : ";
        cin>>ch;
        switch(ch) {
            case 1:
                ob.minHeap();
                break;

            case 2:
                ob.maxHeap();
                break;

            case 3:
                break;

            default:
                cout<<"Invalid choice\n";
        }        
    }while(ch != 3);

    return 0;
}

/*
OUTPUT

Enter number of students : 7

1. Min Heap
2. Max Heap
3. Exit
Enter choice : 1

Enter marks of 7 students :
55
65
89
45
99
76
23

Min heap : 23   55      45      65      99      89      76
Min marks : 23

1. Min Heap
2. Max Heap
3. Exit
Enter choice : 2

Enter marks of 7 students :
55
65
89
45
99
76
23

Max heap : 99   89      76      45      55      65      23
Max marks : 99

1. Min Heap
2. Max Heap
3. Exit
Enter choice : 3

*/