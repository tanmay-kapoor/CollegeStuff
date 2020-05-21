/*
DICTIONARY
Implement dictionary using binary search tree where dictionary stores keywords & its meanings. Perform following operations:
i.		Insert a keyword
ii.		Delete a keyword
iii.	Create mirror image and display level wise
iv.	     Copy
*/

#include<iostream>
using namespace std;


class node												//node class for binary search tree
{
	string data,meaning;
	node *left,*right;
	friend class bst;
};

class bst												//class binary search tree
{

	node *root;
	public :
		void insert_nr();								//insert a node
		void insert_nr(node *);
		void display_bfs();								//display level wise
		void display_bfs(node *);
		void dfs_in();									//display inorder - recursive
		void inorder(node *);
		void dfs_pre();									//display preorder - recursive
		void preorder(node *);
		void dfs_post();								//display postorder - recursive
		void postorder(node *);
		void mirror();									//mirror image of bst
		void mirror(node *);
		bst copy();										//copy of bst
		node* copy(node *);
		void height();									//height of bst
		int height(node *);
		bst delete_bst();								//delete a node in bst
		node* delete_bst(node *,string );
		void search();									//search a node - recursive and non-recursive
		node* search_r(node *,string);
		void search_nr(node *,string);

	bst()
		{
			root=NULL;				//initializing root
		}
};

int front,rear;
int size=50;
class queue												//class queue for level wise display of bst
{
	node *data[50];
	public :
		queue()
		{
			front=-1;
			rear=-1;
		}
		friend class bst;

	void push(node *ele)
	{
		if(rear==size-1)
			cout<<"\nQueue is full";
		else
		{
			rear++;
			data[rear]=ele;
		}
	}

	node* pop()
	{
		if(front==rear)
			cout<<"\nQueue is empty";
		else
		{
			front++;
			return (data[front]);
		}
	}

	int empty()
	{
		if(rear==front)
			return 1;
		else
			return 0;
	}

};


void bst :: insert_nr(node *temp)
{
	int flag,z;
	flag=0;
	node *curr;
	curr=new node();
	curr->left=curr->right=NULL;
	cout<<"\nEnter new keyword : ";						//new keyword to be inserted
	cin>>curr->data;

		while(flag==0)                                  //to determine where to add the node
		{
			if(curr->data==temp->data)
			{
				cout<<"\nKeyword already exists";
			}
			else if(curr->data < temp->data)
			{
				if(temp->left==NULL)
				{
					cout<<"\nEnter its meaning : ";
					cin>>curr->meaning;
					temp->left=curr;
					flag=1;
				}
				temp=temp->left;
			}
			else {
				if(temp->right==NULL)
				{
					cout<<"\nEnter its meaning : ";
					cin>>curr->meaning;
					temp->right=curr;
					flag=1;
				}
				temp=temp->right;
			}
		}
}


void bst :: insert_nr()
{
	char yy;
	if(root==NULL)							//if new tree to be created
	{
		root= new node();
		cout<<"\nEnter keyword for root node :";
		cin>>root->data;
		cout<<"\nEnter its meaning :";
		cin>>root->meaning;
		root->left=root->right=NULL;
	}
	do
	{
		insert_nr(root);
		cout<<"\nDo you wish to add new keyword (yes=y) : ";
		cin>>yy;
	}while(yy=='y');
}

void bst :: display_bfs(node *temp)				//level wise display using queue data structure
{
	queue q;
	q.push(temp);
	while(q.empty()==false)
	{
		node *curr;
		curr=new node();
		curr=q.pop();
		cout<<curr->data<<" : "<<curr->meaning<<endl;
		if(curr->left!=NULL)
			q.push(curr->left);
		if(curr->right!=NULL)
			q.push(curr->right);
	}
}

void bst :: display_bfs()
{
	display_bfs(root);
}

//DISPLAY FUNCTION 1 - DEPTH FIRST SEARCH
void bst :: inorder(node *root)   //lRr -recursive
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" : "<<root->meaning<<"    ";
		inorder(root->right);
	}
}

void bst :: dfs_in()
{
	inorder(root);
}

//DISPLAY FUNCTION 2 - DEPTH FIRST SEARCH
void bst :: preorder(node *root) //Rlr - recursive
{
	if(root!=NULL)
	{
		cout<<root->data<<" : "<<root->meaning<<"    ";
		preorder(root->left);
		preorder(root->right);
	}
}

void bst :: dfs_pre()
{
	preorder(root);
}

//DISPLAY FUNCTION 3 - DEPTH FIRST SEARCH
void bst :: postorder(node* root) //lrR - recursive
{
	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" : "<<root->meaning<<"    ";
	}
}

void bst :: dfs_post()
{
	postorder(root);
	cout<<"\n";
}

void bst :: mirror(node *root)
{
	if(root!=NULL)
	{
		node *temp;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirror(root->left);
		mirror(root->right);
	}
}

void bst :: mirror()
{
	mirror(root);
	display_bfs();
}

node* bst :: copy(node *root)
{
	node *curr;
	curr=NULL;
	if(root!=NULL)
	{
		curr=new node();
		curr->data=root->data;
		curr->meaning=root->meaning;
		curr->left=copy(root->left);
		curr->right=copy(root->right);
	}
	return(curr);
}

bst bst :: copy()
{
	bst t2;
	t2.root=copy(root);
	return t2;
}

int bst :: height(node *root)
{
	if(root==NULL)
	return 0;
	else
	return (max(height(root->left),height(root->right))+1);
}

void bst :: height()
{
	int h=height(root);
	cout<<"\nHeight of tree is "<<h;
}

//DELETE A NODE FROM BINARY SEARCH TREE
node* bst :: delete_bst(node *root,string key)
{
	node *temp,*curr,*parent,*s;
	curr=new node();
	parent=new node();
	s=new node();
	temp=new node();
	temp=root;
	while(temp!=NULL)    //search key to delete it
	{
		if(key==temp->data)
		{
			curr=temp;   //curr is node to be deleted
			break;
		}
		else if(key<temp->data)
		{
			parent=temp;
			temp=temp->left;
		}
		else
		{
			parent=temp;
			temp=temp->right;
		}

	}
		if(curr==root) //deletion of root
		{
			if(curr->right==NULL)
				root=root->left;
			else if(curr->left==NULL)
				root=root->right;
			else if(curr->right!=NULL && curr->left!=NULL)
			{
				temp=curr->left;
				root=curr->right;
				s=curr->right;
				while(s->left!=NULL)
				{
					s=s->left;
				}
				s->left=temp;
			}
		}
		else
		{

			if(curr!=root) //deletion of node which is not root
			{
				if(curr->right==NULL && curr->left==NULL) //deletion of a leaf
				{
					if(curr==parent->left)
					parent->left=NULL;
					else
					parent->right=NULL;
				}

				else if(curr->right!=NULL && curr->left==NULL) //deletion of a single child
				{
					if(curr==parent->left)
						parent->left=curr->right;
					else
						parent->right=curr->right;
				}
				else if(curr->right==NULL && curr->left!=NULL) //deletion of a single child
				{
					if(curr==parent->left)
						parent->left=curr->left;
					else
						parent->right=curr->left;
				}
				else //deletion of a node having two child
				{
					s=curr->right;
					temp=curr->left;
					while(s->left!=NULL)
					{
						s=s->left;
					}
					s->left=temp;
					if(curr==parent->left)
						parent->left=curr->right;
					else
						parent->right=curr->right;
				}

			}
		}
	curr->right=curr->left=NULL;
    delete curr;
    return (root);
}

bst bst :: delete_bst()
{
	string z;
	cout<<"Enter the keyword you wish to delete : ";
	cin>>z;
	bst t2;
	t2.root=delete_bst(root,z);
	return t2;
}

//SEARCH A NODE IN BINARY SEARCH TREE
node* bst :: search_r(node *temp,string key)
{
	while(temp!=NULL)    //search key to delete it
	{
		if(key==temp->data)
		{
			return (temp);
		}
		else if(key<temp->data)
			temp=search_r(temp->left,key);
		else
			temp=search_r(temp->right,key);
	}
	return (temp);
}

void bst :: search_nr(node *temp,string key)
{
	int flag=0;
	while(flag==0)		//search key to delete it
	{
		if(key==temp->data)
		{
			flag=1;
			break;
		}
		else if(key<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(flag==1)
	cout<<"\nKeyword found! \n"<<temp->data<<" : "<<temp->meaning<<endl;
	else
	cout<<"\nKeyword not found!";
}
void bst :: search()
{
	int n;
	string z;
	cout<<"\nEnter way to search :\n1. Recursive\n2. Non-recursive \nChoice : "<<endl;
	cin>>n;
	cout<<"Enter the keyword you wish to search : ";
	cin>>z;
	switch(n)
	{
		case 1 :
			node *t;
			t=new node();
			t=search_r(root,z);
			if(z==t->data)
				cout<<"\nKeyword found! \n"<<t->data<<" : "<<t->meaning<<endl;
			else
				cout<<"\nKeyword not found!";
			break;

		case 2 :
			search_nr(root,z);
			break;

		deafult : cout<<"Not valid option";
	}
}
int main()
{
	cout <<"\n\t\t\t\t\tDICTIONARY\n\n";
	bst t;
	bst t2;
	int ch,h,y;
	do
	{
		cout<<"\n\tMENU\n1. Insert a keyword \n2. Delete a keyword \n3. Mirror image \n4. Copy\n5. Height\n6. Display level wise\n7. Display inorder,preorder and postorder\n8. Search a keyword\n\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
				t.insert_nr();
				break;

			case 2 :
				t=t.delete_bst();
				t.display_bfs();
				break;

			case 3 :
				cout<<"\nMirror image of tree : \n";
				t.mirror();
				break;

			case 4 :
				cout<<"\nTree copied : \n";
				t2=t.copy();
				t2.display_bfs();
				break;

			case 5 :
				t.height();
				break;

			case 6:
				t.display_bfs();
				break;

			case 7 :
				cout<<"\nInorder display :"<<endl;
				t.dfs_in();
				cout<<"\nPreorder display :"<<endl;
				t.dfs_pre();
				cout<<"\nPostorder display :"<<endl;
				t.dfs_post();
				break;

			case 8 :
				t.search();
				break;

			default :
				cout<<"\n Invalid option ";
		}
		cout<<"\nDo you wish to continue (yes =1 ) : ";
		cin>>y;
	}while(y==1);

	return 0;
}