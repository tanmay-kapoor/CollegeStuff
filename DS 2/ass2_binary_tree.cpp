#include<iostream>
using namespace std;

class treenode
{
	char data[10];
	treenode *left;
	treenode *right;
	friend class tree;
};

class tree
{
	treenode *root;
public:
	tree();
	void create_r();
	void inorder_r();
	void preorder_r();
	void postorder_r();
	void create_r(treenode*);
	void inorder_r(treenode*);
	void preorder_r(treenode*);
	void postorder_r(treenode*);

	void create_nr();
	void inorder_nr();
	void preorder_nr();
	void postorder_nr();
};

class stack
{
	int top;
	treenode *data[30];
	public:
		stack()
		{
			top = -1;
		}

		void push(treenode*);
		treenode *pop();
		int empty();
		friend class tree;
};

tree::tree()
{
	root = NULL;
}

void tree::create_r()
{
	root = new treenode();
	cout<<"Enter root data : ";
	cin>>root->data;
	root->left = NULL;
	root->right = NULL;
	create_r(root);
}

void tree::create_r(treenode *temp)
{
	int ch;
	do{
		cout<<"\nAdd data to left of current node?"<<temp->data<<"\n1. Yes\n2. No\nEnter choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				treenode *curr;
				curr = new treenode();
				cout<<"Enter the data to be added : ";
				cin>>curr->data;
				curr->left = NULL;
				curr->right = NULL;
				temp->left = curr;
				create_r(curr);
				break;
			
			case 2:
				break;

			default:
				cout<<"Invalid choice. Enter again";
		}
	}while(ch!=1  && ch!=2);

	cout<<"\nAdd data to right of current node? ("<<temp->data<<")\n1. Yes\n2. No\nEnter choice : ";
	cin>>ch;
	if(ch==1)
	{
		treenode *curr;
		curr = new treenode();
		cout<<"Enter the data to be added : ";
		cin>>curr->data;
		curr->left = NULL;
		curr->right = NULL;
		temp->right = curr;
		create_r(curr);
	}
}

void tree::inorder_r()
{
	inorder_r(root);
}

void tree::inorder_r(treenode *temp)
{
	if(temp!=NULL)
	{
		inorder_r(temp->left);
		cout<<temp->data<<"\n";
		inorder_r(temp->right);
	}
}

void tree::preorder_r()
{
	preorder_r(root);
}

void tree::preorder_r(treenode *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data<<"\n";;
		preorder_r(temp->left);
		preorder_r(temp->right);
	}
}

void tree::postorder_r()
{
	postorder_r(root);
}

void tree::postorder_r(treenode *temp)
{
	if(temp!=NULL)
	{
		postorder_r(temp->left);
		postorder_r(temp->right);
		cout<<temp->data<<"\n";
	}
}

void stack::push(treenode *temp)
{
	top++;
	data[top] = temp;
}

treenode *stack::pop()
{
	treenode *curr;
	curr = data[top];
	top--;
	return curr;
}

int stack::empty()
{
	if(top==-1)
		return 1;
	return 0;
}

void tree::create_nr()
{
	treenode *curr;
	treenode *temp;
	int flag, ch, ch2;
	if(root==NULL)
	{
		root = new treenode();
		cout<<"Enter data for root node : ";
		cin>>root->data;
	}
	temp = root;
	do{
		flag = 0;
		curr = new treenode();
		cout<<"Enter data for new node : ";
		cin>>curr->data;
		while(flag==0)
		{
			x:
				cout<<"Add node to Left of "<<temp->data<<"?\n1. Yes\n2. No\nEnter choice : ";
				cin>>ch;
				if(ch==1)
				{
					if(temp->left==NULL)
					{
						temp->left = curr;
						flag = 1;
					}
					temp = temp->left;
				}
				else if(ch==2)
				{
					y:
						cout<<"Add node to Right of "<<temp->data<<"?\n1. Yes\n2. No\nEnter choice : ";
						cin>>ch;
						if(ch==1)
						{
							if(temp->right==NULL)
							{
								temp->right = curr;
								flag = 1;
							}
							temp = temp->right;
						}
						else if(ch!=1 && ch!=2)
						{
							cout<<"Invalid choice. Enter again\n";
							goto y;
						}
				}
				else
				{
						cout<<"Invalid choice. Enter again\n";
						goto x;
				}
		}
		z:
			cout<<"Add another node?\n1. Yes\n2. No\nEnter choice : ";
			cin>>ch2;
			if(ch2!=1 && ch2!=2)
			{
				cout<<"Invalid choice. Enter again\n";
				goto z;
			}
	}while(ch2==1);
}

void tree::inorder_nr()
{
	stack ob;
	treenode* temp = root;

	while(1)
	{
		while(temp!=NULL)
		{
			ob.push(temp);
			temp = temp->left;
		}
		if(ob.empty())
			break;
		temp = ob.pop();
		cout<<temp->data<<"\n";
		temp = temp->right;
	}
}

void tree::preorder_nr()
{
	stack ob;
	treenode* temp = root;

	while(1)
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<"\n";
			ob.push(temp);
			temp = temp->left;
		}
		if(ob.empty())
			break;
		temp = ob.pop();
		temp = temp->right;
	}
}

void tree::postorder_nr()
{
	stack ob;
	treenode* temp = root;

	while(1)
	{
		while(temp!=NULL)
		{
			ob.push(temp);
			temp = temp->left;
		}
		if(ob.data[ob.top]->right==NULL)
		{
			temp = ob.pop();
			cout<<temp->data<<"\n";
		}
		while(!ob.empty() && ob.data[ob.top]->right==temp)
		{
			temp = ob.pop();
			cout<<temp->data<<"\n";
		}
		if(ob.empty())
			break;
		temp = ob.data[ob.top]->right;
	}
}

int main()
{
	int ch, ch2;
	tree bt;
	do{
		cout<<"1. Create recursive\n2. Create non-recursive\n3. Display recursive\n4. Display non-recursive\n5. Exit\nEnter choice : ";
		cin>>ch2;
		switch(ch2)
		{
			case 1:
				bt.create_r();
				break;
			
			case 2:
				bt.create_nr();
				break;

			case 3:
				do{
					cout<<"\n\n1. Inorder traversal\n2. Preorder traversal\n3. Postorder traversal\n4. Exit\nEnter choice : ";
					cin>>ch;
					switch(ch)
					{
						case 1:
							cout<<"\n\nDisplaying nodes using inorder recursive traversal:\n";
							bt.inorder_r();
							break;

						case 2:
							cout<<"\nDisplaying nodes using preorder recursive traversal:\n";
							bt.preorder_r();
							break;

						case 3:
							cout<<"\nDisplaying nodes using postorder recursive traversal:\n";
							bt.postorder_r();
							break;

						case 4:
							break;

						default:
							cout<<"Invalid choice. Enter again";
					}
				}while(ch!=4);
				break;

			case 4:
				do{
					cout<<"\n\n1. Inorder traversal\n2. Preorder traversal\n3. Postorder traversal\n4. Exit\nEnter choice : ";
					cin>>ch;
					switch(ch)
					{
						case 1:
							cout<<"Displaying nodes using inorder non-recursive traversal\n";
							bt.inorder_nr();
							break;

						case 2:
							cout<<"\nDisplaying nodes using preorder non-recursive traversal:\n";
							bt.preorder_nr();
							break;

						case 3:
							cout<<"\nDisplaying nodes using postorder non-recursive traversal:\n";
							bt.postorder_nr();
							break;
						
						case 4:
							break;

						default:
							cout<<"Invalid choice. Enter again";
					}
				}while(ch!=4);
				break;

			case 5:
				break;

			default:
				cout<<"Invalid choice. Enter again\n\n";		
		}
	}while(ch2!=5);

	return 0;
}