#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printminIndex(int array[],int n){
    int minIndex=-1;
    set<int> myset;
    for(int i=n-1;i>=0;i--){
        if(myset.find(array[i])!=myset.end()){
            minIndex=i;
        }
        else{
            myset.insert(array[i]);
        }


    }
    if(minIndex!=-1){
        cout<<"The min is "<<minIndex;
    }
}
int main(){
    int array[]={1,1,2,3,4,5,6};
    printminIndex(array,sizeof(array)/sizeof(array[0]));
    return 0;

}