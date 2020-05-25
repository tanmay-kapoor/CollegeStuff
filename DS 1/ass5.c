#include<stdio.h>

int frontl = -1, rearl = -1, frontc = 0, rearc = 0;
int lque[10], cque[10];

int linisfull() {		//To check if linear queue is full
    if(rearl == 9)
        return 1;
    return 0;
}

int linisempty() {		//To check if linear queue is empty
    if(rearl == frontl)
        return 1;
    return 0;
}

int cirisfull() {		//To check if circular queue is full
    if((rearc + 1)%10 == frontc)
        return 1;
    return 0;
}

int cirisempty() {		//To check if circular queue is empty
    if(rearc == frontc)
        return 1;
    return 0;
}

void addlin(int item) {	//Add order in linear queue
    if(!linisfull())
        lque[++rearl] = item;
    else
        printf("Queue full!!\n");
}

int dellin() {			//Recieve order for linear queue
    if(!linisempty())
        return lque[++frontl];
    else
        return 0;
}

void addcir(int item) {	//Add order in circular queue
    if(!cirisfull()) {
        rearc = (rearc+1)%10;
        cque[rearc] = item;
    }
    else
        printf("Queue full!!\n");
}

int delcir() {			//Recieve order for circular queue
    if(!cirisempty()) {
        frontc = (frontc+1)%10;
        return cque[frontc];
    }
    else
        return 0;
}

void dis(int n) {		//Display current running orders
    if(n == 1) {
        if(!linisempty()) {
            for(int i = frontl+1; i <= rearl; i++)
                printf("%d ",lque[i]);
        }
        else 
            printf("No current running orders.");
    }
    else {
        if(!cirisempty()) {
            for(int i = frontc+1; i <= rearc; i++)
                printf("%d ",cque[i]);
        }
        else
            printf("No current running orders.");
    }
    printf("\n");
}

int main() {
    int n, ch, od;
    while(1) {
        printf("1: Linear Queue\n2: Circular Queue\n3: Exit\nChoice: ");
        scanf("%d",&n);
        if(n == 3)
            break;
        if(n != 1 && n != 2 && n != 3){
            printf("Enter Valid choice!!\n");
            continue;
        }
        while(1) {
            printf("1: Add Order\n2: Receive order\n3: Display all current orders");
            printf("\n4: Exit to perform other queue operation\nChoice: ");
            scanf("%d",&ch);
            if(ch == 4)
                break;
            switch(ch) {
                case 1:
                	printf("1: Veg Pizza\n2: Non-veg Pizza\n3: Margareta\nEnter Order No: ");
                    scanf("%d",&od);
                    if(n == 1)
                        addlin(od);
                    else
                        addcir(od);
                    break;
                case 2:
                    if(n == 1)
                        od = dellin();
                    else
                        od = delcir();
                    if(od != 0)
                        printf("Order received is %d\n",od);
                    else
                        printf("No current running orders\n");
                    break;
                case 3:
                    if(n == 1)
                        dis(n);
                    else   
                        dis(0);
                    break;
                default:
                    printf("Enter Valid Choice!!\n");
            }
        }
    }
    return 0;
}
