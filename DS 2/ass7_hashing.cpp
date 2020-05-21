/*
Tanmay Kapoor
Div A
PA-38
Batch A3
*/

#include <iostream>
#include <string>
#define max 10
using namespace std;

class Student {

    int roll;
    string name;
    string grade;

    public:
        Student() {
            roll = -1;
            name = "";
            grade = "";
        }

        friend class Hash;
};

class Hash {

    Student hashTable[max];

    public:
        Hash();
        Student accept();
        void linearWithoutReplacement();
        void linearWithReplacement();
        void display();
};

Hash::Hash() {

    for(int i = 0; i<max; i++) {
        hashTable[i].roll = -1;
        hashTable[i].name = "";
        hashTable[i].grade = "";
    }
}

Student Hash::accept() {

    Student s;

    cout<<"Enter student details :\n";
    cout<<"\tName : ";
    cin>>s.name;
    cout<<"\tRoll no. : ";
    cin>>s.roll;
    cout<<"\tGrade : ";
    cin>>s.grade;

    return s;
}

void Hash::linearWithoutReplacement() {

    Student s = accept();
    int index = s.roll % max;

    if(hashTable[index].roll == -1) {
        hashTable[index] = s;
    } else {
        int i = 1;
        i = (index+i) % max;

        while(i != index) {
            if(hashTable[i].roll == -1) {

                hashTable[i] = s;
                break;
            }

            i = (i+1) % max;
        }
    }
}

void Hash::linearWithReplacement() {

    Student s = accept();
    int index = s.roll % max;

    if(hashTable[index].roll == -1) {
        hashTable[index] = s;
    } else {
        Student temp = s;

        if(hashTable[index].roll % max != index) {
            temp = hashTable[index];
            hashTable[index] = s;
        } 

        int i = 1;
        i = (index+i) % max;

        while(i != index) {
            if(hashTable[i].roll == -1) {

                hashTable[i] = temp;
                break;
            }

            i = (i+1) % max;
        }    
    }
}

void Hash::display() {

    cout<<"Roll no.\tName\tGrade\n";

    for (int i = 0; i<max; i++) {
         cout<<hashTable[i].roll<<"\t\t"<<hashTable[i].name<<"\t"<<hashTable[i].grade<<"\n";
    }
}

int main() {

    Hash h;
    int ch, counter = 0;

    do {
        cout<<"\n1. Add student using Linear Probing without replacement\n2. Add student using Linear Probing with replacement\n3. Display all student records\n4. Exit\nEnter choice : ";
        cin>>ch;

        switch(ch) {

            case 1:
                if(counter == 10) {
                    cout<<"Max records entered. Can't add more\n";
                } else {
                    h.linearWithoutReplacement();
                    counter++;
                }

                break;

            case 2:
                if(counter == 10) {
                    cout<<"Max records entered. Can't add more\n";
                } else {
                    h.linearWithReplacement();
                    counter++;
                }

                break;
                
            case 3:
                h.display();
                break;

            case 4:
                break;

            default:
                cout<<"Invalid choice. Enter again\n";
        }
    }while(ch != 4);

    return 0;
}

/*
OUTPUT

1. Add student using Linear Probing without replacement
2. Add student using Linear Probing with replacement   
3. Display all student records
4. Exit
Enter choice : 1
Enter student details :
        Name : Tanmay
        Roll no. : 38
        Grade : A

1. Add student using Linear Probing without replacement
2. Add student using Linear Probing with replacement   
3. Display all student records
4. Exit
Enter choice : 1
Enter student details :
        Name : Afraz
        Roll no. : 21
        Grade : A+

1. Add student using Linear Probing without replacement
2. Add student using Linear Probing with replacement   
3. Display all student records
4. Exit
Enter choice : 2
Enter student details :
        Name : Saloni
        Roll no. : 41
        Grade : B

1. Add student using Linear Probing without replacement
2. Add student using Linear Probing with replacement
3. Display all student records
4. Exit
Enter choice : 1
Enter student details :
        Name : Aditya
        Roll no. : 42
        Grade : A-

1. Add student using Linear Probing without replacement
2. Add student using Linear Probing with replacement
3. Display all student records
4. Exit
Enter choice : 1
Enter student details :
        Name : Manas
        Roll no. : 32
        Grade : B+

1. Add student using Linear Probing without replacement
2. Add student using Linear Probing with replacement
3. Display all student records
4. Exit
Enter choice : 3
Roll no.        Name    Grade
-1
21              Afraz   A+
41              Saloni  B
42              Aditya  A-
32              Manas   B+
-1
-1
-1
38              Tanmay  A
-1

1. Add student using Linear Probing without replacement
2. Add student using Linear Probing with replacement
3. Display all student records
4. Exit
Enter choice : 4

*/