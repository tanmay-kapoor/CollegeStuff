#include<stdio.h>
#include <stdbool.h>

void invert(int *k) {
	if(*k == 1)
		*k = 0;
	else
		*k = 1;
}

int main() {
	int dt[4], cd[7];
	int i;
	printf("Enter Data word:\n");
	for(i = 0; i < 4; i++)
		scanf("%d",&dt[i]);
	for(i = 0; i < 4; i++)
		cd[i] = dt[i];
	cd[4] = (dt[2] ^ dt[3]) ^ dt[0]; 	//r2
	cd[5] = (dt[0] ^ dt[1]) ^ dt[2];	//r1
	cd[6] = (dt[1] ^ dt[2]) ^ dt[3];	//r0
	printf("Code Word: ");
	for(i = 0; i < 7; i++)
		printf("%d",cd[i]);
	printf("\n");
	printf("Enter Code Word:\n");
	for(i = 0; i < 7; i++)
		scanf("%d",&cd[i]);
	int s[3];
	s[0] = ((cd[1] ^ cd[2]) ^ cd[3]) ^ cd[6];
	s[1] = ((cd[0] ^ cd[1]) ^ cd[2]) ^ cd[5];
	s[2] = ((cd[2] ^ cd[3]) ^ cd[0]) ^ cd[4];
	if(s[0] == 1 && s[1] == 1 && s[2] == 0)
		invert(&cd[1]);
	else if(s[0] == 1 && s[1] == 0 && s[2] == 1)
		invert(&cd[3]);
	else if(s[0] == 0 && s[1] == 1 && s[2] == 1)
		invert(&cd[0]);
	else if(s[0] == 1 && s[1] == 1 && s[2] == 1)
		invert(&cd[2]);
	else
		printf("No error\n");
	printf("Extracted Data Word: ");
	for(i = 0; i < 4; i++)
		printf("%d",cd[i]);
	printf("\n");
	return 0;
}
	
/*
Enter Data word:
1
0
0
1
Code Word: 1001011
Enter Code Word:
1
0
0
1
0
1
1
No error
Extracted Data Word: 1001	
*/
