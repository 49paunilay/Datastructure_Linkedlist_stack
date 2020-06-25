#include<stdio.h>
#define max 8

int queue[max];
int front=-1;
int rear=-1;

//isEmpty() is used to find if the queue is empty or not
int isEmpty(){
	if(front==-1 && rear==-1){
		return 1;
	}
	else{
		return 0;
	}
}
//enqueue is used to push the elements in the queue from the rear side
void enqueue(int value){
	if(rear==max-1){
		printf("OverFlow!");
	}
	else if(rear==-1 && front==-1){
		front++;
		rear++;
		queue[rear]=value;
	}
	else{
		rear++;
		queue[rear]=value;
	}
}
//dequeue is used to pop the front value of the queue 
int dequeue(){
	int data;
	if(!isEmpty()){
		if(front==rear){
			data=queue[front];
			front=-1;
			rear=-1;
			return data;
		}
		else{
			data=queue[front];
			front=front+1;
			return data;
		}
	}
	else{
		printf("Under flow!");
	}
}
// to get the front value with out pop
int peek()
{
	return queue[front];
}
//Driver function
int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	printf("%d	",dequeue());
	printf("\nPeek->%d	",peek());
	printf("\nThe elements is the queue");
	while(!isEmpty()){
		printf("\n%d",dequeue());
	}
	
}
