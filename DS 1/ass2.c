#include<stdio.h>

struct student {        //Student Structure
	char name[20];
	int rollno;
	int age;
	int div;
};

void swap(struct student* a, struct student* b) {		//Swap Function
	struct student temp = *a;
	*a = *b;
	*b = temp;
}

int len(char *str) {        //length function to calculate length of string
	int i = 0;
	while((*str) != '\0') {
		i++;
		str++;
	}
	return i;
}

int comp(char str1[20], char str2[20]) {    //compare function to compare two strings
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

void copy(struct student* a, struct student* b, int n) {    //copy function to copy one structure instance to another
	int i;
	for(i = 0; i < n; i++) {
		*a = *b;
		a++;
		b++;
	}
}

void getdata(struct student* s, int n) {        //getdata function to input structure values from user
	int i;
	for(i = 0; i < n; i++) {
		printf("Enter name of student %d: ",i+1);
		scanf("%s",s[i].name);
		printf("Enter rollno of student %d: ",i+1);
		scanf("%d",&s[i].rollno);
		printf("Enter age of student %d: ",i+1);
		scanf("%d",&s[i].age);
		printf("Enter division of student %d: ",i+1);
		scanf("%d",&s[i].div);
	}
}

void printall(struct student s[], int n) {				//Display data Function
	int i;
	printf("\nName\t\tRollNo\t\tAge\t\tDivision\n");
	for(i = 0; i < n; i++) {
		printf("%s",s[i].name);
		printf("\t\t%d",s[i].rollno);
		printf("\t\t%d",s[i].age);
		printf("\t\t%d\n",s[i].div);
	}
}

int linearsearch(struct student s[], int n, int key) {	//Linear Search Function
	int i;
	for(i = 0; i < n; i++) {   
		if(s[i].rollno == key)
			return i;
	}
	return -1;
}

int linears(struct student s[], int n, char nm[]) {  //linear search function by name
	int i;
	for(i = 0; i < n; i++) {
		if(!comp(nm, s[i].name)) 
			return i;
	}
	return -1;
}

int binsearchs(struct student s[], int n, char nm[]) {		//Binary Search Function by name
	int low = 0, high = n-1, mid, k = 1;
	while(low <= high) {
		mid = (low + high)/2;
		if(comp(s[mid].name, nm) == 0) {
            printf("\nNo of elements searched is %d\n",k);
			return mid;
        }
		else if(comp(s[mid].name, nm) == 1)
			high = mid-1;
		else 
			low = mid+1;
        k++;
	}
	return -1;
}

int binsearch(struct student s[], int n, int key) {		//Binary Search Function
	int low = 0, high = n-1, mid, k = 1;
	while(low <= high) {
		mid = (low + high)/2;
		if(s[mid].rollno == key) {
            printf("\nNo of elements searched is %d\n",k);
			return mid;
        }
		else if(s[mid].rollno > key)
			high = mid-1;
		else 
			low = mid+1;
        k++;
	}
	return -1;
}

int binsearchrec(struct student s[], int key, int low, int high) {	//Binary Search Recursive Function
	if(low <= high) {
		int mid = (low+high)/2;
		if(s[mid].rollno == key)
			return mid;
		else if(s[mid].rollno < key)
			return binsearchrec(s, key, mid+1, high);
		else 
			return binsearchrec(s, key, low, mid-1);
	}
	else
		return -1;
}

int binrecs(struct student s[], char nm[], int low, int high) {	//Binary Search Recursive Function by name
	if(low <= high) {
		int mid = (low+high)/2;
		if(!(comp(s[mid].name, nm)))
			return mid;
		else if(comp(s[mid].name, nm) == 1)
            return binrecs(s, nm, low, mid-1);
		else
			return binrecs(s, nm, mid+1, high);
	}
	else
		return -1;
}

int bubbsort(struct student* s, int n, int f) {		//Bubble Sort Function
	int i, j, pass = 0, swaps = 0, swapt = 0;
	for(i = 0; i < n-1; i++) {   
		for (j = 0; j < n-i-1; j++) {
            if(f == 1) {
			    if(s[j].rollno > s[j+1].rollno) {
                    swaps++;
				    swap(&s[j], &s[j+1]);
                }
            }
            else {
                if(comp(s[j].name, s[j+1].name) == 1) {
				    swaps++;
				    swap(&s[j], &s[j+1]);
                }
			}
		}
		if(swaps == 0)
			break;
		pass++;
		printall(s, n);
		printf("The no of swaps in pass %d is %d\n\n", pass, swaps);
        swapt += swaps;
		swaps = 0;
	}
    printf("The total no of swaps is %d",swapt);
	return pass;
}

int selection_sort(struct student* s, int n, int f) {	//Selection Sort Function
	int i, j, min, pass = 0, swaps = 0, swapt = 0;
	for (i = 0; i < n-1; i++) {
	    min = i;
	    for (j = i+1; j < n; j++) {
            if(f == 1) {
	            if (s[j].rollno < s[min].rollno) {
				    swaps++;
	                min = j;
	            }
            }
            else {
                if(comp(s[j].name, s[min].name) == -1) {
                    swaps++;
                    min = j;
                }
            }
	    }
		if(swaps > 0) {
	    	swap(&s[i], &s[min]);
	    	pass++;
			printall(s, n);
            swapt += swaps;
			printf("The no of swaps in pass %d is %d\n\n", pass, swaps);
			swaps = 0;
		}
	}
    printf("The total no. of swaps is %d",swapt);
	return pass;
}

int insertion_sort(struct student* s, int n, int f) {       //insertion sort function
	int i, j, ins = 0, pass = 0, inst = 0;
	for(i = 1; i < n; i++) {
		struct student key = s[i];
		j = i - 1;
        if(f == 1) {
		    while(s[j].rollno > key.rollno && j >= 0) {
		    	ins++;
			    s[j+1] = s[j];
			    j--;
	    	}
        }
        else {
            while((comp(s[j].name, key.name) == 1) && j >= 0) {
		    	ins++;
			    s[j+1] = s[j];
			    j--;
	    	}
        }
		if(ins > 0) {
			pass++;
			s[j+1] = key;
			printall(s, n);
			printf("The no of insertions in pass %d is %d\n\n", pass, ins);
		}
        inst += ins;
		ins = 0;
	}
    printf("The total no of insertions is %d",inst);
	return pass;
}

int main() {
	int n, ch, chin, roll, t, pass;
	char nm[20];
	printf("Enter no of students: ");
	scanf("%d",&n);
	struct student s[n], cp[n];
	getdata(s, n);
	copy(cp, s, n);
	printall(cp, n);
	
	while(1) {
		printf("\n1: Linear Search\n2: Binary Search\n3: Binary Search with recursion\n4: Bubble Sort\n");	
		printf("5: Selection Sort\n6: Insertion Sort\n7: Display Data\n8: Enter New Values\n9: Exit\nChoice: ");
		scanf("%d",&ch);

		if(ch == 9) 
			break;
			
		switch(ch) { 
	
			case 1:		//Linear Search
				printf("\n1: Search by name\n2: Search by rollno\nChoice: ");
				while(1) {
					scanf("%d",&chin);
					if(chin == 2) {
						printf("\nEnter rollno of student to search: ");
		    			scanf("%d",&roll);
						t = linearsearch(s, n, roll);
						break;
					}
					else if(chin == 1) {
						printf("\nEnter name of student to search: ");
						scanf("%s",nm);
						t = linears(s, n, nm);
						break;
					}
					else
						printf("Enter Valid Choice: ");
				}
				if(t == -1)
					printf("\nRecord not found\n");
				else
					printf("\nRecord found at location %d\n", t+1);;
			
				break;
		
			case 2:		//Binary Search 
				printf("\n1: Search by name\n2: Search by rollno\nChoice: ");
				while(1) {
					scanf("%d",&chin);
					if(chin == 2) {
						printf("\nEnter rollno of student to search: ");
		    			scanf("%d",&roll);
						t = binsearch(s, n, roll);
						break;
					}
					else if(chin == 1) {
						printf("\nEnter name of student to search: ");
						scanf("%s",nm);
						t = binsearchs(s, n, nm);
						break;
					}
					else
						printf("Enter Valid Choice: ");
				}
				if(t == -1)
					printf("\nRecord not found\n");
				else
					printf("\nRecord found at location %d\n", t+1);;
			
				break;
		
			case 3:		//Binary Search with recursion
				printf("\n1: Search by name\n2: Search by rollno\nChoice: ");
				while(1) {
					scanf("%d",&chin);
					if(chin == 2) {
						printf("\nEnter rollno of student to search: ");
		    			scanf("%d",&roll);
						t = binsearchrec(s, roll, 0, n-1);
						break;
					}
					else if(chin == 1) {
						printf("\nEnter name of student to search: ");
						scanf("%s",nm);
						t = binrecs(s, nm, 0, n-1);
						break;
					}
					else
						printf("Enter Valid Choice: ");
				}
				if(t == -1)
					printf("\nRecord not found\n");
				else
					printf("\nRecord found at location %d\n", t+1);;
			
				break;
		
			case 4:		//Bubble Sort
                printf("\n1: Sort by rollno\n2: Sort by name\nChoice: ");
                while(1) {
                    scanf("%d",&chin);
                    if(chin != 1 && chin != 2) {
                        printf("Enter Valid Choice: ");
                        continue;
                    }
				    pass = bubbsort(s, n, chin);
                    break;
                }   
				copy(s, cp, n);
				if(pass != 0) 
					printf("\nThe total no. of passes is %d\n",pass);
				else
					printf("\nData is already sorted\n");
				break;
			
			case 5:		//Selection Sort
				printf("\n1: Sort by rollno\n2: Sort by name\nChoice: ");
                while(1) {
                    scanf("%d",&chin);
                    if(chin != 1 && chin != 2) {
                        printf("Enter Valid Choice: ");
                        continue;
                    }
				    pass = selection_sort(s, n, chin);
                    break;
                }    
				copy(s, cp, n);
				if(pass != 0) 
					printf("\nThe total no. of passes is %d\n",pass);
				else
					printf("\nData is already sorted\n");
				break;
		
			case 6:		//Insertion Sort
				printf("\n1: Sort by rollno\n2: Sort by name\nChoice: ");
                while(1) {
                    scanf("%d",&chin);
                    if(chin != 1 && chin != 2) {
                        printf("Enter Valid Choice: ");
                        continue;
                    }
				    pass = insertion_sort(s, n, chin);
                    break;
                } 
				copy(s, cp, n);
				if(pass != 0) 
					printf("\nThe total no. of passes is %d\n",pass);
				else
					printf("\nData is already sorted\n");
				break;
	
			case 7:		//Display Data
				printall(s, n);
				break;
				
			case 8:
				printf("\nEnter no of students: ");
				scanf("%d",&n);
				getdata(s, n);
				copy(cp, s, n);
				printall(cp, n);
				break;
		
			default:
				printf("\nEnter Valid Choice\n");
		}
	}
	return 0;
}

/*
Enter no of students: 3
Enter name of student 1: yash
Enter rollno of student 1: 22
Enter age of student 1: 18
Enter division of student 1: 3
Enter name of student 2: harsh
Enter rollno of student 2: 11
Enter age of student 2: 20
Enter division of student 2: 4
Enter name of student 3: zts
Enter rollno of student 3: 44
Enter age of student 3: 17
Enter division of student 3: 6

Name		RollNo		Age		Division
yash		22		18		3
harsh		11		20		4
zts		44		17		6

1: Linear Search
2: Binary Search
3: Binary Search with recursion
4: Bubble Sort
5: Selection Sort
6: Insertion Sort
7: Display Data
8: Enter New Values
9: Exit
Choice: 1

1: Search by name
2: Search by rollno
Choice: 1

Enter name of student to search: yash

Record found at location 1

1: Linear Search
2: Binary Search
3: Binary Search with recursion
4: Bubble Sort
5: Selection Sort
6: Insertion Sort
7: Display Data
8: Enter New Values
9: Exit
Choice: 2

1: Search by name
2: Search by rollno
Choice: 1

Enter name of student to search: harsh

No of elements searched is 1

Record found at location 2

1: Linear Search
2: Binary Search
3: Binary Search with recursion
4: Bubble Sort
5: Selection Sort
6: Insertion Sort
7: Display Data
8: Enter New Values
9: Exit
Choice: 3

1: Search by name
2: Search by rollno
Choice: 1

Enter name of student to search: yas

Record not found

1: Linear Search
2: Binary Search
3: Binary Search with recursion
4: Bubble Sort
5: Selection Sort
6: Insertion Sort
7: Display Data
8: Enter New Values
9: Exit
Choice: 4

1: Sort by rollno
2: Sort by name
Choice: 1

Name		RollNo		Age		Division
harsh		11		20		4
yash		22		18		3
zts		44		17		6
The no of swaps in pass 1 is 1

The total no of swaps is 1
The total no. of passes is 1

1: Linear Search
2: Binary Search
3: Binary Search with recursion
4: Bubble Sort
5: Selection Sort
6: Insertion Sort
7: Display Data
8: Enter New Values
9: Exit
Choice: 5

1: Sort by rollno
2: Sort by name
Choice: 1

Name		RollNo		Age		Division
harsh		11		20		4
yash		22		18		3
zts		44		17		6
The no of swaps in pass 1 is 1

The total no. of swaps is 1
The total no. of passes is 1

1: Linear Search
2: Binary Search
3: Binary Search with recursion
4: Bubble Sort
5: Selection Sort
6: Insertion Sort
7: Display Data
8: Enter New Values
9: Exit
Choice: 6

1: Sort by rollno
2: Sort by name
Choice: 1

Name		RollNo		Age		Division
harsh		11		20		4
yash		22		18		3
zts		44		17		6
The no of insertions in pass 1 is 1

The total no of insertions is 1
The total no. of passes is 1

1: Linear Search
2: Binary Search
3: Binary Search with recursion
4: Bubble Sort
5: Selection Sort
6: Insertion Sort
7: Display Data
8: Enter New Values
9: Exit
Choice: 9
*/
