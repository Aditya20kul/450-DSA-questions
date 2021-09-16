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

// Print the Linked List
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

Node* addTwoNumbers(Node* A, Node* B) {
    Node *ans=NULL, *end=NULL;
    int carry = 0;
    int temp;
    while(A || B){
        temp=0;
        if(A!=NULL){
            temp += A->data;
        }
        if(B!=NULL){
            temp += B->data;
        }
        temp = temp + carry;
        //cout<<"\nTemp - "<<temp;
        carry = temp/10;
        //cout<<"\ntemp%10 - "<<temp%10;
        Node *newNode = new Node(temp%10);
        if(ans==NULL){
            ans = newNode;
            end = newNode;
        }
        else{
            end->next = newNode;
            end = end->next;
        }
        if(A){
            A = A->next;
        }
        if(B){
            B = B->next;
        }
    }
    if(carry!=0){
        end->next = new Node(carry); 
    }
    return ans;
}


int main(){
    int t,i,cnt=0,dt,n;
    Node* head = NULL, *head1=NULL;
    //cout<<"Enter Number of Nodes - ";
    //cin>>n;
    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 1);
    
    head1 = insertAtEnd(head1, 1);

    Node *ans = addTwoNumbers(head, head1);
    printList(ans);
    return 0;
}