#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            this->data=val;
            this->next=NULL;
        }
}; 

int getMid(Node *head){
    //Complete this function to return data middle node
    Node *fast=head, *slow=head;
    while(fast && fast->next){
        if(fast->next->next!=NULL){
            slow = slow->next;
        }
        fast = fast->next->next;
    }
    return slow->data;   
}

Node* insertAtEnd(Node* head, int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    if(head==NULL){
        head=newNode;
    }
    else{
        while(temp->next){
            temp = temp->next;
        }
        temp->next=newNode;
    }
    return head;
}

void printList(Node *head){
    if(head==NULL){
        cout<<"\n!!! Linked List Empty !!!\n";
        return;
    }
    else{
        cout<<"\n *** Printing LinkedList - ";
        Node *temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}


int main(){
    int t,i,cnt=0,ans,dt,n;
    Node* head1 = NULL;
    Node* head2 = NULL;
    cout<<"Enter Number of Nodes in LL - ";
    cin>>n;
    while(n--){
        cin>>dt;
        head1 = insertAtEnd(head1, dt);
    }
    cout<<"Mid Value is - "<<getMid(head1);
    return 0;
}