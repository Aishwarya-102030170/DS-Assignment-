#include<iostream>
using namespace std;
class queue{
     int front,rear,size;
     int arr[100];
     public:
     queue(){
        front=0;
        rear=-1;
        size=0;
     }
     bool isempty(){
        return (size==0);
     }
     void enqueue(int x){
        if(rear>=90){
            cout<<"queue overflow!"<<endl;
            return ;
        }
        arr[++rear]=x;
        size++;
     }
     int dequeue(){
        if(isempty()){
            cout<<"queue underflow!"<<endl;
            return -1;
        }
        int val=arr[front];
        front++;
        size--;
        return val;
     }
     int getsize(){
        return size;
     }
     int peek(){
        if(isempty()){
            cout<<"queue empty!"<<endl;
            return -1;
        }
        return arr[front];
     }
};
 
class stack{
    queue q1,q2;
    public:
    void push(int x){
        q2.enqueue(x);

        while(!q1.isempty()){
            q2.enqueue(q1.dequeue());
        }

        queue temp=q1;
        q1=q2;
        q2=temp;
    }
       void pop() {
        if (q1.isempty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        q1.dequeue();
    }

    int top() {
        if (q1.isempty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return q1.peek();
    }

    bool empty() {
        return q1.isempty();
    }
};
int main(){
stack s;
s.push(10);
s.push(20);
s.push(30);
 cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl; 
s.pop();
    return 0;
}
