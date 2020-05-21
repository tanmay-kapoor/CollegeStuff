/*
Tanmay Kapoor
SYBtech div A
PA 38
*/

#include<iostream>
using namespace std;

class node
{
	int coeff;
	int exp;
	node *next;
	friend class poly;
};

class poly
{
	node *head;									//private member
	public:
		poly();
		void create_poly();
		void add_poly(poly p1, poly p2);
		void display();
		void evaluate(int x);
		void sub_poly(poly p1, poly p2);
};

poly::poly()									//constructor for allocating memory to head node
{
	head = new node();
	head->next = head;
	head->exp = -1;
}

void poly::create_poly()
{
	int ch;
	node *curr,*temp;
	temp = head;
	do
	{
		curr = new node();
		cout<<"Enter coeff : ";
		cin>>curr->coeff;
		cout<<"Enter exp : ";
		cin>>curr->exp;
		curr->next = head;
		temp->next = curr;
		temp = curr;
		do
		{
			cout<<"\n1. Add another node\n2. Exit\nEnter choice : ";
			cin>>ch;
			switch(ch)
			{
				case 1:
				break;
				case 2:
				break;
				default:
					cout<<"Invalid choice";	
			}
		}while(ch<1 || ch>2);
		cout<<"\n\n";
	}while(ch==1);
}

void poly::add_poly(poly p1, poly p2)
{
	node *temp1, *temp2,*temp3,*curr;
	temp1 = p1.head->next;
	temp2 = p2.head->next;
	temp3 = head;
	while(temp1->exp!=-1 || temp2->exp!=-1)
	{
		curr = new node();
		if(temp1->exp == temp2->exp)
		{
			curr->exp = temp1->exp;
			curr->coeff = temp1->coeff + temp2->coeff;
			curr->next = head;
			temp3->next = curr;
			temp3 = curr;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		
		else if(temp1->exp > temp2->exp)
		{
			curr->exp = temp1->exp;
			curr->coeff = temp1->coeff;
			curr->next = head;
			temp3->next = curr;
			temp3 = curr;
			temp1 = temp1->next;
		}
		
		else
		{
			curr->exp = temp2->exp;
			curr->coeff = temp2->coeff;
			curr->next = head;
			temp3->next = curr;
			temp3 = curr;
			temp2 = temp2->next;
		}
	}
}

void poly::sub_poly(poly p1, poly p2)
{
	node *temp1, *temp2,*temp3,*curr;
	temp1 = p1.head->next;
	temp2 = p2.head->next;
	temp3 = head;
	while(temp1->exp!=-1 || temp2->exp!=-1)
	{
		curr = new node();
		if(temp1->exp == temp2->exp)
		{
			curr->exp = temp1->exp;
			curr->coeff = (temp1->coeff - temp2->coeff);
			curr->next = head;
			temp3->next = curr;
			temp3 = curr;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		
		else if(temp1->exp > temp2->exp)
		{
			curr->exp = temp1->exp;
			curr->coeff = temp1->coeff;
			curr->next = head;
			temp3->next = curr;
			temp3 = curr;
			temp1 = temp1->next;
		}
		
		else
		{
			curr->exp = temp2->exp;
			curr->coeff = (temp2->coeff*-1);
			curr->next = head;
			temp3->next = curr;
			temp3 = curr;
			temp2 = temp2->next;
		}
	}
}


void poly::display()
{
	node *curr;
	curr = head->next;
	while(curr!=head)
	{
		cout<<curr->coeff;
		if(curr->exp > 0)
			cout<<"x^"<<curr->exp;
		if(curr->next!=head)
		{
			if(curr->next->coeff > 0)
				cout<<" + ";
		}
		curr = curr->next;
	}
	cout<<"\n";
}

void poly::evaluate(int x)
{
	node *curr;
	int ans = 0, pow, temp;
	curr = head->next;
	while(curr!=head)
	{
		temp = curr->exp;
		pow = 1;
		while(temp>0)
		{
			pow = pow * x;
			temp--;
		}
		ans = ans + (curr->coeff * pow);
		curr = curr->next;
	}
	cout<<ans<<"\n";
}

int main()
{
	poly p1,p2,p3;							//creating 3 head nodes
	int x, ch;
	cout<<"For poly 1\n\n";
	p1.create_poly();
	cout<<"\n\nFor poly 2\n\n";
	p2.create_poly();
	cout<<"Polynomial 1 = ";
	p1.display();
	cout<<"Polynomial 2 = ";
	p2.display();
	cout<<"\nEnter value of x : ";			//to evaluate the polynomials
	cin>>x;
	cout<<"\nPolynomial 1 = ";
	p1.evaluate(x);
	cout<<"Polynomial 2 = ";
	p2.evaluate(x);
	do
	{
		cout<<"\n1. Addition\n2. Subtraction\n3. Exit\nEnter choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Addition =   ";
				p3.add_poly(p1,p2);
				p3.display();
				cout<<"Addition = ";
				p3.evaluate(x);
			break;
		
			case 2:
				cout<<"Subtraction =   ";
				p3.sub_poly(p1,p2);
				p3.display();
				cout<<"Subtraction = ";
				p3.evaluate(x);
			break;
			
			case 3:
			break;
		
			default:
				cout<<"Inavlid choice\n";
		}
	}while(ch!=3);
	return 0;
}

/*
OUTPUT

For poly 1

Enter coeff : 5
Enter exp : 5
1. Add another node
2. Exit
Enter choice : 1


Enter coeff : 3
Enter exp : 3
1. Add another node
2. Exit
Enter choice : 2




For poly 2

Enter coeff : 7
Enter exp : 3
1. Add another node
2. Exit
Enter choice : 1


Enter coeff : 2
Enter exp : 1
1. Add another node
2. Exit
Enter choice : 2


Polynomial 1 = 5x^5 + 3x^3
Polynomial 2 = 7x^3 + 2x^1

Enter value of x : 1

Polynomial 1 = 8
Polynomial 2 = 9

1. Addition
2. Subtraction
Enter choice : 1
Addition =   5x^5 + 10x^3 + 2x^1
Addition = 17

1. Addition
2. Subtraction
3. Exit
Enter choice : 2
Subtraction =   5x^5-4x^3-2x^1
Subtraction = -1

1. Addition
2. Subtraction
3. Exit
Enter choice : 3

*/
