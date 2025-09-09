#include <iostream>
using namespace std;
    // stack<int> st;
    int msize=10;
    int s[10];
    int top=-1;
void push(int ele){
    if(top==msize){
        cout<<"stack overloading"<<endl;
    }
    else{
        top=top+1;
        s[top]=ele;
    }
}
void pop(){
    if(top==-1){
        cout<<"empty stack,unable to pop any ele"<<endl;
    }
    else{
        top=top-1;
    }
}
void topele(){
     if(top==-1){
        cout<<"empty stack,unable to find top ele"<<endl;
    }
    else{
        cout<<"top = "<<s[top]<<endl;
    }
}
void size(){
    cout<<"current size = "<<top+1<<endl;
}
void isEmpty(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
}
void isFull(){
    if(top==msize-1){
        cout<<"Stack is full"<<endl;
    }
    else{
        cout<<"Stack is not full"<<endl;
    }
}
void peek(){
     if(top==-1){
        cout<<"empty stack,unable to find top ele"<<endl;
    }
    else{
        cout<<"top = "<<s[top]<<endl;
    }
}
void display(){
    for(int i=0;i<=top;i++){
        cout<<s[i]<<" ";
    }
}
int main(){
    int ele1,ele2,ele3;
    cout<<"Enter the elements to be added in stack: ";
    cin>>ele1>>ele2>>ele3;
    push(ele1);
    push(ele2);
    push(ele3);
    pop();
    topele();
    size();
    isEmpty();
    isFull();
    peek();
    display();
    return 0;
}