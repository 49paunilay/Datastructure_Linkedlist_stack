#include<stdio.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node *top=NULL,*temp;
void push(int value){
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=top;
	top=newNode;
}
void pop(){
	struct Node* oldNode;
	oldNode=top;
	top=top->next;
	free(oldNode);
}
void display(){
	temp=top;
	while(temp!=NULL){
		printf("%d	",temp->data);
		temp=temp->next;
	}
}
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	display();
	pop();
	printf("\nAfter poping\n");
	display();
	pop();
	printf("\nAfter poping\n");
	display();
}

