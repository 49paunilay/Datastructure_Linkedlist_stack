#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
Node *temp=NULL,*head=NULL;
void Display(){
    Node* displayer=head;
    while (displayer!=NULL)
    {
        cout<<displayer->data<<" ";
        displayer=displayer->next;
    }
    
}
void newNode(int value){
    struct Node* nextNode;
    nextNode=(Node*)malloc(sizeof(Node));
    nextNode->data=value;
    nextNode->next=NULL;
    if(head==NULL){
        head=temp=nextNode;
    }
    else{
        temp->next=nextNode;
        temp=nextNode;
    }
}
void reverseLinkedList(){
    struct Node *current,*previous=0,*after;
    current=after=head;
    while(after!=NULL){
        after=after->next;
        current->next=previous;
        previous = current;
        current=after;

    }
    head=previous;
 
}
Node* Addone(){
    Node* res=head;
    int carry=1,sum=0;
    while(res!=NULL){
        sum=carry+(res?res->data:0);
       
        carry=(sum>=10)?1:0;
        sum=sum%10;
        res->data=sum;
        res=res->next;
    }
    if(carry>0){
        newNode(carry);
    }
 
    return head;
}

void AddoneTothenumber(){
    Node* holder;
    reverseLinkedList();
    holder=Addone();
    
    reverseLinkedList();
  
}
int main(){
    newNode(1);
    newNode(9);
    newNode(9);
    newNode(9);
    Display();
    AddoneTothenumber();
    Display();

}