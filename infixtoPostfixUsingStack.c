#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 100

char stack[size];
int top=-1;
int isFull(){
	if(top==size-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
void push(int data){
	if(!isFull()){
		top=top+1;
		stack[top]=data;
	}
	else{
		printf("Cannot push\n");
	}
}
char pop(){
	int data;
	if(!isEmpty()){
		data=stack[top];
		top=top-1;
		return data;
	}
	else{
		printf("Cannot pop");
	}
}
int is_operator(char ch){
	if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
	{
		return 1;
	}
	else{
		return 0;
	}
}
int precendence(char ch){
	if(ch=='^'){
		return 3;
	}
	else if(ch=='*'||ch=='/'){
		return 2;
	}
	else if(ch=='+'||ch=='-'){
		return 1;
	}
	else{
		return 0;
	}
}
void InfixTOPrefix(char infix[],char postfix[]){
	int i,j;
	char item;
	char x;
	push('(');
	strcat(infix,")");
	i=0;j=0;
	item=infix[i];
	while(item!='\0'){
		if(item=='('){
			push(item);
		}
		else if(isdigit(item)||isalpha(item)){
			postfix[j]=item;
			j++;
		}
		else if(is_operator(item)==1){
			x=pop();
			while(is_operator==1 && precendence(x)>=precendence(item)){
				postfix[j]=x;
				j++;
				x=pop();
			}
			push(x);
			push(item);
		}
		else if(item==')'){
			x=pop();
			while(x!='('){
				postfix[j]=x;
				j++;
				x=pop();
			}
			
		}
		else{
			printf("Invalid");
			getchar();
			exit(1);
		}
		i++;
		item=infix[i];
	}
	if(top>0){
		printf("Invalid");
		getchar();
		exit(1);
	}
	postfix[j]='\0';
	
}


int main() {
	char infix[size],postfix[size];
	printf("\Enter\n");
	gets(infix);
	InfixTOPrefix(infix,postfix);
	puts(postfix);
	return 0;
	
	
}
