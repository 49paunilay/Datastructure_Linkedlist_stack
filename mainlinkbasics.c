#include <stdio.h>
//declearing the structure
struct Node{
	int data;
	struct Node *next;
};
struct Node* head=NULL;
struct Node* temp;
//add function
void addme(int value){
	struct Node *newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	if(newNode==NULL){
		printf("Not allocated");
	}
	else{
		newNode->data=value;
		newNode->next=NULL;
		if(head==NULL){
			head=temp=newNode;
			//printf("....%d....",temp->data);
			
		}
		else{
			temp->next=newNode;
			temp=newNode;
			//printf("....%d....",temp->data);
		}
	}
	
}
//display function
void display(){
	temp=head;
	while(temp!=NULL){
		printf("\n%d",temp->data);
		temp=temp->next;
		
	}
}
//Driver function
int main(int argc, char** argv) {
	int choice=1;
	int number;
	while(choice){
		printf("Enter the number");
		scanf("%d",&number);
		addme(number);
		printf("press 1 to continue-------------");
		scanf("%d",&choice);
		
	}
	display();
}
