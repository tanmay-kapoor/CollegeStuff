#include<stdio.h>
#define max 5

void accept(int a[max], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
}

void display(int a[max], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d  ", a[i]);
	}
}

void ascending(int a[max], int n)
{
	int i, j, temp;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j]>a[j+1])
			{
				temp= a[j];
				a[j]= a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void descending(int a[max], int n)
{
	int i, j, temp;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j]<a[j+1])
			{
				temp= a[j];
				a[j]= a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int main()
{
	int ch, a[max], n;
	//int pid();
	printf("\nEnter  number of elements: ");
	scanf("%d", &n);
	accept(a, n);
	printf("\nEnter operation to perform:\n1. Arrange in Ascending order\n2. Arrange in Descending order");
	scanf("%d", &ch);
	switch(ch)
	{	
		case 1:
			ascending(a, n);
			display(a, n);
			break;
		
		case 2:
			descending(a, n);
			display(a, n);
			break;
		
		default:
			printf("\nEnter valid option");
			break;	
	}
}



/*Enter  number of elements: 4

 10
 5
 20
 15
 Enter operation to perform:\n1. Arrange in Ascending order\n2. Arrange in Descending order: 1

 5 10 15 20

 Enter operation to perform:\n1. Arrange in Ascending order\n2. Arrange in Descending order: 2

 20 15 10 5*/


