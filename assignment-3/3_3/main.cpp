#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    cout<<"Enter an expression: ";
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