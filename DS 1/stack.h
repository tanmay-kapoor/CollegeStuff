#ifndef stack_H_ 
#define stack_H_

char stack[20];
int top = -1;

int isempty() {
	if(top == -1)
		return 1;
	return 0;
}

int isfull() {
	if(top == 19)
		return 1;
	return 0;
}

void push(char x) {
    stack[++top] = x;
}
 
char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

#endif