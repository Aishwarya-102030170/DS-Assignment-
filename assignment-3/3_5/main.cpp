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
    cout<<"enter the postfix exp: ";
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
    cout<<"expression becomes: "<<st.top();
    return 0;
}