#include <stdio.h>
#include <string.h>
#include "stack.h"

int icp(char ch) {
	if(ch == '+' || ch == '-')
		return 1;
	if(ch == '*' || ch == '/')
		return 2;
	if(ch == '^')
		return 4;
	if(ch == '(')
		return 5;
	else
		return 0;
}

int isp(char ch) {
	if(ch == '+' || ch == '-')
		return 1;
	if(ch == '*' || ch == '/')
		return 2;
	if(ch == '^')
		return 3;
	else
		return 0;
}

void display() {
	for(int i = top; i >= 0; i--) 
		printf("%d ",stack[i]);
}

int operator(char ch) {
	char a[] = "+-/*^()";
	for(int i = 0; i < 7; i++) {
		if(a[i] == ch)
			return 1;
	}
	return 0;
}

int operand(char ch) {
	char a[] = "qazwsxedcrfvtgbyhnujmikolpPLOIKMJUYHNTGBRFVEDCWSXQAZ";
	for(int i = 0; i < 52; i++) {
		if(a[i] == ch)
			return 1;
	}
	return 0;
}

void in_post(char inexp[20]) {
    char *e, x;
    e = inexp;
    while(*e != '\0') {
        if(!operator(*e))
            printf("%c", *e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')') {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else {
            while(isp(stack[top]) >= icp(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
        printf("%c",pop());
	printf("\n");
}

void post_pre(char postexp[20]) {
    int i, len;
    len = strlen(postexp);
    for(i = len - 1; i >= 0; i--)
        printf("%c", postexp[i]); 
	printf("\n");
}

void pre_post(char preexp[20]) {
	int i;
	char op1, op2, sym, temp;
	for(i = strlen(preexp)-1; i >= 0; i--) {
		sym = preexp[i];
		temp = sym;
		if(sym != '\0') {
			if(operator(sym)) {
				op1 = pop();
				op2 = pop();
				if(operand(op2))	
					printf("%c%c%c", op1, op2, temp);
				else
					printf("%c%c",op1, temp);
			}
			else
			    push(temp);
		}	
	}
	printf("\n");
}

int main() {
	char exp[20];
	int n;
	while(1) {
		printf("Enter Characters for operation: ");
		scanf("%s",exp);
		printf("1: Infix to Postfix\n2: Postfix to Prefix\n3: Prefix to Postfix\n4: Exit\nChoice: ");
		scanf("%d",&n);
		switch(n) {
			case 1:
				printf("The Postfix expression is: ");
				in_post(exp);
				break;
			case 2:
				printf("The Prefix expression is: ");
				post_pre(exp);
				break;
			case 3:
				printf("The Postfix expression is: ");
				pre_post(exp);
				break;
			case 4:
				return 0;
			default:
				printf("Enter Valid Choice!\n");
		}
	}
	return 0;
}
