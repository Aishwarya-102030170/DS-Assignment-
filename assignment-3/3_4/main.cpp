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
    cout<<"enter the expression: ";
    getline(cin,s);
    int it=0;
    stack<char> st;
    string ans=""; 
    //we have 3 parts -operands,operators and brackets
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
    cout<<"The postfix expression is: "<<ans;
    return 0;
}