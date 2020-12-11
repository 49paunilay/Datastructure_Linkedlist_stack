#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void Printmin(int array[],int n){
    int min=-1;
    set<int> myset;
    for(int i=n-1;i>=0;i--){
        if(myset.find(array[i])!=myset.end()){
            min=i;
        }
        else{
            myset.insert(array[i]);
        }
    }
    if(min!=-1){
        cout<<"The first repeating element is "<<array[min]<<" And the minimum index "<<min;
    }
    else{
        cout<<"No repeat";
    }


}
int main(){
    int arr[]={10,5,3,4,3,5,6};
    Printmin(arr,(sizeof(arr)/sizeof(arr[0])));

}