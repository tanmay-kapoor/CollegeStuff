/*
Tanmay Kapoor
Batch: A3
Pa-38
*/

#include <iostream>
using namespace std;

class tbtnode {

    int data;
    bool rbit, lbit;
    tbtnode *right, *left;
    friend class tbt;

    public:
        tbtnode();
};

tbtnode::tbtnode() {
    lbit = 1;
    rbit = 1;
}

class tbt {

    tbtnode *head;

    public:
        void create();
        void inorder();
        tbtnode *in_succ(tbtnode *);
        void preorder();
        tbt(); 
};

tbt::tbt() {

    head = new tbtnode();
    head->rbit = 0;
    head->right = head;
    head->left = head;
}

void tbt ::create() {

    tbtnode *root;
    root = new tbtnode();

    cout << "\nEnter the data for root node: ";
    cin >> root->data;

    head->lbit = 0;
    head->left = root;
    root->left = head;
    root->right = head;

    int x;

    do {
        int flag = 0;
        char pos;
        tbtnode *temp;
        temp = root;
        tbtnode *curr;
        curr = new tbtnode();

        cout << "\nEnter the data: ";
        cin >> curr->data;

        while (flag == 0) {

            cout << "Do you want to enter node to left [l] or right [r] of " << temp->data << " ?\t";
            cin >> pos;

            if (pos == 'l') {

                if (temp->lbit == 1) {

                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 0;
                    flag = 1;
                } else {
                    temp = temp->left;
                }
            }
            if (pos == 'r') {

                if (temp->rbit == 1) {

                    curr->left = temp;
                    curr->right =  temp->right;
                    temp->right = curr;
                    temp->rbit = 0;
                    flag = 1;
                } else {
                    temp = temp->right;
                }   
            }
        }
        cout << "\n'1' to continue, Otherwise '0': ";
        cin >> x;
    } while (x == 1);
}

void tbt ::inorder() {

    tbtnode *temp;
    temp = head;
    while (1) {

        temp = in_succ(temp);
        if (temp == head)
            break;
        cout << temp->data << "\t";
    }
}

tbtnode *tbt::in_succ(tbtnode *temp) {

    tbtnode *s;
    s = temp->right;

    if (temp->rbit == 0) {

        while (s->lbit == 0)
            s = s->left;
    }
    return s;
}

void tbt::preorder() {

    tbtnode *temp;
    temp = head->left;
    while (temp != head) {

        cout << temp->data << "\t";
        while (temp->lbit != 1) {

            temp = temp->left;
            cout << temp->data << "\t";
        }
        while (temp->rbit == 1)
            temp = temp->right;
        temp = temp->right;
    }
}

int main() {

    tbt t1;
    int ch;

    do {
        cout << "\n\nEnter the operation you want to perform: ";
        cout << "\n1. Create a Threaded Binary Tree";
        cout << "\n2. Display [Inorder] Threaded Binary Tree";
        cout << "\n3. Display [Preorder] Threaded Binary Tree";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {

            case 1:
                t1.create();
                cout << "\nTree created successfully";
                break;

            case 2:
                cout << "\nInorder:\t";
                t1.inorder();
                break;

            case 3:
                cout << "\nPreorder:\t";
                t1.preorder();
                break;

            case 4:
                break;

            default:
                cout << "\nINVALID INPUT";
        }
    } while (ch != 4);

    return 0;
}

/*
OUTPUT

Enter the operation you want to perform:  
1. Create a Threaded Binary Tree
2. Display [Inorder] Threaded Binary Tree 
3. Display [Preorder] Threaded Binary Tree
4. Exit
Enter your choice: 1

Enter the data for root node: 1

Enter the data: 2
Do you want to enter node to left [l] or right [r] of 1 ?       l

'1' to continue, Otherwise '0': 1

Enter the data: 3
Do you want to enter node to left [l] or right [r] of 1 ?       r

'1' to continue, Otherwise '0': 1

Enter the data: 4
Do you want to enter node to left [l] or right [r] of 1 ?       l
Do you want to enter node to left [l] or right [r] of 2 ?       l

'1' to continue, Otherwise '0': 1

Enter the data: 5
Do you want to enter node to left [l] or right [r] of 1 ?       l
Do you want to enter node to left [l] or right [r] of 2 ?       r

'1' to continue, Otherwise '0': 0

Tree created successfully

Enter the operation you want to perform:
1. Create a Threaded Binary Tree
2. Display [Inorder] Threaded Binary Tree
3. Display [Preorder] Threaded Binary Tree
4. Exit
Enter your choice: 2

Inorder:        4       2       5       1       3

Enter the operation you want to perform:
1. Create a Threaded Binary Tree
2. Display [Inorder] Threaded Binary Tree
3. Display [Preorder] Threaded Binary Tree
4. Exit
Enter your choice: 3

Preorder:       1       2       4       5       3

Enter the operation you want to perform:
1. Create a Threaded Binary Tree
2. Display [Inorder] Threaded Binary Tree
3. Display [Preorder] Threaded Binary Tree
4. Exit
Enter your choice: 4

*/