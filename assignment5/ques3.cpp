#include<iostream>
using namespace std;
class node{
         public:
          int data;
          node* next;
         
          node(int val){
             data=val;
             next=NULL;
             
          }
};
class list{
    node *head;
    node*tail;
    public:
    list(){
        head=tail=NULL;
    }

    void push_back(int val){
      node *newnode=new node(val);
      if(head==NULL){
        head=tail=newnode;
      }
      else{
        tail->next=newnode;
        tail=newnode;
      }
    }
    void pop_back(){
        
        if(head==NULL){
            cout<<"list empty\n";
        }
        node* temp=head;
       while(temp->next!=tail){
        temp=temp->next;
       }
       delete temp->next;
       temp->next=NULL;

    }
       int findmiddle(){
        if(head==NULL){
            cout<<"list is empty"<<endl;
       return -1;
     }
        node* slow=head;
        node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
       }

    void printll(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";

    }

};
int main(){
    list l;
    l.push_back(1);
      l.push_back(2);
        l.push_back(3);
          l.push_back(4);
            l.push_back(5);
              l.push_back(6);
                l.push_back(7);
             cout<<l.findmiddle();
                
    return 0;
}
