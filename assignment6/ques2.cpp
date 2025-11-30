#include<iostream>
using namespace std;
class node{
    public:
int data;
node* next;
public:
node(int val){
    data=val;
    next=NULL;
   
}
};
class linkedlist{
    public:
node* head;
linkedlist(){
    head=NULL;
}

void insertatend(int val){
node* newnode=new node(val);

if(head==NULL){
    head=newnode;
    newnode->next=head;
    return;
}
else{
    node *temp=head;
    while( temp->next!=head){
        temp=temp->next;

    }
    temp->next=newnode;
    newnode->next=head;
    
    
}
}

void printcll(){
    node* temp=head;
    while(temp->next!=head){
       
      cout<<temp->data<<"->";
       temp=temp->next;
    }
    cout<<temp->next->data;
    
}
};
int main(){
    linkedlist l;
    l.insertatend(20);
     l.insertatend(100);
      l.insertatend(40);
       l.insertatend(80);
        l.insertatend(60);
        l.printcll();
    return 0;
}