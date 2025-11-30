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

    void removekey(int key){
        int count =0;
        while(head!=NULL && head->data==key){
            node* todel=head;
            head=head->next;
            delete todel;
            count++;
        }
        if(head==NULL){
            tail==NULL;
        cout<<"no of occurences:"<<count<<endl;
    return;
        }
        node* prev=head;
        node*curr=head->next;
        while(curr!=NULL){
            if(curr->data==key){
                prev->next=curr->next;
                delete curr;
                count++;
                curr=prev->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        tail=prev;
        cout<<"no of occurenece:"<<count<<endl;
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
        l.push_back(1);
          l.push_back(2);
            l.push_back(1);
              l.push_back(3);
                l.push_back(1);
                l.removekey(1);
                l.printll();
    return 0;
}
