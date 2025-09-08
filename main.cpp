#include <iostream>
#include <string>
#include <stack>
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
    cout<<"reversed string is: "<<rev;
}
int main(){
  string s;
  cout<<"enter a string: ";
  getline(cin,s);
  reverse(s);
}