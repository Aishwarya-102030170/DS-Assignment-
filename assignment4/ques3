#include<iostream>
using namespace std;
class queue{
    int front;
    int rear;
    int arr[100];
    int count=0;
    public:
       queue(){
        front =0;
        rear=-1;
        count=0;
       }
       void enqueue(int x){
        if(rear>=99){
            cout<<"queue overflow"<<endl;
            return;
        }
       
        arr[++rear]=x;
        count++;
       }
       int dequeue(){
        if(isempty()){
            cout<<"empty queue"<<endl;
            return -1;
        }
        int x=arr[front];
        front++;
        count--;
     
      if(count==0){
        front=0;
        rear=-1;
      }
      return x;
    }
    
    int size() const {
        return count;
    }
          bool isempty(){
        return (count == 0);
          }

          void interleave(){
            int n=size();
            if(n%2!=0){
                cout<<"queue cant be interleaved"<<endl;
           return;
         }
         int half=n/2;
        queue q1;
        queue q2;
         for(int i=0;i<half;i++){
            q1.enqueue(dequeue());
         }
         for(int i=0;i<half;i++){
              q2.enqueue(dequeue());
         }
         while(!q1.isempty() &&!q2.isempty()){
            enqueue(q1.dequeue());
            enqueue(q2.dequeue());
         }
          }
};
int main(){
    queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);


    q.interleave();

   


    while (!q.isempty()) {
        cout << q.dequeue() << " ";
    }
    cout<<endl;

    return 0;
}
