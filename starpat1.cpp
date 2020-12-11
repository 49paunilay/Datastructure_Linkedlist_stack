#include<iostream>
using namespace std;
int main(){
    int i,j;
    int number=5;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(j<5-i-1){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
            
        }
        cout<<endl;
    }
}