#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* temp;
void Create(int value){
    struct Node* newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=temp=newNode;
    }
    else{
        temp->next=newNode;
        temp=newNode;
    }

}
void Display(){
    struct Node* d=head;
    while(d!=NULL){
        cout<<d->data<<"    ";
        d=d->next;
    }
}

void Rearrange(){
    struct Node *odd,*even,*evenfirst;
    if(head==NULL){
        return;
    }
    odd=head;
    even=head->next;
    evenfirst=even;
    while(1){
        if(!odd || !even ||!(even->next)){
            odd->next=evenfirst;
            break;
        }
        odd->next=even->next;
        odd=even->next;
        if(odd->next==NULL){
            even->next=NULL;
            odd->next=evenfirst;
            break;
        }
        even->next=odd->next;
        even=odd->next;
    }
}

int main(){
    int n;
    int temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        Create(temp);
    }

    Display();
    Rearrange();
    cout<<endl;
    Display();
    
}