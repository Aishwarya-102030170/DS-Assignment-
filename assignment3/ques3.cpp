#include<iostream>
#include<string>
using namespace std;
class stack{
    public:
 int top;
 char str[100];
 public:
 stack(){
    top=-1;
 }
 void push(char val){
    if(top>=99){
        cout<<"overload"<<endl;
        return;
    }
    top++;
    str[top]=val;
 }
 char pop(){
if(top<0){
    cout<<"stack empty"<<endl;
}
return str[top--];


}
    char peek() {
        if (top < 0) return '\0';
        return str[top];
    }
 bool isempty(){
    return top==-1;
 }
};

int main(){
    string str="({([ )})";
    stack s;
    for(int i=0;i<str.length();i++){
            if(str[i]=='['|| str[i]=='('||str[i]=='{'){
                s.push(str[i]);
            }
            else{
                char topChar=s.peek();
                if((str[i] == ')' && topChar == '(') ||
                (str[i] == '}' && topChar == '{') ||
                (str[i] == ']' && topChar == '[')){
                    s.pop();
                }
                else{
                    cout<<"not balanced"<<endl;
                    return 0;
                }
            }
    }

     if (s.isempty())
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
