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

Node* kReverse(Node* head, int k){
    if(head==NULL){
        return NULL;
    }

    // Reverse the K nodes
    Node *curr = head;
    Node *prev = NULL;
    Node *temp;
    int cnt=1;
    while(curr!=NULL && cnt<=k){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }
    if(temp!=NULL){
        head->next = kReverse(curr, k);
    }
    return prev;
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
    Node* head = NULL;
    cout<<"Enter Number of Nodes - ";
    cin>>n;
    while(n--){
        cin>>dt;
        head = insertAtEnd(head, dt);
    }
    printList(head);
    int k;
    cout<<"\nEnter the value of K - ";
    cin>>k;
    head = kReverse(head, k);
    printList(head);
    return 0;
}