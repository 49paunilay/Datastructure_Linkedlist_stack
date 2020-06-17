#include <stdio.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node *head=NULL,*temp;
void create(int value){
	struct Node* newData;
	newData=(struct Node*)malloc(sizeof(struct Node));
	if(newData==NULL){
		printf("Memory is not allocated");
	}
	else{
		newData->data=value;
		newData->next=NULL;
		if(head==NULL){
			head=temp=newData;
		}
		else{
			temp->next=newData;
			temp=newData;
		}
	}
}
void display(){
	temp=head;
	while(temp!=NULL){
		printf("%d	",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void deleteatbeginning(){
	struct Node *oldnode;
	oldnode=head;
	head=head->next;
	free(oldnode);
}
void deleteattheend(){
	struct Node *previous;
	previous=temp=head;
	while(temp->next!=NULL){
		previous=temp;
		temp=temp->next;
	}
	if(temp==head){
		head=NULL;
	}
	else{
		previous->next=NULL;
	}
	free(temp);
	
}
void deletefromapos(int pos){
	temp=head;
	struct Node* nextNode;
	int i=1;
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	nextNode=temp->next;
	temp->next=nextNode->next;
	free(nextNode);	
}

int main(int argc, char** argv) {
	create(1);
	create(2);
	create(3);
	create(4);
	display();
	printf("After deletion from the specified position\n");
	deletefromapos(3);
	display();
	printf("After deletion at the beginning \n");
	deleteatbeginning();
	display();
	printf("After deletion at the end \n");
	deleteattheend();
	display();
}
