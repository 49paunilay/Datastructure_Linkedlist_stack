#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
struct Node *head,*temp;
void createLinkedList(int v){
    struct Node* newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=v;
    newNode->next=NULL;
    if(head==NULL){
        head=temp=newNode;
    }
    else{
        temp->next=newNode;
        temp=newNode;
    }

}
void RotateNode(){
    struct Node *odd,*even,*evenFirst;
    if(head==NULL){
        cout<<"The head is null";
    }
    odd=head;
    even=odd->next;
    evenFirst=even;
    while(1){
        if(!odd || !even || !(even->next)){
            odd->next=evenFirst;
            break;
        }
        odd->next=even->next;
        odd=even->next;
        if(odd->next==NULL){
            even->next=NULL;
            odd->next=evenFirst;
            break;
        }
        even->next=odd->next;
        even=odd->next;
    }

}
void Display(){
    struct Node* displayer=head;
    while(displayer!=NULL){
        cout<<displayer->data<<" ";
        displayer=displayer->next;
    }
    
}
int main(){
    for(int i=1;i<15;i++){
        createLinkedList(i);
    }
    RotateNode();
    Display();


}