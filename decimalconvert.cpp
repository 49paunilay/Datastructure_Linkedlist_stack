#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* temp;
void CreateNode(int value){
    Node* newNode=(struct Node*) malloc(sizeof(struct Node));
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
void Display(){
    struct Node* disp=head;
    while(disp!=NULL){
        cout<<disp->data<<" ";
        disp=disp->next;
    }
}
int printResult(){
    
    int res=0;
    Node* result=head;
    while(result!=NULL){
        res=res*2+result->data;
        result=result->next;
    }
    return res;
}
int main(){
    for(int i=0;i<5;i++){
        if(i%2==0){
             CreateNode(0);
        }
        else{
             CreateNode(1);
        }
       

    }
    Display();
    int res=printResult();
    cout<<endl;
    cout<<res;
}