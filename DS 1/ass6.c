#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void create(struct node* head) {            //Function for creating a list
    struct node* temp = malloc(sizeof(struct node));
    temp = head;
    int n;
    while(1) {
        struct node* curr = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&curr->data);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        printf("1: Continue\n2: Exit\nChoice: ");
        scanf("%d",&n);
        if(n == 2) 
            break;
    }
}

void display(struct node* head) {           //Function for displaying the list
    struct node* curr = malloc(sizeof(struct node));
    if(head->next == NULL)
        printf("List is empty\n");
    else {
        curr = head->next;
        while(curr) {
            printf("%d ",curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

int len(struct node* head) {                //Function to calculate no. of nodes in list
    struct node* curr = malloc(sizeof(struct node));
    if(head->next == NULL) {
        printf("List is empty\n");
        return 0;
    }
    else {
        curr = head->next;
        int count = 0;
        while(curr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
}

void insert(struct node* head) {            //Function to insert element at a certain position in list
    struct node* curr = malloc(sizeof(struct node));
    struct node* nnode = malloc(sizeof(struct node));
    int i = 1, n, k;
    curr = head;
    printf("Enter position: ");
    scanf("%d",&n);
    k = len(head);
    if(n > k+1)
        printf("Enter valid position\n");
    else {
        printf("Enter data: ");
        scanf("%d",&nnode->data);
        while(curr && i < n) {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
    }
}

struct node* reverse(struct node* head) {   //Function to reverse the list
    struct node* ptr = malloc(sizeof(struct node));
    struct node* mid = malloc(sizeof(struct node));
    struct node* prev = malloc(sizeof(struct node));
    ptr = head->next, mid = NULL, prev = NULL;
    while(ptr) {
        prev = mid;
        mid = ptr;
        ptr = ptr->next;
        mid->next = prev;
    }
    head->next = mid;
    return head;
}

void delpos(struct node* head) {            //Function to delete a node from a certain position in list
    struct node* curr = malloc(sizeof(struct node));
    struct node* prev = malloc(sizeof(struct node));
    struct node* temp = malloc(sizeof(struct node));
    prev = head;
    curr = prev->next;
    int n, ctr = 0;
    printf("Enter Position: ");
    scanf("%d",&n);
    if(n > len(head))
        printf("Can't Delete\n");
    else {
        while(ctr < n && curr) {
            if(ctr == n - 1) {
                temp = curr;
                prev->next = curr->next;
                curr->next = NULL;
                free(temp);
                return;
            }
            prev = curr;
            curr = curr->next;
            ctr++;
        }
    }
}

void swap(struct node* a, struct node* b) {     //Function to swap two nodes
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
}

void sort(struct node *head)  {                 //Function to sort the lists
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
    if (head->next == NULL) {
        printf("List is empty\n");
        return;
    }
    do { 
        swapped = 0; 
        ptr1 = head->next; 
        while (ptr1->next != lptr) { 
            if (ptr1->data > ptr1->next->data) {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}

void merge(struct node* h1, struct node* h2) {      //Function to merge two sorted two lists
    struct node* curr1 = malloc(sizeof(struct node));
    struct node* curr2 = malloc(sizeof(struct node));
    struct node* temp = malloc(sizeof(struct node));
    int flag;
    curr1 = h1->next;
    curr2 = h2->next;
    if(curr1->data < curr2->data) {
        temp = h1;
        flag = 1;
    }
    else {
        temp = h2;
        flag = 0;
    }
    while(curr1 && curr2) {
        if(curr1->data < curr2->data) {
            temp->next = curr1;
            temp = curr1;
            curr1 = curr1->next;
        }
        else {
            temp->next = curr2;
            temp = curr2;
            curr2 = curr2->next;
        }
    }
    if(curr1 == NULL)
        temp->next = curr2;
    if(curr2 == NULL)
        temp->next = curr1;
    if(flag == 1)
        display(h1);
    else
        display(h2);
}

int main() {
    struct node* head = malloc(sizeof(struct node));
    struct node* h1 = malloc(sizeof(struct node));
    struct node* h2 = malloc(sizeof(struct node));
    head->next = NULL;
    h1->next = NULL;
    h2->next = NULL;
    int ch;
    while(1) {
        printf("0: Create\n1: Insert Node\n2: Delete Node\n3: Display List\n4: Reverse List\n5: Sort List\n6: Merge Lists\n7: Exit\nChoice: ");
        scanf("%d",&ch);
        if(ch == 7)
            break;
        switch(ch) {
            case 0:
                create(head);
                break;
            case 1:
                insert(head);
                break;
            case 2:
                delpos(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                reverse(head);
                break;
            case 5:
                sort(head);
                break;
            case 6:
                printf("Enter for first list\n");
                create(h1);
                printf("Enter for second list\n");
                create(h2);
                merge(h1,h2);
                break;
        }
    }
    return 0;
}