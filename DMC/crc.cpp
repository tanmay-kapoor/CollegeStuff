/*
Assignment 5B
Write a program for error detection using CRC
*/
#include<iostream>

using namespace std;
int dev[4];


void division(int dataword[7],int key[4]){
	int i,j=0;
	for(i=0;i<4;i++)
		dev[i]=dataword[i];	
	
	for(i=0;i<4;i++){
		if(dev[0]==1){
			dev[j]=dev[j+1]^key[j+1];
			dev[j+1]=dev[j+2]^key[j+2];
			dev[j+2]=dev[j+3]^key[j+3];
			dev[j+3]=dataword[i+4];
		}
		else
		{
			dev[j]=dev[j+1];
			dev[j+1]=dev[j+2];
			dev[j+2]=dev[j+3];
			dev[j+3]=dataword[i+4];
		}
	}
}

int main(){
	
	cout<<"Enter Data Word Bit by Bit :-\n";
	int dataword[7];
	int i;
	for(i=0;i<4;i++){
		cin>>dataword[i];
	}
	dataword[4]=0;
	dataword[5]=0;
	dataword[6]=0;
	int key[4];
	
	
	
	cout<<"Enter Key Bit by Bit:-\n";
	
	for(i=0;i<4;i++){
		cin>>key[i];
	}
	division(dataword,key);
	
	cout<<"\nCode Word:";
	for(i=0;i<4;i++){
		cout<<dataword[i];
	}
	for(int l=0;l<3;l++){
		cout<<dev[l];
	}
	//------------------------Reciever Side----------------------------------------------------------
	
	int recData[7];
	cout<<"\nEnter Recieved Code Word Bit by Bit :- \n";
	
	for(i=0;i<7;i++){
		cin>>recData[i];
	}
	
	division(recData,key);
	cout<<"\n";
	int flag=0;
	for(i=0;i<4;i++){
		if(dev[i]==1)
			flag=1;
	}
	
	if(flag==0)
		cout<<"Correct Data is Recieved Successfully..";
	else
		cout<<"Incorrect Data is Recieved...";	

	return 0;
}

/*
Output:-

Enter Data Word Bit by Bit :-
1
0
0
1
Enter Key Bit by Bit:-
1
1
0
1

Code Word:1001011
Enter Recieved Code Word Bit by Bit :- 
1
0
0
1
0
1
1

Correct Data is Recieved Successfully..	
*/
