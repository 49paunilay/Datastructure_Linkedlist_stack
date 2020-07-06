#include <stdio.h>
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head=NULL;
struct Node *temp;
void create(int data){
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	if(head==NULL){
		head=temp=newNode;
	}
	else{
		temp->next=newNode;
		newNode->prev=temp;
		temp=newNode;
	}
}
void deleteatbeg(){
	struct Node* previous=head;
	head=head->next;
	head->prev=NULL;
	free(previous);
	printf("\nAfter deletion at the beginning\n");
}
void display(){
	temp=head;
	while(temp!=NULL){
		printf("%d	",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void deleteatend(){
	struct Node* tempo=head;
	struct Node* lastNode1;
	while(tempo->next!=NULL){
		tempo=tempo->next;
	}
	lastNode1=tempo->prev;
	lastNode1->next=NULL;
	printf("\Delete at the end\n");
	free(tempo);	
	
}
void deleteatpos(int position){
	struct Node* currentnode=head;
	int i=1;
	if(position<1 || position>size()){
		printf("\nchosen size is not right %d is total size\n ",size());
		}
	else if(position==1){
		deleteatbeg();
		
	}
	else if(position==size()){
		deleteatend();
		
	}
	else{
		while(i<position){
			currentnode=currentnode->next;
			i++;
		}
		currentnode->prev->next=currentnode->next;
		currentnode->next->prev=currentnode->prev;
		free(currentnode);
		printf("\nAfter deletion at %d\n",position);
	}
}
int size(){
	struct Node* sizevar=head;
	int count=0;
	while(sizevar!=NULL){
		sizevar=sizevar->next;
		count++;
	}
	return count;
}

int main(int argc, char** argv) {
	create(1);
	create(2);
	create(3);
	create(4);
	create(5);
	create(6);
	create(7);
	create(8);
	create(9);
	display();
	deleteatbeg();
	display();
	deleteatbeg();
	display();
	deleteatend();
	display();
	deleteatend();
	display();
	deleteatpos(3);
	display();
	deleteatpos(4);
	display();
}
