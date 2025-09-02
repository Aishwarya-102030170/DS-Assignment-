//Q1:
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
        cout<<"top ="<<s[top]<<endl;
    }
}
void size(){
    cout<<"current size="<<top+1<<endl;
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
        cout<<"top ="<<s[top]<<endl;
    }
}
void display(){
    for(int i=0;i<=top;i++){
        cout<<s[i]<<" ";
    }
}
int main(){
    int ele1,ele2,ele3;
    cout<<"Enter the elements to be added in stack";
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


//Q2:
#include <iostream>
#include <string>
using namespace std;
void reverse(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    string rev="";
    for(int i=0;i<s.length();i++){
      rev+=st.top();
      st.pop();
    }
    cout<<"reversed string is : "<<rev;
}
int main(){
  string s;
  cout<<"enter a string";
  getline(cin,s);
  reverse(s);
}

//Q3:
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    cout<<"Enter an expression";
    getline(cin,s);
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if((s[i]=='[')||(s[i]=='{')||(s[i]=='(')){
            st.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
        char top=st.top();
        if((top=='(')&&(s[i]==')') || (top=='{')&&(s[i]=='}') || (top=='[')&&(s[i]==']')){
            st.pop();
        }
        }
    }
    if(st.empty()){
       cout<<"Valid parenthesis";
    }
    else{
        cout<<"Invalid parenthesis";
    }
   
}

//Q4:
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='/'||ch=='*') return 2;
    else if(ch=='+'|| ch=='-') return 1; 
    else return 0;
}
int main(){
    string s;
    cout<<"enter the expression";
    getline(cin,s);
int it=0;
stack<char> st;
string ans="";
//in this type of questions,we have 3 parts -operands,operators and brackets
     for(char ch : s){
        //for the operands to enter into answer part
        if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))||((ch>='0')&&(ch<='9'))){
            ans+=ch;
        }
        //for the elements inside the brackets to enter into stack
        else if(ch=='('){
            st.push(ch);
        }
        //for the elements inside the brackets to enter the ans now as soon as the closing bracket is met
        else if(ch==')'){
            while(!st.empty() && st.top()!='('){
            ans+=st.top();
            st.pop();
        }
            st.pop();//to pop out the opening bracket 
    }
      //for the operators to enter the stack and ans depending on the priority
        else{
            while(!st.empty() && priority(st.top())>=priority(ch)){
                ans+=st.top();
                st.pop();
            }
           st.push(ch);
        }
     }
     while(!st.empty()){
        ans+=st.top();
        st.pop();
     }
cout<<"The postfix expression is:"<<ans;
return 0;
}

//Q5:

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int it=0;
    stack<int> st;
    string ans="";
    string s;
    cout<<"enter the postfix exp";
    getline(cin,s);
    for(char ch : s){
       if(ch>='0' && ch<='9'){
        //to convert the char into int value
        st.push(ch-'0');
       }
       else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'|| ch=='^'){
        int ele1=st.top();
        st.pop();
        int ele2=st.top();
        st.pop();
        switch(ch){
            case '+':
            st.push(ele2+ele1);
            break;

            case '-':
            st.push(ele2-ele1);
            break;

            case '*':
             st.push(ele2*ele1);
            break;

            case '/':
             st.push(ele2/ele1);
            break;

            case '^':
             st.push(pow(ele2,ele1));
            break;

            default:
            cout<<"wrong input";
        }
       }
    }
    cout<<"expression becomes:"<<st.top();
    return 0;
}

