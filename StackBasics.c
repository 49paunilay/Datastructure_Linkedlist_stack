#include <stdio.h>
int maxsize=8;
int stack[8];
int top=-1;

int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(){
	if(top==maxsize){
		return 1;
	}
	else{
		return 0;
	}
}
int peek(){
	return stack[top];
}

int pop(){
	int data;
	if(!isEmpty()){
		data=stack[top];
		top=top-1;
		return data;
	}
	else{
		printf("The stack is Empty");
	}
}
int push(int data){
	top=top+1;
	stack[top]=data;
	
}
int main(int argc, char** argv) {
	push(4);
	push(5);
	push(7);
	printf("%d is peek\n",peek());
	while(!isEmpty()){
		printf("%d	",pop());
	}
	return 0;
}
