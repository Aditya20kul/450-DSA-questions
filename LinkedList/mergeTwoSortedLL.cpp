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

Node* mergeSorted(Node *head1, Node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node *temp;
    if(head1->data < head2->data){
        temp = head1;
        temp->next = mergeSorted(head1->next, head2);
    }
    else{
        temp = head2;
        temp->next = mergeSorted(head1, head2->next);
    }
    return temp;
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
    cout<<"Enter Number of Nodes in LL1 - ";
    cin>>n;
    while(n--){
        cin>>dt;
        head1 = insertAtEnd(head1, dt);
    }
    cout<<"\nEnter Number of Nodes in LL2 - ";
    cin>>n;
    while(n--){
        cin>>dt;
        head2 = insertAtEnd(head2, dt);
    }
    //printList(head);
    Node *res = mergeSorted(head1, head2);
    printList(res);
    return 0;
}