#include <stdio.h>
//Defining custom datatype in c
struct Node{
	int data;
	struct Node* next;
};
struct Node* head=NULL;
struct Node* temp;
void create(int value){
	//Create the nodes
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	if(head==NULL){
		temp=head=newNode;
	}
	else{
		temp->next=newNode;
		temp=newNode;
	}
}
//Function to reverse the links 
void reverse(){
	struct Node *previous=NULL;
	struct Node* current=head;
	struct Node* nextnode=head;
	while(nextnode!=NULL){
		/*Three pointers are here. 'nextnode' is set to the next after the current node to store that node. After breaking the node between next and current node we connect 
		previous node and current->next to reverse the link.
		we set the current node in the previous node.
		we set current node to next node*/
		nextnode=nextnode->next;
		current->next=previous;
		previous=current;
		current=nextnode;
	}
	//After the loop set head to the last node . In this case previous to complete the reversal of links.
	head=previous;
	
}
void display(){
	temp=head;
	while(temp!=NULL){
		printf("%d	",temp->data);
		temp=temp->next;	
	}
	printf("\n");
}

int main(int argc, char** argv) {
	//main function
	create(1);
	create(2);
	create(3);
	create(9);
	create(11);
	display();
	reverse();
	printf("After revers------------\n");
	display();
	return 0;
	
			
	
}
