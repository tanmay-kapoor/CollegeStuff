#include<stdio.h>
#include<stdlib.h>

int len(char *str) {
	int i = 0;
	while((*str) != '\0') {
		i++;
		str++;
	}
	return i;
}

void copy(char *str1, char *str2) {
	while((*str1) != '\0') {
		*str2 = *str1;
		str1++;
		str2++;
	}
	*str2 = '\0';
}

void concat(char *str1, char *str2) {
	int i = len(str1);
	str1 += i;
	while((*str2) != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
}

void reverse(char *str1, char *str2) {
	int i = 0;
	while((*str1) != '\0') {
		*(str2+len(str1) - i - 1) = *str1;
		i++;
		str1++;
		str2++;
	}
	*str2 = '\0';
}

int comp(char str1[20], char str2[20]) {
	int i = 0;
	while(i < len(str1)) {
		if(str1[i] > str2[i]) 
			return 1;
		else if(str1[i] < str2[i]) 
			return -1;
		i++;
	}
	return 0;
}

int palin(char str[20]) {
	char str1[20];
	copy(str,str1);
	reverse(str,str);
	if(comp(str,str1) == 0)
		return 1;
	return 0;
}

int substr(char str[20], char sub[20]) {
	int l1 = len(str);
	int l2 = len(sub);
	int i, count, j, count1 = 0;
	if(l2 > l1) {
		return 0;
	}
	for (i = 0; i < l1;) {
        j = 0;
        count = 0;
        while ((str[i] == sub[j]) && j < l2 && i < l1) {
            count++;
            i++;
            j++;
        }
        if (count == l2) {
            count1++;                                   
            count = 0;
			i--;
        }
        else
            i++;
    }
    return count1;
}

void del(char *str) {
	*str = '\0';
}

int main() { 
	
	int n;
	char str[20],str1[20],str2[20];
	
	while(1) {
		printf("1: Length\n2: Copy\n3: Concat\n4: Reverse\n5: Compare\n6: Palindrome\n7: Substring\n8: Delete\n9: Exit\nEnter Choice: ");
		scanf("%d",&n);
		switch(n) {
			case 1:    //for length
				printf("Enter string: ");
				scanf("%s",str);
				int i = len(str);
				printf("The length of string is %d\n\n",i);
				break;
	
			case 2:   //for copy
				printf("Enter string: ");
				scanf("%s",str1);
				copy(str1,str2);
				printf("String copied is %s\n\n", str2);
				break;
	
			case 3:   //for concat
				printf("Enter strings: ");
				scanf("%s%s",str1,str2);
				concat(str1,str2);
				printf("Concatinated string is %s\n\n",str1);
				break;
	
			case 4:     //for reverse
				printf("Enter string: ");
				scanf("%s",str1);
				reverse(str1, str2);
				printf("The reversed string is %s\n\n",str2);
				break;
	
			case 5:  //for compare
				printf("Enter strings: ");
				scanf("%s%s",str1,str2);
				int j = comp(str1,str2);
				if(j > 0) 
					printf("First string is greater\n\n");
				else if(j < 0)
					printf("Second string is greater\n\n");
				else
					printf("Strings are equal\n\n");
				break;
	
			case 6:  //for palindrome
				printf("Enter string: ");
				scanf("%s",str);
				int b = palin(str);
				if(b)
					printf("String is palindrome\n\n");
				else
					printf("String is not palindrome\n\n");
				break;
	
			case 7:     //for substring
				printf("Enter string: ");
				scanf("%s",str1);
				printf("Enter substring: ");
				scanf("%s",str2);
				int count = substr(str1,str2);
				if(count == 0) 
					printf("No occurences\n\n");
				else
					printf("The no of occurences is %d\n\n",count);
				break;
		
			case 8:  //for delete
				printf("Enter string: ");
				scanf("%s",str);
				del(str);
				printf("String deleted\n%s",str);
				break;

			case 9:
				exit(0);
				
			default:
				printf("enter vaild choice\n");
		}
	}
	return 0;
}

/* Output
1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 1
Enter string: tanmay
The length of string is 6

1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 2
Enter string: dfs
String copied is dfs

1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 3
Enter strings: tanmay
hello
Concatinated string is tanmayhello

1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 4
Enter string: tanmay
The reversed string is yamnat

1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 5
Enter strings: tanmay
tanmay
Strings are equal

1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 6
Enter string: malayalam
String is palindrome

1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 7
Enter string: sgaisgagaga
Enter substring: aga
The no of occurences is 2

1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 8
Enter string: yag
String deleted
1: Length
2: Copy
3: Concat
4: Reverse
5: Compare
6: Palindrome
7: Substring
8: Delete
9: Exit
Enter Choice: 
*/
