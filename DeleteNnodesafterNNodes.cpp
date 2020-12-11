#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* temp;
void Display(){
    struct Node* displayer=head;
    while(displayer!=NULL){
        cout<<displayer->data<<" ";
        displayer=displayer->next;
    }
    cout<<endl;
}
void createNode(int data){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=temp=newNode;
    }
    else{
        temp->next=newNode;
        temp=newNode;
    }
}

void mainLoop(int m,int n){

    int count;
    Node *current=head;
    Node *t,*tempo;
    while(current!=NULL){
        for(count=0;count<m && current!=NULL ;count++){
            cout<<current->data<<" ";
            current=current->next;
            
        }
        if(current==NULL){
            return;
        }
        t=current;
        for(count=0;count<n;count++){
            tempo=t;
            t=t->next;
            
            free(tempo);
        }
      
        current=t;

        
    }
    

}

int main(){
    int m=2,n=2;
    for(int i=1;i<15;i++){
        createNode(i);
    }
    mainLoop(m,n);
    
}