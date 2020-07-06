#include <stdio.h>
struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};
struct Node* head=NULL;
struct Node* tail;
void create(int value){
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	newNode->prev=NULL;
	if(head==NULL){
		head=tail=newNode;
	}
	else{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	}
}
void atbegin(int value){
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->prev=NULL;
	newNode->next=head;
	head=newNode;
}
void atend(int value){
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	//newNode->prev=NULL;
	tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	newNode->prev=tail;
	newNode->next=NULL;
	tail->next=newNode;
	tail=newNode;		
}
void position(int value,int pos){
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	struct Node* temp=head;
	int i=1;
	newNode->data=value;
	if(pos<0){
		printf("Invalid");
	}
	else{
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		newNode->prev=temp;
		newNode->next=temp->next;
		temp->next=newNode;
		newNode->next->prev=newNode;
		
	}
}
void display(){
	tail=head;
	while(tail!=NULL){
		printf("%d	",tail->data);
		tail=tail->next;
	}
	printf("\n");
}

int main(int argc, char** argv) {
	printf("Doubly Linked list\n\");
	create(1);
	create(2);
	create(3);
	create(4);
	display();
	atbegin(5);
	display();
	atend(14);
	display();
	atbegin(49);
	display();
	atend(44);
	display();
	position(13,3);
	display();
}
