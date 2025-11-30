#include<iostream>
#include<string>
using namespace std;
 class stack{
    int top;
    char arr[100];
    public:
stack(){
top=-1;
}

void push(char val){
 if(top>=99){
    cout<<"stack is full"<<endl;
    return;
 }
 top++;
 arr[top]=val;
}
char pop(){
if(empty()){
    cout<<"stack empty"<<endl;
}
return arr[top--];

}

  

bool empty(){
    return top<0;
}


 };
int main(){
    stack s;
    string str="DataStructure";

    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }

while(!s.empty()){
    cout<<s.pop();
}
cout<<endl;
    return 0;
}
