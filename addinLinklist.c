#include <stdio.h>
//custom datatype 
struct Node{
	int data;
	struct Node *next;
};
//declaring globally
struct Node *head=NULL,*temp;
void End(int value){
	//Insert value at the end of the linkedlist
	struct Node *newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	if(newNode==NULL){
		printf("Cannot allocate memory!");
	}
	else{
		newNode->data=value;
		newNode->next=NULL;
		if(head==NULL){
			head=temp=newNode;
		}
		else{
			temp->next=newNode;
			temp=newNode;
		}
		
	}
}
void first(int value){
	/*In case of inserting at beginning we first need to update the link to newNode to the rest of the linkedlist .
	So we first do newNode->next=head to point to the head/ the first element of the list and then we assign head= newNode to link the newNode as head node*/
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=head;
	head=newNode;
	
}
void position(int pos,int value,int count){
	//inserting at a specific node
	struct Node *temp1=head;
	struct Node *newNode;
	int i=1;
	if(pos>count){
		printf("Invalid!!");
	}
	else{
		newNode=(struct Node*)malloc(sizeof(struct Node));
		if(newNode==NULL){
			printf("Invalid Memory!");
		}
		else{
			newNode->data=value;
			newNode->next=NULL;
			while(i<pos){
				//traversing until the previous position of the required position is not obtained by i<pos condition
				temp1=temp1->next;
				i++;
			}
			newNode->next=temp1->next;
			temp1->next=newNode;
		}
		
	}
	
}
void display(){
	//display function
	temp=head;
	while(temp!=NULL){
		printf("%d	",temp->data);
		temp=temp->next;
	}
}
//main function
int main() {
	//counting perpous
	int count=0;
	
	End(1);
	count++;
	End(3);
	count++;
	End(5);
	count++;
	first(10);
	count++;
	position(2,15,count);
	count++;
	display();
	return 0;
}
